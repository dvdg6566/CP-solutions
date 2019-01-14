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

int N,E,C,T,R,a,b,w;
int D[15][15];
int DP[15][(1<<15)];
int G[21][21], bfs[21][21];
struct node {
    int a, b, w;
    node (int _a=0, int _b=0, int _w=0): a(_a), b(_b), w(_w) {}
};

bool cmp (node x, node y) { return x.w < y.w; }

vector<node> V;
string S;
queue<pi> Q;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int tsp(int pos, int bm){
	if(bm == T)return D[pos][0]; // Return to start location if ur done
	if (DP[pos][bm] != INF) return DP[pos][bm];
	int ans = -INF;
	for (int i = 0; i < V.size(); ++i){
		if(bm & (1 << i))continue;
		ans = max(ans,D[pos][i] + tsp(i, bm | (1<<i)));
	}
	return DP[pos][bm] = ans;
}


void fill (int x, int y){
	for (int i = 0; i < R; ++i){
		for (int j = 0; j < C; ++j)bfs[i][j] = -INF;
	}
	bfs[x][y] = 0;
	Q.push(mp(x,y));
	while(Q.size()){
		int cx = Q.front().f;
		int cy = Q.front().s;
		Q.pop();
		for (int i = 0; i < 4; ++i){
			int nx = cx + dx[i]; int ny = cy + dy[i];
			if(nx<0||nx>=R||ny<0||ny>=C)continue;
			if(G[nx][ny] == -1)continue;
			if(bfs[nx][ny] != -INF)continue;
			Q.push(mp(nx,ny));
			bfs[nx][ny] = bfs[cx][cy] - 2;
		}
	}
	for (int i = 0; i < V.size(); ++i){
		D[E][i] = bfs[V[i].a][V[i].b];
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> R >> C;
	for (int i = 0; i < R; ++i){
		cin >> S;
		for (int j = 0; j < C; ++j){
			if (S[j] == '~')G[i][j] = -1;
			else if (S[j] == '.')G[i][j] = 0;
			else {
				if (S[j] != 'C')G[i][j] = S[j] - '0';
				V.pb({i,j,G[i][j]});
			}
		}
	}
	sort(V.begin(),V.end(),cmp);
	for (int i = 0; i < V.size(); ++i){
		E = i;
		//cout << V[i].a << ' ' << V[i].b << '\n';
		fill(V[i].a, V[i].b);
	}
	for (int i = 0; i < V.size(); ++i){
		for (int j = 0; j < (1 << V.size()); ++j){
			DP[i][j] = INF;
		}
	}
	T = (1 << V.size()) - 1;
	int ans = 0;
	//cout << tsp(0,1) << '\n';
	for (int bm = 0; bm <= T; ++bm){
		int cur = 0;
		for (int i = 0; i < V.size(); ++i){
			if (bm & (1<<i))continue;
			cur += V[i].w;
		}
		ans = max(ans,cur+tsp(0,bm));
	}
	cout << ans << '\n';
	/*
	for (int i = 0; i < V.size(); ++i){
		for (int j = 0; j < V.size(); ++j){
			cout << D[i][j] << ' ';
		}
		cout << '\n';
	}
	*/
}
