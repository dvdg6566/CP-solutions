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

int N,H,a,E,b,w;
vpi adjList[10010];
bool hotels[10010];
int bfsdist[120];
vi V,neighbours;
queue<int> Q;
priority_queue<pi, vector<pi>, greater<pi> > pq;
int dist[10010];

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
	        if(nd >= 600)continue;
	        if (dist[nx] != -1 && dist[nx] <= nd) continue;
	        dist[nx] = nd;
	        pq.push(mp(nd, nx));
	    }
	}
}

void bfs(int x){
	Q.push(x);
	memset(bfsdist,-1,sizeof(bfsdist));
	bfsdist[x] = 0;
	while(Q.size()){
		int c = Q.front();
		Q.pop();
		dijkstra(c);
		for (auto i : neighbours){
			bfsdist[i] = bfsdist[c] + 1;
			Q.push(i);
		}
	}
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("input.txt","r",stdin);
	while(cin>>N>>H){
		if(!N)return 0;
		for (int i = 1; i <= N; ++i)adjList[i].clear();
		memset(hotels,0,sizeof(hotels));
		V.clear();
		for (int i = 0; i < H; ++i){
			cin >> a;
			hotels[a] = 1;
			V.pb(a);
		}
		cin >> E;
		for (int i = 0; i < E; ++i){
			cin >> a >> b >> w;
			if(w>600)continue;
			cout << a << ' ' << b << '\n';
			adjList[a].pb(mp(b,w));
			adjList[b].pb(mp(a,w));
		}
		bfs(1);
	}
}

