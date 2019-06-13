#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef pair<ll,pi> pii;
typedef vector<pi> vpi;
typedef set<ll> si;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define f first
#define s second
ll INF = 1e9;
ll MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
#define MAXN 100100

vector<pii> V;
ll ans, N,a,b,c,H,W;
set<ll> cur;

void res(ll x){
	if (x >= 0)cur.insert(x);
	else cur.erase(-x);
}
int main(){
	// freopen("in.txt","r",stdin);
	cin>>H>>W>>N;
	for (ll i=1;i<=N;++i){
		cin>>a>>b>>c;
		V.pb(mp(c,mp(a,b)));
	}
	for (ll i=1;i<=H;++i){
		vpi wind;
		for (int it=0;it<SZ(V);++it){
			pii x = V[it];
			ll used = (x.s.f-i)*(x.s.f-i);
			ll left = x.f * x.f-used;
			if (left<0)continue;
			ll bef = max(1LL, x.s.s-(ll)sqrt(left));
			ll aft = min(W, x.s.s+(ll)sqrt(left));
			wind.pb(mp(bef, it+1));
			wind.pb(mp(aft+1, -it-1));
		}
		// cout<<"Resolving row "<<i<<'\n';

		wind.pb(mp(1,0));
		ll t=SZ(wind);
		sort(ALL(wind));
		wind.pb(mp(W+1,0));

		for (int i=0;i<t;++i){
			ll tmp=wind[i].f;
			res(wind[i].s);
			while (i+1<t && wind[i+1].f==tmp){
				++i;
				res(wind[i].s);
			}
			ll winlen=wind[i+1].f-wind[i].f;
			ans += (winlen)*(N-*(--cur.end()));
		}
	}
	cout<<ans;
}