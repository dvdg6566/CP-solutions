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

ll N,a,b,w,ans,T;
vpi adjList[501000];
ll pop[501000];
ll par[501000];
pi res[501000];
ll pd[501000];
ll out[501000];

void rootdfs(ll x){
	for (auto i : adjList[x]){
		if (par[i.f] != -1)continue;
		par[i.f] = x;
		//cout << x << ' ' << i.f << ' ' << i.s << '\n';
		pd[i.f] = i.s;
		rootdfs(i.f);
	}
}

void update(ll i){
	if (i == 0){
		out[i] = res[i].f;
		return;
	}
	if (out[par[i]] == -1)update(par[i]);
	ll x = res[i].f;
	ll p = out[par[i]] - res[i].f; // People who come from the parent minus those coming from yourself
	p += pd[i] * (T - 2*res[i].s); // Distance for people to walk over from parent
	out[i] = p+x;
}

pi query(ll x){
	if (x != 0 && adjList[x].size() == 1){
		// Leaf Node
		res[x] = mp(0,pop[x]);
		return mp(0,pop[x]);
	}
	ll ans = 0, p = 0;
	for (auto i : adjList[x]){
		if (i.f == par[x])continue;
		pi c = query(i.f);
		ans += c.f; // Distance already travelling
		ans += (c.s)*(i.s); // Additionally distance of current travellers
		p += c.s;
	}
	p += pop[x];
	res[x] =  mp(ans,p);
	return mp(ans,p);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> N;
	for (ll i = 0; i < N; ++i){
		cin >> a;
		pop[i] = a;
		T += a;
		res[i] = mp(-1,-1);
	}
	for (ll i = 1; i < N; ++i){
		cin >> a >> b >> w;
		adjList[a].pb(mp(b,w));
		adjList[b].pb(mp(a,w));
	}
	memset(par,-1,sizeof(par));
	memset(out,-1,sizeof(out));
	par[0] = 0;
	rootdfs(0);
	query(0);
	cout << res[0].f << ' ';
	for (ll i = 1; i < N; ++i){
		if (out[i] != -1)continue;
		update(i);
	}
	for (ll i = 1; i < N; ++i){
		cout << out[i] << ' ';
	}
}
