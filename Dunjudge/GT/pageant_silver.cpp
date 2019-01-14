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

int N,M;
int table[55][55];
string st;
vi adjList[2600];
int dist[4][2600];
int cnt = 1;
queue<int> q;

int cnv(pi X){
	if(table[X.f][X.s])return table[X.f][X.s];
	return 4+X.f*M+X.s;
}

int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};
void dfs(pi x){
	for (int k = 0; k < 4; ++k){
		int cx = dx[k] + x.f, cy = dy[k] + x.s;
		if (cx<0||cy<0)continue;
		if(cx>=N)continue;
		if(cy>=M)continue;
		if(table[cx][cy] != -1)continue;
		table[cx][cy] = table[x.f][x.s];
		dfs(mp(cx,cy));
	}
}

void bfs(){
	while(q.size())q.pop();
	q.push(cnt);
	while (!q.empty()){
		int x = q.front();
		q.pop();
		for (auto it:adjList[x]){
			if (dist[cnt][it])continue;
			dist[cnt][it] = dist[cnt][x] + 1;
			q.push(it);
		}
	}
	for (int i = 0; i < N*M; ++i){
		dist[cnt][i]--;
		if(dist[cnt][i])dist[cnt][i]--;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> N >> M;
	for (int i = 0;i < N; ++i){
		cin >> st;
		for (int j = 0; j < M; ++j){
			table[i][j] = -(st[j] == 'X');
		}
	}
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < M; ++j){
			if(table[i][j] != -1)continue;
			table[i][j] = cnt;
			dfs(mp(i,j));
			cnt++;
		}
	}
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < M; ++j){
			for (int k = 0; k < 4; ++k){
				int cx = dx[k] + i, cy = dy[k] + j;
				if (cx<0||cy<0)continue;
				if(cx>=N)continue;
				if(cy>=M)continue;
				if(cnv(mp(i,j)) == cnv(mp(cx,cy)))continue;
				adjList[cnv(mp(i,j))].pb(cnv(mp(cx,cy)));
			}
		}
	}
	cnt = 1;
	memset(dist,0,sizeof(dist));
	for (;cnt<=3;++cnt){
		dist[cnt][cnt] = 1;
		bfs();
	}
	int ans = INF;
	for (int i = 0; i < N*M+4; ++i){
		if(!adjList[i].size())continue;
		ans = min(ans,dist[1][i]+dist[2][i]+dist[3][i]+(i>3));
	}
	cout << ans << '\n';
}
