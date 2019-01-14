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
#define MOD 1000007
#define lb lower_bound
#define ub upper_bound
#define dst distance
#define INF 1000000000

int grid[120][120];
string st;
int N,T,src;
vi adjList[12000];
int dx[] = {-1,-1}, dy[] = {-1,1};
vi topo;
int dp[12000];
bool visited[12000];

void dfs(int x){
   for (auto i : adjList[x]) {
        if (visited[i]) continue;
        visited[i] = 1;
        dfs(i);
    }
    topo.pb(x);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> T;
	for (int caseno = 1; caseno <= T; ++caseno){
		cin >> N;
		memset(grid,0,sizeof(grid));
		for (int i = 0; i < N; ++i){
			cin >> st;
			for (int j = 0; j < N; ++j){
				if(st[j] == 'W')src = i*N+j;
				if(st[j] == 'B')grid[i][j] = 1;
			}
		}
		for (int i = 0; i <= N*N; ++i)adjList[i].clear();
		for (int i = 1; i < N; ++i){
			for (int j = 0; j < N; ++j){
				for (int k = 0; k < 2; ++k){
					int cx = i + dx[k], cy = j + dy[k];
					if (cx<0)continue;
					if (cy<0)continue;
					if (cx>=N)continue;
					if (cy>=N)continue;
					if (grid[cx][cy]){
						int cx2 = cx + dx[k], cy2 = cy + dy[k];
						if (cx2<0)continue;
						if (cy2<0)continue;
						if (cx2>=N)continue;
						if (cy2>=N)continue;
						if(grid[cx2][cy2])continue;
						adjList[i*N+j].pb(cx2*N+cy2);
					}else{
						adjList[i*N+j].pb(cx*N+cy);
					}
				}
			}
		}
		for (int i = 0; i < N; ++i){
			adjList[i].pb(N*N);
		}
		topo.clear();
		memset(dp,0,sizeof(dp));
		memset(visited,0,sizeof(visited));
		dfs(src);
		dp[src] = 1;
		reverse(topo.begin(),topo.end());
		for (auto i : topo){
			for (auto j : adjList[i]){
				dp[j] += dp[i];
				dp[j] = dp[j]%MOD;
			}
		}
		cout << "Case " << caseno << ": " << dp[N*N] << '\n';
	}
}
