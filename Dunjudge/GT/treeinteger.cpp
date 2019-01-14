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
#define INF 1000000000
#define SZ(x) x.size()
#define ALL(x) x.begin(),x.end()

int N,Q,a,b;
pi rng[100100];
int ans[100100];
vi adjList[100100];
int p[100100];

pi unionpair(pi a, pi b){
  if (abs(a.f)%2 != abs(b.f)%2 && a.s < INF && b.s < INF){
    cout<<"No";
    exit(0);
  }
  pi res = mp ( max(a.f,b.f) , min(a.s,b.s));
  if (res.f > res.s){
    cout<<"No";
    exit(0);
  }
  return res;
}

void dfs(int x){
  for (auto i : adjList[x]){
    if (p[i] != -1)continue;
    p[i] = x;
    dfs(i);
  }
}

void crange(int x){
  pi res = rng[x];
  for (auto i : adjList[x]){
    if (p[x] == i)continue;
    crange(i);
    pi chk = mp(rng[i].f-1, rng[i].s + 1);
    // cout<<i<<' '<<chk.f<<' '<<chk.s<<'\n';
    res = unionpair(res,chk);
  }
  rng[x] = res;
  // cout<<x<<' '<<res.f<<' '<<res.s<<'\n';
  return;
}

void fill(int x){
  if (rng[x].f != -INF){
    for (auto i : adjList[x]){
      if (p[x] == i)continue;
      rng[i] = unionpair(rng[i], mp(rng[x].f - 1, rng[x].s +1));
    }
  }
  if (ans[x] == -INF){ans[x] = rng[x].f;}
  for (auto i : adjList[x]){
    if (p[x] == i)continue;
    rng[i] = unionpair(rng[i], mp(ans[x] - 1, ans[x] + 1));
    fill(i);
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin>>N;
  for (int i=0;i<N-1;++i){
    cin>>a>>b; 
    adjList[a].pb(b);
    adjList[b].pb(a);
  }
  for (int i=1;i<=N;++i)ans[i]=-INF;
  for (int i=1;i<=N;++i)rng[i]=mp(-INF,INF);
  cin>>Q;
  for (int i=0;i<Q;++i){
    cin>>a>>b;
    rng[a] = mp(b,b);
    ans[a] = b;
  }
  memset(p,-1,sizeof(p));
  p[1] = 0;
  dfs(1);
  crange(1);
  fill(1);
  cout<<"Yes\n";
  for (int i=1;i<=N;++i)cout<<ans[i]<<'\n';
  }
