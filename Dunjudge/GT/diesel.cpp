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
#define INF 1000000000
#define START 33000

int G[1010][1010];
int M, N;
priority_queue<pi> pq;
int dist[1010110];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

void run(int cx, int cy, int d){
	for (int k = 0; k < 4; ++k){
		int nx = cx + dx[k], ny = cy + dy[k], nd;
		if (nx<0||ny<0||nx>=M||ny>=N)continue;
		if (G[cx][cy] >= G[nx][ny])nd = d - 10;
		else nd = d - d/1000 * (G[nx][ny] - G[cx][cy]) * 4 - 10;
		if (nd < 8000)continue;
		if (dist[nx*N+ny] >= nd)continue;
		dist[nx*N+ny] = nd;
		pq.push(mp(nd,nx*N+ny));
	}
}

void dijkstra(int start){
	memset(dist, -1, sizeof(dist));
	dist[start] = 33000;
	pq.push(mp(33000, start));
	while (!pq.empty()) {
	    pi cur = pq.top();
	    pq.pop();
	    int x = cur.s, d = cur.f;
	    if (d+1000 < dist[x]) continue;
	    int cx = x/N, cy = x%N;
	    run(cx,cy,d);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("input.txt","r",stdin);
	cin >> M >> N;
	for (int i = 0; i < M; ++i){
		for (int j = 0; j < N; ++j){
			cin >> G[i][j];
			G[i][j] /= 100;
		}
	}
	dijkstra(0);
	for (int i = 0; i < M; ++i){
		for (int j = 0; j < N; ++j){
			cout << dist[i*N+j] << ' ';
		}
		cout << '\n';
	}
	if (dist[M*N-1] == -1 || dist[M*N-1] == 0) cout << dist[M*N-1];
	else cout << dist[M*N-1] - 8000;
}
