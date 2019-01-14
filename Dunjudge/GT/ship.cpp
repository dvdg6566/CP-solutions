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
#define INF 1000000000

int H,W,xH,xW;
int dx[] = {1,-1,0,0},dy[] = {0,0,1,-1};
int dp[1010][1010];
priority_queue<pi, vector<pi>, greater<pi> > pq;
int dist[1010000],vals[1010000];
bool visited[1010000];

void dijkstra(int x){
    while(pq.size())pq.pop();
	memset(dist, -1, sizeof(dist));
	dist[x] = vals[x];
	pq.push(mp(vals[x], x));
	while (!pq.empty()) {
	    pi cur = pq.top();
	    pq.pop();
	    int x = cur.s, d = cur.f;
	    if (d > dist[x]) continue;
	    visited[x] = 1;
	    int cx = x/W, cy = x%W;
	    if (cy==0){cx--;cy=W;}
	    for (int k = 0; k < 4; ++k){
			int px = cx+dx[k], py = cy+dy[k];
			if (px<=0||py<=0||px>H-xH+1||py>W-xW+1)continue;
			int nx = px*W+py;
			if (visited[nx])continue;
			int nd = max(d,vals[nx]);
	        if (dist[nx] != -1 && dist[nx] <= nd) continue;
	        dist[nx] = nd;
	        pq.push(mp(nd, nx));
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> W >> H >> xW >> xH;
	for (int i = 1; i <= H; ++i){
		for (int j = 1; j <= W; ++j){
			cin >> dp[i][j];
			dp[i][j] = dp[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1]; 
		}
	}
	int M = 0;
	for (int i = 1; i <= H; ++i){
		for (int j = 1; j <= W; ++j){
            if(xH+i-1>H)continue;
            if (xW+j-1>W)continue;
			int cx = xH+i-1;
			int cy = xW+j-1;
            M = max(M,i*W+j);
            vals[i*W+j] = dp[cx][cy] - dp[cx][j-1] - dp[i-1][cy] + dp[i-1][j-1];
		}
	}
	dijkstra(1+W);
	cout << dist[M];
}
