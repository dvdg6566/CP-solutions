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

int N,K,L,U,a,b;
vpi adjList[301000];
vi compressed[3100];
int c = 1;
int ind[301000], par[3100], wgt[3100], child[3100];
vi DP[3100];

void root(int x){
	for (auto i : adjList[x]){
		if(ind[i.f] != -1)continue;
		if (i.s == 0){
			ind[i.f] = ind[x];
		}else{
			ind[i.f] = c;
			compressed[ind[x]].pb(c);
			c++;
			par[ind[i.f]] = ind[x];
		}
		wgt[ind[i.f]]++;
		root(i.f);
	}
}

int runDP(int x){
  if(compressed[x].size() == 0){
	  DP[x].pb(wgt[x]);
      child[x] = 1;
	  return 1;
  }
  int desc = 1;
  for (auto i : compressed[x]){
    desc += runDP(i);
  }
  int temp = 1;
  for (int i = 0; i <= desc && i <= K; ++i)DP[x].pb(wgt[x]);
  for (auto it : compressed[x]){
    temp += child[it];
    for (int i = min(K,temp); i > 0; --i){
      for (int j = 1; j <= child[it] && j <= i; ++j){
        DP[x][i] = max(DP[x][i], DP[x][i-j] + DP[it][j-1]); 
      }
    }
  }
  child[x] = desc;
  return desc;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> N >> K >> L >> U;
	for (int i = 0;i < L; ++i){
		cin >> a >> b;
		adjList[a].pb(mp(b,1));
		adjList[b].pb(mp(a,1));
	}
	for (int i = 0;i < U; ++i){
		cin >> a >> b;
		adjList[a].pb(mp(b,0));
		adjList[b].pb(mp(a,0));
	}
	memset(ind,-1,sizeof(ind));
	memset(par,-1,sizeof(par));
    cout << *max_element(DP[0].begin(),DP[0].end());
}
