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

string str;
ll N,M,a;
vpi adjList[5000];
bool visited[5000];
vi topo;
ll ind[5000],dp[5000];

void dfs(int x){
   visited[x] = 1;
   for (auto i : adjList[x]) {
        if (visited[i.f]) continue;
        dfs(i.f);
    }
    topo.pb(x);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	while(cin>>str){
		if(cin.eof())return 0;
		cout << str << '\n';
		cin >> N >> M;
		for (int i = 0; i <= N*M; ++i)adjList[i].clear();
		for(int i = 0; i < N-1; ++i){
			for(int j = 0; j < M; ++j){
				for (int k = 0; k < M; ++k){
					cin >> a;
					adjList[i*M+j].pb(mp((i+1)*M+k,a+2));
					//cout << i*M+j << ' ' << (i+1)*M+k << ' ' << a+2 << '\n';
				}
			}
		}
		topo.clear();
		memset(visited,0,sizeof(visited));
		for (int i = 0; i < M; ++i)dfs(i);
		reverse(topo.begin(), topo.end()); 
		memset(dp,0,sizeof(dp));
		for (auto i : topo){
			for (auto j : adjList[i]){
				if(dp[j.f] == 0)dp[j.f] = dp[i] + j.s;
				else dp[j.f] = min(dp[j.f],dp[i] + j.s);
			}
		}
		ll res = INF;
		for (int i=(N-1)*M; i < N*M; ++i)res = min(res,dp[i]);
		cout << res << '\n';
	}
}
