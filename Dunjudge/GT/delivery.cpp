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

// DP bitmask TSP has N*2^N state and N transition. Works up to 16. 

int N,E,C,T,R,a,b,w;
vpi V;
vpi adjList[100100];
int D[15][15];
int DP[15][(1<<15)];

priority_queue<pi, vector<pi>, greater<pi> > pq;
int dist[100100];
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
	for (int i = 0; i < C; ++i){
		D[R][i] = dist[V[i].f];
	}
}

int tsp(int pos, int bm){
	if(bm == T)return D[pos][0]; // Return to start location if ur done
	if (DP[pos][bm] != -1) return DP[pos][bm];
	int ans = INF;
	for (int i = 0; i < C; ++i){
		if(bm & (1 << i))continue;
		ans = min(ans,D[pos][i] + tsp(i, bm | (1<<i)));
	}
	return DP[pos][bm] = ans;
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> C >> N >> E;
	V.pb(mp(0,0));
	for (int i = 0; i < C; ++i){
		cin >> a >> b;
		V.pb(mp(a,b));
	}
	++C;
	for (int i = 0; i < E; ++i){
		cin >> a >> b >> w;
		adjList[a].pb(mp(b,w));
		adjList[b].pb(mp(a,w));
	}
	for (int i = 0; i < C; ++i){
		R = i;
		dijkstra(V[i].f);
	}
	memset(DP,-1,sizeof(DP));
	T = (1 << C) - 1;
	tsp(0,1);
	int ans = 0;
	for (int bm = 0; bm <= T; ++bm){
		int cur = 0;
		for (int i = 0; i < C; ++i){
			if (bm & (1<<i))continue;
			cur += V[i].s;
		}
		ans = max(ans,cur-tsp(0,bm));
	}
	cout << ans;
	/*
	for (int i = 0; i < C; ++i){
		for (int j = 0; j < C; ++j){
			cout << D[i][j] << ' ';
		}
		cout << '\n';
	}*/
}
