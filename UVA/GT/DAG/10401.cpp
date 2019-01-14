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

int N,a,b;
vi adjList[300];
vi topo;
ll dp[300];
bool visited[300];
string str;

void dfs(int x){
   for (auto i : adjList[x]) {
        if (visited[i]) continue;
        visited[i] = 1;
        dfs(i);
    }
    topo.pb(x);
}

int cnv(char x){
	int tmp = x;
	if (48 < tmp && tmp <= 57)return x - '1';
	return x - 'A' + 9;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	while(cin>>str){
		if(cin.eof())return 0;
		N = str.size();
		for (int i = 0; i <= 225; ++i)adjList[i].clear();
		for (int i = 0; i < N-1; ++i){
			for (int k = 0; k < N; ++k){
				for (int j = 0; j < N; ++j){
					if (abs(j-k) > 1){
						adjList[k+i*N].pb(j+(i+1)*N);
					}
				}
			}
			if(str[i]!='?'){
				a = cnv(str[i]);
				for (int j = 0; j < N; ++j){
					if(j!=a)adjList[i*N+j].clear();
				}
			}
		}
		
		for (int i = 0; i < N; ++i){
			adjList[N*N-N+i].pb(N*N);
			if(str[N-1]!='?'&&cnv(str[N-1])!=i)adjList[N*N-N+i].clear();
		}
		
		topo.clear();
		memset(dp,0,sizeof(dp));
		memset(visited,0,sizeof(visited));
		if(str[0]!='?'){
			dfs(cnv(str[0]));
			dp[cnv(str[0])]=1;
		}
		else{
			for (int i = 0; i < N; ++i){
				dfs(i);
				dp[i] = 1LL;
			}
		}
		reverse(topo.begin(),topo.end());
		for (auto i : topo){
			for (auto j : adjList[i]){
				dp[j] += dp[i];
			}
		}
		cout << dp[N*N] << '\n';
	}
}
