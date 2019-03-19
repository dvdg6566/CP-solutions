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
ll INF = 1e18;
ll MOD = 1e9;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (ll)x.size()
#define ALL(x) x.begin(),x.end()

vi l, r;
vpi V;
ll N,a,b,C,ans;

int main(){
  //freopen("input.txt","r",stdin);
  cin>>N>>C;
  for (int i=0;i<N;++i){
		cin>>a>>b;
		V.pb(mp(a,b));
	}
	sort(ALL(V));
	pi cur = mp(0,0);
	l.pb(0);
	for (int i=N-1; i >= 0; --i){
		cur.f = (C - V[i].f)*2;
		cur.s += V[i].s;
		if (cur.s - cur.f > l.back())l.pb(cur.s - cur.f);
		else l.pb(l.back());
	}
	//for (auto i : l)cout<<i<<' ';
	r.pb(0);
	cur = mp(0,0);
	for (int i=0;i<N;++i){
		cur.f = V[i].f;
		cur.s += V[i].s;
		if (cur.s - cur.f > r.back())r.pb(cur.s - cur.f);
		else r.pb(r.back());
	}
	reverse(ALL(r));
	for (int i=0;i<=N;++i){
		//cout<<l[i]<<' '<<r[i]<<'\n';
		ans = max(ans, l[i] + r[i]);
	}
	l.clear(); r.clear();
	cur = mp(0,0);
	l.pb(0);
	for (int i=N-1; i >= 0; --i){
		cur.f = (C - V[i].f);
		cur.s += V[i].s;
		if (cur.s - cur.f > l.back())l.pb(cur.s - cur.f);
		else l.pb(l.back());
	}
	//for (auto i : l)cout<<i<<' ';
	r.pb(0);
	cur = mp(0,0);
	for (int i=0;i<N;++i){
		cur.f = V[i].f*2;
		cur.s += V[i].s;
		if (cur.s - cur.f > r.back())r.pb(cur.s - cur.f);
		else r.pb(r.back());
	}
	reverse(ALL(r));
	for (int i=0;i<=N;++i){
		//cout<<l[i]<<' '<<r[i]<<'\n';
		ans = max(ans, l[i] + r[i]);
	}
	cout<<ans;
}
