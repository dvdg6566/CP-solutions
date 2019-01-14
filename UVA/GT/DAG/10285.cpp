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

int T,R,C;
string loc;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
vi adjList[12000];
ll visited[12000];
int G[110][110];
vi topo;

void tdfs(int x){
   visited[x] = 1;
   for (auto i : adjList[x]) {
        if (visited[i]) continue;
        tdfs(i);
    }
    topo.pb(x);
}

int main(){
	//freopen("input.txt","r",stdin);
	cin >> T;
	while(T--){
		cin>>loc>>R>>C;
		for (int i = 0; i < R; ++i){
			for (int j = 0; j < C; ++j){
				cin>>G[i][j];
				adjList[i*C+j].clear();
			}
		}
		cout << loc << ": ";
		for (int i = 0; i < R; ++i){
			for (int j = 0; j < C; ++j){
				for (int k =0; k < 4; ++k){
					int cx = i+dx[k], cy=j+dy[k];
					if(cx<0||cy<0)continue;
					if(cx>=R||cy>=C)continue;
					int a = i*C+j, b = cx*C+cy;
					if (G[i][j] <= G[cx][cy])continue;
					adjList[a].pb(b);
				}
			}
		}
		topo.clear();
		memset(visited,0,sizeof(visited));
		for (int i = 0; i < R*C; ++i){
			if(visited[i])continue;
			tdfs(i);
		}
		reverse(topo.begin(),topo.end());
		for (int i =0; i < R*C; ++i)visited[i] = 1;
		for (auto it : topo){
			for (auto i : adjList[it]){
				visited[i] = max(visited[i], visited[it] + 1);
			}
		}
		
		cout << *max_element(visited,visited+R*C) << '\n';
	}
}
