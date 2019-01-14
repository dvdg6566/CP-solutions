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

int N,start,finish;
bool G[200][200];
string S;
vpi adjList[150000];
priority_queue<pi, vector<pi>, greater<pi> > pq;
int dist[150000];

int dijkstra(int start){
	while(pq.size())pq.pop();
	memset(dist, -1, sizeof(dist));
	dist[start] = 0;
	pq.push(mp(0, start));
	while (!pq.empty()) {
	    pi cur = pq.top();
	    pq.pop();
	    int x = cur.s, d = cur.f;
	    if(x%(N*N) == finish)return d;
	    if (d > dist[x]) continue;
	    for (auto it:adjList[x]) {
	        int nx = it.f, nd = d+it.s;
	        if (dist[nx] != -1 && dist[nx] <= nd) continue;
	        dist[nx] = nd;
	        pq.push(mp(nd, nx));
	    }
	}
	return -INF;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> N;
	for (int i = 0; i < N; ++i){
		cin >> S;
		for (int j = 0; j < N; ++j){
			if(S[j] == 'X')G[i][j] = 1;
			if(S[j] == 'S'){
				start = i*N+j;
			}
			if(S[j] == 'F'){
				finish = i*N+j;
			}
		}
	}
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N; ++j){
			if(G[i][j])continue;
			int cur = (i*N+j);
			//Angle 0 (Northeast)
			int cx = i - 1, cy = j + 1;
			if(cx>=0&&cy<N){
				int dest = cx*N+cy;
				adjList[cur].pb(mp(dest,10));
				adjList[cur].pb(mp(dest+N*N,10));
				adjList[cur].pb(mp(dest+N*N*3,22));
			}
			//Angle 1 (East)
			cur += N*N;
			cx = i, cy = j+1;
			if(cy<N){
				int dest = cx*N+cy;
				adjList[cur].pb(mp(dest,9));
				adjList[cur].pb(mp(dest+N*N*2,9));
				adjList[cur].pb(mp(dest+N*N,9));
			}
			//Angle 2 (Southeast)
			cur += N*N;
			cx = i+1, cy = j+1;
			if(cx<N&&cy<N){
				int dest = cx*N+cy;
				adjList[cur].pb(mp(dest+N*N,15));
				adjList[cur].pb(mp(dest+N*N*2,15));
			}
			//Angle 3 (Northwest)
			cur += N*N;
			cx = i-1, cy = j-1;
			if(cx>=0&&cy>=0){
				int dest = cx*N+cy;
				adjList[cur].pb(mp(dest,22));
				adjList[cur].pb(mp(dest+3*N*N,10));
				adjList[cur].pb(mp(dest+4*N*N,10));
			}
			//Angle 4 (West)
			cur += N*N;
			cx = i, cy = j-1;
			if(cy>=0){
				int dest = cx*N+cy;
				adjList[cur].pb(mp(dest+N*N*3,9));
				adjList[cur].pb(mp(dest+N*N*4,9));
				adjList[cur].pb(mp(dest+N*N*5,9));
			}
			//Angle 5 (Southwest)
			cur += N*N;
			cx = i+1, cy = j-1;
			if(cx<N&&cy>=0){
				int dest = cx*N+cy;
				adjList[cur].pb(mp(dest+N*N*4,15));
				adjList[cur].pb(mp(dest+N*N*5,15));
			}
		}
	}
	int res = INF;
	for (int i = 0; i < 6; ++i){
		int x = dijkstra(i*N*N+start);
		if(x==-INF)continue;
		//cout << x << '\n';
		res = min(res,x);
	}
	cout << res;
}
