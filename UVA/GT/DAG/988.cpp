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
vi adjList[40];
vi topo;
ll dp[12000];
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
	while(cin>>N){
		if(cin.eof())return 0;
		if(dp[0]!=0)cout << '\n';
		for (int i = 0; i < N; ++i){
			adjList[i].clear();
			cin >> a;
			if (a==0)adjList[i].pb(N);
			while(a--){
				cin >> b;
				adjList[i].pb(b);
			}
		}
		topo.clear();
		memset(dp,0,sizeof(dp));
		memset(visited,0,sizeof(visited));
		dfs(0);
		dp[0] = 1LL;
		reverse(topo.begin(),topo.end());
		for (auto i : topo){
			for (auto j : adjList[i]){
				dp[j] += dp[i];
			}
		}
		cout << dp[N] << '\n';
	}
}
