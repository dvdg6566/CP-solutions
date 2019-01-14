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

ll A[301000], N,X;
vpi adjList[301000];
ll dist[301000],L,ans;

void dfs(int x){
	for (auto i : adjList[x]){
		if(i.f == X%N)L=dist[x] + i.s;
		if (dist[i.f] != -1)continue;
		dist[i.f] = dist[x] + i.s;
		dfs(i.f);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> N >> X;
	for (int i = 0; i < N; ++i)cin>> A[i];
	for (int i = 0; i < N; ++i){
		adjList[(i+A[i])%N].pb(mp(i,A[i]));
	}
	memset(dist,-1,sizeof(dist));
	dist[X%N] = 0;
	dfs(X%N);
	for (int i = 0; i < N; ++i){
		 if(dist[i] == -1)continue;
		 if (dist[i] > X)continue;
		 if (!L)ans ++;
		 else ans += (X - dist[i]) / L + 1;
	}
	cout << ans;
}
