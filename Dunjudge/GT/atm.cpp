#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef pair<ll,pi> pii;
typedef vector<pi> vpi;
typedef set<ll> si;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define f first
#define s second
ll INF = 1e8;
ll MOD = 1e9;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (ll)x.size()
#define ALL(x) x.begin(),x.end()

ll curstack[500100],SCC[500100], ind[500100],lowlink[500100];
ll N,E,a,b;
stack<ll> stk;
vi aList[500100];
vpi edgeList;
ll val[500100], dp[500100];

void dfs(ll x){
  if (ind[x] != -1)return;
  ind[x] = lowlink[x] = b++;
  stk.push(x);
  curstack[x] = 1;
  for (auto v : aList[x]){
    if (SCC[v])continue;
    if (ind[v] == -1){
      dfs(v);
      lowlink[x] = min(lowlink[x], lowlink[v]);
    }else if (curstack[v]){
      lowlink[x] = min(lowlink[x], ind[v]);
    }
  }
  if (lowlink[x] == ind[x]){
    while(stk.top() != x){
      SCC[stk.top()] = a;
      curstack[stk.top()] = 0;
      stk.pop();
    }
    SCC[x] = a++;
    stk.pop();
  }
}

vi tp;
bool visited[500100];
void topo(ll x){
  for (auto i : aList[x]){
    if (visited[i] == 1)continue;
    visited[i] = 1;
    topo(i);
  }
  tp.pb(x);
}

int main(){
  // freopen("in.txt","r",stdin);
  cin >> N >> E;
  for (ll i=0;i<E;++i){
    cin >> a >> b;
    aList[a].pb(b);
    edgeList.pb(mp(a,b));
  }
  memset(ind,-1,sizeof(ind));
  b = a = 1;
  for(ll i=1;i<=N;++i){
    dfs(i);
  }
  // for (ll i=1;i<=N;++i)cout<<SCC[i]<<' ';cout<<'\n';
  for (ll i=1;i<=N;++i)aList[i].clear();
  for (auto i : edgeList){
    if(SCC[i.f] != SCC[i.s])aList[SCC[i.f]].pb(SCC[i.s]);
  }
  for (ll i=1;i<=N;++i){
    sort(ALL(aList[i]));
    aList[i].resize(unique(ALL(aList[i])) - aList[i].begin());
  }

  for (ll i=1;i<=N;++i){
    cin >> a;
    val[SCC[i]] += a;
  }
  // for (ll i=1;i<=N;++i)cout<<val[i]<<' ';cout<<'\n';
  ll S;
  for (ll i=1;i<=N;++i)if (!visited[SCC[i]]){visited[SCC[i]] = 1;topo(SCC[i]);}
  // for (auto i : tp)cout<<i<<' ';cout<<'\n';
  reverse(ALL(tp));
  for (ll i=1;i<=N;++i)dp[i] = -INF;
  cin >> S; dp[SCC[S]] = 0;
  for (auto x : tp){
    dp[x] = dp[x] + val[x];
    for (auto v : aList[x])dp[v] = max(dp[v], dp[x]);
  }
  // for (int i=1;i<=4;++i)cout<<dp[i]<<' ';cout<<'\n';
  ll ans = 0;
  ll T;
  cin >> T;
  while(T--){
    cin >> a;
    ans = max(ans, dp[SCC[a]]);
  }
  cout<<ans;
}