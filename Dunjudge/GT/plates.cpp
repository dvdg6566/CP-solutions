#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
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
#define MUL 10000

int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};
vpi edges;
bool grid[1010][1010];
priority_queue<pi, vector<pi>, greater<pi> > pq;
int dist[4001000];
string st;
int H,W;

int cnv(int a, int b, int d){
	return H*W*d+a*W+b;
}

void dijkstra(int start){
	memset(dist, -1, sizeof(dist));
	dist[start] = 0;
	pq.push(mp(0, start));
	while (!pq.empty()) {
		edges.clear();
	    pi cur = pq.top();
	    pq.pop();
	    int x = cur.s, d = cur.f;
	    if (d > dist[x]) continue;
	    int i = (x%(H*W))/W, j = (x%(H*W))%W, k = x/(H*W);
	    int cx = i+dx[k], cy = j+dy[k];
	    if (cx>=0&&cy>=0&&cx<H&&cy<W){
			edges.pb(mp(cnv(cx,cy,k),1));
		}
		if (grid[i][j]){
			for (int it = 0; it < 4; ++it){
				if(it==k)continue;
				edges.pb(mp(cnv(i,j,it),MUL+1));
			}
		}
	    for (auto it:edges) {
	        int nx = it.f, nd = d+it.s;
	        if (dist[nx] != -1 && dist[nx] <= nd) continue;
	        dist[nx] = nd;
	        pq.push(mp(nd, nx));
	    }
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> H >> W;
	for (int i = 0; i < H; ++i){
		cin >> st;
		for (int j = 0; j < W; ++j){
		    grid[i][j] = (st[j] == '#');
		}
	}
	dijkstra(cnv(0,0,2));
	if(dist[cnv(H-1,W-1,2)] < 0)cout << -1;
	else cout << dist[cnv(H-1,W-1,2)]/MUL;
}

