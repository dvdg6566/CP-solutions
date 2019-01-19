#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<int, pi> pii;
typedef set<int> si;
typedef vector<pi> vpi;
typedef double dl;
#define mp make_pair
#define pb push_back
#define f first
#define s second
ll MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
#define INF 10000000
#define SZ(x) x.size()
#define ALL(x) x.begin(),x.end()

int N,M,a,b,T;
int p[100100][2];
int par(int x, int row) { return (x==p[x][row])?x:p[x][row]=par(p[x][row],row);}
vi adjList[100100];
vpi edgeList;
int depth[100100], lowlink[100100], pa[100100];

void dfs(int x){
  lowlink[x] = depth[x];
  for (auto i : adjList[x]){
    if(i == pa[x]){
      continue;
    }
    if (depth[i] != -1){
      lowlink[x] = min(lowlink[i], lowlink[x]);
      continue;
    }
    depth[i] = depth[x] + 1;
    T = max(depth[i], T);
    pa[i] = x;
    dfs(i);
    lowlink[x] = min(lowlink[x], lowlink[i]);
  } 
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin>>N>>M;
  for (int i=1;i<=N;++i)p[i][0] = p[i][1] = i;
  for (int i=0;i<M;++i){
    cin>>a>>b;
    if (par(a,0) != par(b,0)){
      p[par(a,0)][0] = par(b,0);
      if (a > b)swap(a,b);
      edgeList.pb(mp(a,b));
      // cout << "KEEP " << a << ' ' << b << '\n';
      continue;
    }
    if (par(a,1) == par(b,1))continue;
    p[par(a,1)][1] = par(b,1);
    if (a > b)swap(a,b);
    edgeList.pb(mp(a,b));
    // cout << "KEEP " << a << ' ' << b << '\n';
  }
  // for (auto i : edgeList)cout<<i.f<<' '<<i.s<<'\n';cout<<"\n\n";
  memset(depth,-1,sizeof(depth));
  memset(pa,-1,sizeof(pa));
  // sort(ALL(edgeList));
  // edgeList.resize(distance(edgeList.begin(), unique(ALL(edgeList))));
  for (auto i : edgeList){
    adjList[i.f].pb(i.s);
    adjList[i.s].pb(i.f);
  }
  // for (int i=1;i<=N;++i)cout<<i<<' '<<depth[i]<<' '<<lowlink[i]<<'\n';
  // for (int i=1;i<=N;++i){
    // if (lowlink[i] >= depth[i])cout<<i<<'\n';
  // }

  for (int i=1;i<=N;++i){
    if (depth[i] != -1)continue;
    pa[i] = 0;
    depth[i] = T+1;
    T++;
    dfs(i);
  }
  vpi V;
  for (auto i : edgeList){
    if (lowlink[i.f] <= depth[i.s] && depth[i.f] > depth[i.s])continue;
    if (lowlink[i.s] <= depth[i.f] && depth[i.s] > depth[i.f])continue;
    V.pb(i);
  }
  sort(ALL(V));
  for (int i=0;i<V.size();++i){
    if (i+1 != V.size() && V[i+1].f == V[i].f && V[i+1].s == V[i].s){++i;continue;}
    cout<<V[i].f<<' '<<V[i].s<<'\n';
  }
}
