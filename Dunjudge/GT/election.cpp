#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef pair<ll,ll> pii;
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
#define SZ(x) (ll)x.size()
#define ALL(x) x.begin(),x.end()

vi aList[100100],paths[100100];
int depth[100100], p[100100][17];
ll full[100100], empt[100100], fold[100100], fw[100100];
int heavy[100100], head[100100], pos[100100];
int cnt,N;

void update(int x, ll v){
	for (;x<=N;x+=x&(-x))fw[x] += v;
}

ll sum(int x){
	ll res = 0;
	for (;x;x-=x&(-x))res+=fw[x];
	return res;
}

ll rsq(int a, int b){
	assert(a<=b);
	return sum(b) - sum(a-1);
}

ll query_sum(int x,int t){
	ll res = 0;
	while(head[x] != head[t]){
		res += rsq(pos[head[x]], pos[x]);
		x = p[head[x]][0];
	}
	res += rsq(pos[t], pos[x]);
	return res;
}

int dfs2(int x){
	int cs = 1;
	int msize = 0;
	for (auto i : aList[x]){
		if (p[i][0] != x)continue;
		int t = dfs2(i);
		cs += t;
		if (t > msize){
			msize = t;
			heavy[x] = i;
		}
	}
	return cs;
}

void decompose(int x, int h){
	pos[x] = cnt++; head[x] = h;
	if (heavy[x] != -1)decompose(heavy[x], h);
	for (auto v : aList[x]){
		if (p[v][0] != x || v == heavy[x])continue;
		decompose(v,v);
	}
}

int lca(int a, int b){
	if (depth[a] < depth[b])swap(a,b);
	if (a == b)return a;
	int h = depth[a] - depth[b];
	assert(h >= 0);
	for (int i=0;i<17;++i){
		if ((1<<i) & h){
			a = p[a][i];
		}
	}
	if (a == b)return a;
	assert(depth[a] == depth[b]);
	for(int i=16;i>=0;--i){
		if (p[a][i] != p[b][i]){
			a = p[a][i];
			b = p[b][i];
		}
	}
	assert(p[b][0] == p[a][0]);
	return p[a][0];
}

int find_p(int x, int h){
	for (int i=0;i<17;++i){
		if ((1<<i) & h)x = p[x][i];
	}
	return x;
}

struct route{
	ll a,b,w,p;
	route(ll _a, ll _b, ll _w): a(_a), b(_b), w(_w) {
		p = lca(a,b);
	}
};

void dfs(int v, int u){
	for (auto i : aList[v]){
		if (i == u)continue;
		depth[i] = depth[v]+1;
		p[i][0] = v;
		dfs(i, v);
	}
}

ll R,a,b,w;
vector<route> V;

void dp(int x, int u){
	for (auto i : aList[x]){
		if (i == u)continue;
		dp(i, x);
		empt[x] += full[i];
	}
	ll ans = 0;
	for (auto i : paths[x]){
		route cur = V[i];
		ll rep = empt[x];
		int child = cur.a;
		// cout<<"When path is from " << cur.a << " to " << cur.b << " through " << cur.p<<' ' << " weighted " << cur.w<<'\n';
		if (child != x){
			int d = depth[child] - depth[x];
			int agent = find_p(child, d-1);
			// cout<<"Agent " << agent<<'\n';
			rep -= query_sum(child, agent);
		}
		child = cur.b;
		if (child != x){
			int d = depth[child] - depth[x];
			int agent = find_p(child, d-1);
			// cout<<"Agent " << agent<<'\n';
			rep -= query_sum(child, agent);
		}
		rep += cur.w;
		ans = max(ans, rep);
	}
	full[x] = max(ans, empt[x]);
	fold[x] = full[x] - empt[x];
	update(pos[x], fold[x]);
}

int main(){
	memset(heavy, -1, sizeof(heavy));
	// freopen("in.txt","r",stdin);
	cin >> N;
	for (int i=1;i<N;++i){
		cin >> a >> b;
		aList[a].pb(b);
		aList[b].pb(a);
	}
	memset(p, -1, sizeof(p));
	dfs(1,0);
	for (int j=1;j<17;++j){
		for (int i=2;i<=N;++i){
			if (p[i][j-1] == -1)continue;
			p[i][j] = p[p[i][j-1]][j-1];
		}
	}
	cnt = 1;
	dfs2(1);
	decompose(1,1);
	// for (int i=1;i<=N;++i)cout<<pos[i]<<' '<<head[i]<<'\n';cout<<'\n';
	// for (int i=1;i<=N;++i)cout<<depth[i]<<' ';cout<<'\n';
	cin >> R;
	for (int i=0;i<R;++i){
		cin >> a >> b >> w;
		V.pb({a,b,w});
	}
	for (int i=0;i<SZ(V);++i){
		paths[V[i].p].pb(i);
	}
	dp(1,0);
	// for (int i=1;i<=N;++i)cout<<full[i]<<' '<<empt[i]<<' '<<'\n';
	cout<<*max_element(full+1, full+N+1);
}