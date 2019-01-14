#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MOD 1e9+7
#define lb lower_bound
#define ub upper_bound
#define dst distance
#define INF 1000000000

int T,s,d,N,E,p,a,b,c;
vpi adjList[11000],rev[11000];
int dist[11000], revdist[11000];

struct edge {
    int a, b, w;
    edge (int _a=0, int _b=0, int _w=0): a(_a), b(_b), w(_w) {}
};
vector<edge> edgeList;

priority_queue<pi,vector<pi>,greater<pi>> pq;

void dijkstra(int start){
	memset(dist, -1, sizeof(dist));
	dist[start] = 0;
	pq.push(mp(0, start));
	while (!pq.empty()) {
	    pi cur = pq.top();
	    pq.pop();
	    int x = cur.s, d = cur.f;
	    if (d > dist[x]) continue;
	    for (auto it:adjList[x]) {
	        int nx = it.f, nd = d+it.s;
	        if (dist[nx] != -1 && dist[nx] <= nd) continue;
	        dist[nx] = nd;
	        pq.push(mp(nd, nx));
	    }
	}
}

void invdijkstra(int endpt){
	memset(revdist, -1, sizeof(revdist));
	revdist[endpt] = 0;
	pq.push(mp(0, endpt));
	while (!pq.empty()) {
	    pi cur = pq.top();
	    pq.pop();
	    int x = cur.s, d = cur.f;
	    if (d > revdist[x]) continue;
	    for (auto it:rev[x]) {
	        int nx = it.f, nd = d+it.s;
	        if (revdist[nx] != -1 && revdist[nx] <= nd) continue;
	        revdist[nx] = nd;
	        pq.push(mp(nd, nx));
	    }
	}
}

int main(){
	//freopen("input.txt","r",stdin);
	cin >> T;
	while (T--){
		cin >> N >> E >> s >> d >> p;
		edgeList.clear();
		for (int i = 1; i <= N; ++i){adjList[i].clear();rev[i].clear();}
		while(E--){
			cin >> a >> b >> c;
			adjList[a].pb(mp(b,c));
			rev[b].pb(mp(a,c));
			edgeList.pb({a,b,c});
		}
		dijkstra(s);
		invdijkstra(d);
		
		int ans = -1;
		for (auto i : edgeList){ 
			if(dist[i.a]==-1 || revdist[i.b] == -1)continue;
			int cur = dist[i.a] + revdist[i.b] + i.w;
			if(cur>p)continue;
			ans = max(i.w,ans);
		}
		cout << ans << '\n';
	}
}
