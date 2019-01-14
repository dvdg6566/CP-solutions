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

ll N,a,T;
ll A[1000010],DP[1000010];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> N >> a;
	for (int i = 0; i < N; ++i)cin >> A[i];
	for (int i = 0; i <= a; ++i){
		DP[i] = A[i];
	}
	for (int i = a+1; i < N; ++i){
		T = max(T,DP[i-a-1]);
		DP[i] = T + A[i];
	}
	cout << *max_element(DP,DP+N);
}
