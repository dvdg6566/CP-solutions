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
#define MOD 1e9+7
#define lb lower_bound
#define ub upper_bound
#define dst distance
#define INF 1000000000

ll N,M;
ll A[100100], R[100100];
ll fw[220100], ans;

void update(int x) {
	x += 110000;
    for (; x<= 220010; x+=x&(-x)) fw[x] ++; 
}

int sum(int x) {
	x += 110000;
    int res = 0;
    for(; x; x-=x&(-x)) res += fw[x];
    return res;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> N >> M;
	for (int i = 1; i <= N; ++i){
		cin >> A[i];
		A[i] = (A[i] >= M);
		R[i] = A[i] + R[i-1];
	}
	// Find number of subsequences of A that have a range sum more than half its length
	// A[sum i...j] >= (j-i)/2;
	// 2*A[sum i...j] >= (j-i)
	// multiply each element of A by 2
	// rsq[i] - rsq[j-1] >= (i-j)
	// Replace j with j+1
	// rsq[i] - rsq[j] >= i-j+1
	// (rsq[i] - i) - (rsq[j] - j) >= 1
	for (int i = 0; i <= N; ++i)R[i] *= 2;
	/*
	for (int i = 0; i <= N; ++i)cout << A[i] * 2 << ' ';cout << '\n';
	for (int i = 0; i <= N; ++i)cout << R[i] << ' ';cout << '\n';
	for (int i = 0; i <= N; ++i)cout << R[i]-i << ' ';cout << '\n';
	* */
	for (int i = 0; i <= N; ++i){
		int q = R[i] - i;
		ans += sum(q);
		//cout << "querying " << q << '\n';
		update(q);
		//cout << "updating " << q << '\n';
	}
	cout << ans;
}
