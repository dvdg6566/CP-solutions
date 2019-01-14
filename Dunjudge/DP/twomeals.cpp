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

ll A[500100], ML[501000], MR[501000];
ll mL[501000], mR[501000];
int N;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> N;
	for (int i = 1; i <= N; ++i)cin >> A[i];
	for (int i = 1; i <= N; ++i){
		ML[i] = max(0LL,ML[i-1] + A[i]);
		mL[i] = max(ML[i],mL[i-1]);
	}
	for (int i = N; i > 0; --i){
		MR[i] = max(0LL,MR[i+1] + A[i]);
		mR[i] = max(MR[i],mR[i+1]);
	}
	ll ans = -INF;
	for (int i = 0; i <= N; ++i){
		ans = max(ans, mL[i] + mR[i+1]);
	}
	cout << ans;
}

