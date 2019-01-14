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

vpi adjList[100100];
int pre[100100], post[100100], dist[100100];
int fw[100100],c=1,res[300100], par[100100];
int N,Q,a,b,s,e,w;

struct edge {
    int a, b, time, type;
    edge (int _a=0, int _b=0, int _t=0, int _y= 0): a(_a), b(_b), time(_t), type(_y) {}
};

vector<edge> EdgeList;
bool cmp(edge a, edge b){
	if(a.time != b.time)return a.time < b.time;
	return a.type < b.type;
}

void update(int x, int y, int v) { // inclusive
	x--;
	for(; y; y-=y&(-y)) fw[y] += v;
	for(; x; x-=x&(-x)) fw[x] -= v;
}

int query(int x) {
    int res = 0;
    for (; x<=N; x+=x&(-x)) res += fw[x];
    return res;
}

void dfs(int x){
	pre[x] = c;
	++c;
	for (auto i : adjList[x]){
		if(dist[i.f] != -1)continue;
		dist[i.f] = dist[x] + i.s;
		par[i.f] = x;
		dfs(i.f);
	}
	post[x] = c-1;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> N >> Q;
	for (int i = 1; i < N; ++i){
		cin >> a >> b >> w >> s >> e;
		EdgeList.pb({a,b,s,0});
		EdgeList.pb({a,b,e,2});
		adjList[a].pb(mp(b,w));
		adjList[b].pb(mp(a,w));
	}
	memset(dist,-1,sizeof(dist));
	dist[0] = 0;
	dfs(0);
	for (int i = 0; i < EdgeList.size(); ++i){
		if(par[EdgeList[i].a] == EdgeList[i].b){
			swap(EdgeList[i].a,EdgeList[i].b); // Make sure start and end alligned properly
		}
		update(pre[EdgeList[i].b],post[EdgeList[i].b],1);
		EdgeList[i].time = EdgeList[i].time - dist[EdgeList[i].a]; // Remove the time it takes to get to the start of the road
	}
	for (int i = 0; i < Q; ++i){
		cin >> a >> b;
		EdgeList.pb({a,i,b,1});
	}
	sort(EdgeList.begin(),EdgeList.end(), cmp);
	for (auto i : EdgeList){
		if (i.type == 0){
			// Open edge
			update(pre[i.b], post[i.b], -2);
		}
		if (i.type == 1){
			//  Query
			res[i.b] = (query(pre[i.a]) == 0);
		}
		if (i.type == 2){
			// Close Road
			update(pre[i.b],post[i.b],2);
		}
	}
	for (int i = 0; i < Q; ++i){
		if(res[i])cout << "YES\n";
		else cout << "NO\n";
	}
}
