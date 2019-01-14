#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef double dl;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MOD 1000000007LL
#define lb lower_bound
#define ub upper_bound
#define dst distance
#define INF 1000000000
string S, S2;
int n,LEN;
int RA[8010], tempRA[8010]; // rank array and temporary rank array
int SA[8010], tempSA[8010]; // suffix array and temporary suffix array
int c[8010]; // for counting/radix sort
int LCP[8010], Phi[8010], PLCP[8010]; // for longest common prefix
set<string> ST;

void countingSort(int k) { // O(n)
	int i, sum, maxi = max(300, n); // up to 255 ASCII chars or length of n
	memset(c, 0, sizeof c); // clear frequency table
	for (i = 0; i < n; i++){
		c[i + k < n ? RA[i + k] : 0]++; // count the frequency of each integer rank
	}
	for (i = sum = 0; i < maxi; i++) {
		int t = c[i]; 
		c[i] = sum; 
		sum += t;
	}
	for (i = 0; i < n; i++) tempSA[c[SA[i]+k < n ? RA[SA[i]+k] : 0]++] = SA[i]; // shuffle the suffix array if necessary
	for (i = 0; i < n; i++) SA[i] = tempSA[i];// update the suffix array SA
}

void constructSA() {
	int i, k, r;
	for (i = 0; i < n; i++) RA[i] = S[i]; // initial rankings
	for (i = 0; i < n; i++) SA[i] = i; // initial SA: {0, 1, 2, ..., n-1}
	for (k = 1; k < n; k <<= 1) { // repeat sorting process log n times
		countingSort(k); // actually radix sort: sort based on the second item
		countingSort(0); // then (stable) sort based on the first item
		tempRA[SA[0]] = r = 0; // re-ranking; start from rank r = 0
		for (i = 1; i < n; i++) // compare adjacent suffixes
		tempRA[SA[i]] =  (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r; 
		// if same pair => same rank r; otherwise, increase r
		for (i = 0; i < n; i++) RA[i] = tempRA[i]; // update the rank array RA
		if (RA[SA[n-1]] == n-1) break; // nice optimization trick
	}
}

void computeLCP() {
	int i, L;
	Phi[SA[0]] = -1; // default value
	 // compute Phi in O(n)
	for (i = 1; i < n; i++) Phi[SA[i]] = SA[i-1]; // remember which suffix is behind this suffix
	for (i = L = 0; i < n; i++) { // compute Permuted LCP in O(n)
	if (Phi[i] == -1) { PLCP[i] = 0; continue; } // special case
	while (S[i + L] == S[Phi[i] + L]) L++; // L increased max n times
		PLCP[i] = L;
		L = max(L-1, 0); // L decreased max n times
	}
	// compute LCP in O(n)
	for (i = 0; i < n; i++) LCP[i] = PLCP[SA[i]]; // put the permuted LCP to the correct position
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("input.txt","r",stdin);
	while(cin >> S){
		if(S2 != "")cout << '\n';
		if(cin.eof())return 0;
		cin >> S2;
		S += '$';
		S += S2;
		S += '#';
		LEN = S2.size() + 1;
		n = S.size();
		constructSA();
		computeLCP();
		int res = -INF;
		for (int i = 0; i < n; ++i){
			if(n-SA[i] > LEN && n-SA[i-1] > LEN)continue;
			if(n-SA[i] <= LEN && n-SA[i-1] <= LEN)continue;
			res = max(res,LCP[i]);
		}
		if(res == 0){cout << "No common sequence.\n"; continue;}
		for (int i = 0; i < n; ++i){
			if(n-SA[i] > LEN && n-SA[i-1] > LEN)continue;
			if(n-SA[i] <= LEN && n-SA[i-1] <= LEN)continue;
			if(LCP[i] != res)continue;
			S2 = "";
			for (int j = 0; j < res; ++j)S2 += S[j+SA[i]];
			ST.insert(S2);
		}
		for (auto i : ST)cout << i << '\n';
		ST.clear();
	}
}


