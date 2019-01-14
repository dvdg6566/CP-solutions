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

deque<pi> dq;
ll sum,wgt,ans,N,M,a;
vi wgts, decs;

void insert(ll a, ll b){
	// a is deliciousness
	if (a >= 0){
		dq.pb(mp(a,b));
		sum += a;
		wgt += b;
		while (wgt > M){
			sum -= dq[0].f;
			wgt -= dq[0].s;
			dq.pop_front();
		}
		ans = max(ans,sum);
	}else{
		if (sum+a<0){
			dq.clear();
			sum = 0;
			wgt = 0;
		}else{
			dq.pb(mp(a,b));
			wgt += b;
			sum += a;
			while(dq[dq.size()-1].f<0){
				pi x = dq.back();
				dq.pop_back();
				dq.back().f += x.f;
				dq.back().s += x.s;
			}
			while (wgt > M){
				sum -= dq[0].f;
				wgt -= dq[0].s;
				dq.pop_front();
			}
			ans = max(sum,ans);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> N >> M;
	for (ll i = 0; i < N; ++i){cin >> a;decs.pb(a);}
	for (ll i = 0; i < N; ++i){cin >> a;wgts.pb(a);}
	for (ll i = 0; i < N; ++i){
		insert(decs[i],wgts[i]);
	}
	cout << ans;
}
