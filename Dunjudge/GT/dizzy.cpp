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

vi adjList[100100];
int N,D,U,a,b;
vi topo;
bool visited[100100];
int topoord[100100];
vpi edgeList;

void dfs(int x){
  for (auto i : adjList[x]){
    if (visited[i])continue;
    visited[i] = 1;
    dfs(i);
  } 
  topo.pb(x);
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin >> N >> D >> U;
  for (int i = 0; i < D; ++i){
    cin >> a >> b;
    adjList[a].pb(b);
    edgeList.pb(mp(a,b));
  }
  for (int i = 1; i <= N; ++i){
    if (visited[i])continue;
    visited[i]  =1;
    dfs(i);
  }
  // for (auto i : topo)cout << i << '\n';
  reverse(topo.begin(),topo.end());
  for (int i = 0; i < N; ++i){
    topoord[topo[i]] = i;
  }
  for (int i = 0; i < U; ++i){
    cin >>  a >> b;
    if (topoord[a] > topoord[b]){
      cout <<a << ' ' << b << '\n';;
    }else cout << b << ' ' <<a << '\n';
  }

}
