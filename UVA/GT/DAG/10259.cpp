#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<int,int> pi;
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

int grid[110][110];
int N,M,T;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
vpi adjList[15000];
int visited[15000];

vector<int> topo;

void topodfs(int x){
   visited[x] = 1;
   for (auto i : adjList[x]) {
        if (visited[i.f]) continue;
        topodfs(i.f);
    }
    topo.pb(x);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin>>T;
	while(T--){
		memset(grid,0,sizeof(grid));
		for (int  i = 0; i < N*N; ++i)adjList[i].clear();
		cin >> N >> M;
		if(M>=N)M=N-1;
		for (int i = 0; i < N; ++i){
			for (int j=0; j < N; ++j){
				cin >> grid[i][j];
			}
		}
		for (int i = 0; i < N; ++i){
			for (int j = 0; j < N; ++j){
				for (int it = 1; it <= M; ++it){
					for (int k = 0; k < 4; ++k){
						int cx = i+dx[k]*it;
						int cy = j+dy[k]*it;
						if(cx<0||cy<0)continue;
						if(cx>N||cy>N)continue;
						if(grid[i][j]>=grid[cx][cy])continue;
						adjList[i*N+j].pb(mp(cx*N+cy,grid[cx][cy]));
					}
				}
			}
		}
		memset(visited,0,sizeof(visited));
		topo.clear();
		topodfs(0);
		reverse(topo.begin(),topo.end());
		memset(visited,0,sizeof(visited));
		visited[0] = grid[0][0];
		for (auto it : topo){
			for (auto i : adjList[it]){
				visited[i.f] = max(visited[i.f], visited[it] + i.s);
			}
		}
		cout << *max_element(visited,visited+N*N) << '\n';
		if(T)cout<<'\n';
	}
}
