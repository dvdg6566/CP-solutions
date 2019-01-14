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

ll N,E,Q,K,a,b,w;
vpi adjList[300100];
ll d[300100];

void dfs(ll x){
  for (auto i : adjList[x]){
    if (d[i.f] != -1)continue;
    d[i.f] = d[x] + i.s;
    dfs(i.f);
  }
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> N;
	for (int i = 1; i < N; ++i){
		cin >> a >> b >> w;
		adjList[a].pb(mp(b,w));
		adjList[b].pb(mp(a,w));
	}
  cin >> Q >> K;
	memset(d,-1,sizeof(d));
  d[K] = 0;
  dfs(K);
	for (int i = 0; i < Q; ++i){
		cin >> a >> b;
		cout << d[a]+ d[b] << '\n';
	}
}

