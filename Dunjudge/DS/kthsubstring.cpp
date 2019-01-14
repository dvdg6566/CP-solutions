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
#define MOD (ll)1000000007
#define lb lower_bound
#define ub upper_bound
#define dst distance
#define INF 1000000000

string S,a;
int K,n;
map<string,bool> M;

int RA[5010], tempRA[5010]; // rank array and temporary rank array
int SA[5010], tempSA[5010]; // suffix array and temporary suffix array
int c[5010]; // for counting/radix sort
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
		tempRA[SA[i]] =  (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r; // if same pair => same rank r; otherwise, increase r
		for (i = 0; i < n; i++) RA[i] = tempRA[i]; // update the rank array RA
		if (RA[SA[n-1]] == n-1) break;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> S >> K;
	n = S.size();
	constructSA();
	for (int i = 0; i < n; ++i){
		a = "";
		for (int j = SA[i]; j < n; ++j){
			a += S[j];
			if(M[a])continue;
			--K;
			M[a] = 1;
			if (K == 0){cout << a; return 0;}
		}
	}
}
