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
int N,a,b,w,ans;
int par[1001000],low[1001000],visited[1001000], furthest[1001000], nxt[1001000], extra [1001000];
vpi adjList[1001000];

void pardfs(int x){
	for (auto i : adjList[x]){
		if (par[i.f] != -1)continue;
		par[i.f] = x;
		pardfs(i.f);
	}
}
void tspdfs(int p){
  visited[p] = 1;
  for (auto it : adjList[p]){
	if (it.f == par[p])continue;
    if (visited[it.f])continue;
    tspdfs(it.f);
    ans += it.s;
  }
}
int tsp(){
	memset(visited,0,sizeof(visited));
	tspdfs(0);
	return ans*2;
}
void findLow(int x){
  if(adjList[x].size() == 1 && x != 0)return;
  ll res = 0;
  for (auto i : adjList[x]){
	if (i.f == par[x])continue;
	findLow(i.f);
	res = max(res,i.s+low[i.f]);
  }
  low[x] = res;
  return;
}

void mapLowtoChild(int x){
	if(adjList[x].size() == 1 && x != 0)return;
	if(low[x] == furthest[x]){
	  bool done = 0; ll next = extra[x];
	  for(auto i : adjList[x]){
		 if(i.f == par[x])continue;
		 if(low[i.f]+i.s == low[x]){
			if(done)next = low[x];
			else done = 1;
		 }else{
			next = max(next,low[i.f]+i.s);
		 }
	  }
	  for(auto i : adjList[x]){
		 if(i.f == par[x])continue;
		 if(low[i.f]+i.s == low[x]){
			 if(low[x]-i.s > i.s+next){
				extra[i.f] = i.s+next;
			 }
			 furthest[i.f] = max(low[x]-i.s,i.s+next);
		 }else{
			furthest[i.f] = i.s + low[x];
		 }
		 mapLowtoChild(i.f);
	  }
	}else{
		for (auto i : adjList[x]){
			if(i.f == par[x])continue;
			furthest[i.f] = furthest[x] + i.s;
			mapLowtoChild(i.f);
		}
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
  memset(par,-1,sizeof(par));
  par[0] = 0;
  pardfs(0);
  //for (int i = 0; i < N; ++i)cout << par[i] << ' ';cout << '\n';
  int x = tsp();
  findLow(0);
  furthest[0] = low[0];
  mapLowtoChild(0);
  for(int i = 0; i < N; ++i)cout << x-furthest[i] << ' ';
}
