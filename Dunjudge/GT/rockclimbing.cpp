#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef pair<ll, pi> pii;
typedef set<ll> si;
typedef vector<pi> vpi;
typedef double dl;
#define mp make_pair
#define pb push_back
#define f first
#define s second
ll MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
#define INF 1000000000
#define SZ(x) x.size()
#define ALL(x) x.begin(),x.end()

vector<pii> V;
int N,a,b,c;
vi adjList[600];
si desc[600];

struct AugPath {
    int A, B;   //size of left, right groups
    vector<vector<int> > G; //size A
    vector<bool> visited;   //size A
    vector<int> P;          //size B
    
    AugPath(int _A, int _B): A(_A), B(_B), G(_A), P(_B, -1) {}
    
    void AddEdge(int a, int b) {    //a from left, b from right
        G[a].push_back(b);
    }
    
    bool Aug(int x) {
        if (visited[x]) return 0;
        visited[x] = 1;
        /* Greedy heuristic */
        for (auto it:G[x]) {
            if (P[it] == -1) {
                P[it] = x;
                return 1;
            }
        }
        for (auto it:G[x]) {
            if (Aug(P[it])) {
                P[it] = x;
                return 1;
            }
        }
        return 0;
    }
    int MCBM() {
        int matchings = 0;
        for (int i = 0; i < A; ++i) {
            visited.resize(A, 0);
            matchings += Aug(i);
            visited.clear();
        }
        return matchings;
    }
}*root;

vi llist, rl;
int lmap[1000], rmap[1000];
bool visited[1000];

void dfs(int x){
  for (auto i : adjList[x]){
    if (!visited[i]){
      visited[i] = 1;
      dfs(i);
    }
    desc[x].insert(i);
    for (auto j : adjList[i])desc[x].insert(j);
  }  
}

int main(){
  freopen("input.txt","r",stdin);
  cin >> N;
  for (int i=0;i<N;++i){
    cin>>a>>b>>c;
    V.pb(mp(c, mp(a,b)));
  }
  int L = 0;
  for (int i=0;i < N; ++i){
    int indeg = 0;
    for (int j=0;j<N;++j){
      // Edge from j to i
      if (V[i].s.s <= V[j].s.s)continue;
      if ( max(abs(V[i].s.s - V[j].s.s), abs(V[i].s.f - V[j].s.f)) > max(V[i].f, V[j].f))continue;
      adjList[j].pb(i);
      indeg++;
    }
    if (indeg == 0){
      ++L;
      llist.pb(i);
    }else{
      rl.pb(i);
    }
  }
  for (int i=0;i<llist.size(); ++i)lmap[llist[i]] = i;
  for (int i=0;i<rl.size(); ++i)rmap[rl[i]] = i;
  root = new AugPath(L, N-L);
  // cout<<L<<' '<<N-L<<'\n';
  memset(visited,0,sizeof(visited));
  for (auto i : llist){
    visited[i] = 1;
    dfs(i); 
  }
  for (auto i : llist){
    int x = lmap[i];
    for (auto it : desc[i]){
      root->AddEdge(x, rmap[it]);
      cout<<i<<' '<<it<<'\n';
    }
  }
  cout<<N-root->MCBM()+1;
}

/*
5
0 3 2
-1 5 1
4 4 3
-1 1 2
2 2 1
*/
