#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MOD 1e9+7
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
ll INF = 10e12;

ll memo[1610][1610];
ll N,M,a;
vpi V;
vi women, men;

ll dp (ll a, ll b){
  if (a <0 || b <0)return -INF;
  if (memo[a][b] != -1)return memo[a][b];
  if (a >= b)return memo[a][b] = 0;
  if (lb(ALL(women),a) == lb(ALL(women),b+1))return memo[a][b] = 0;
  if (lb(ALL(men), a) == lb(ALL(men),b+1))return memo[a][b] = 0;
  ll ans = 0;
  if (V[a].s == 0){
    auto stop = lb(ALL(women), b+1);
    for (auto i = lb(ALL(women),a);i != stop;++i){ 
      ll c = *i;
      ans = max(ans, dp(a+1, c-1) + V[c].f - V[a].f + dp(c+1,b));
    }
  }else{
    auto stop = lb(ALL(men),b+1);
    for (auto i = lb(ALL(men),a); i != stop; ++i){ 
      ll c = *i;
      ans = max(ans, dp(a+1, c-1) + V[c].f - V[a].f + dp(c+1,b));
    }
  }
  if (V[b].s == 0){
    auto stop = lb(ALL(women), b+1);
    for (auto i = lb(ALL(women),a);i != stop;++i){ 
      ll c = *i;
      ans = max(ans, dp(c+1,b-1) + V[b].f - V[c].f + dp(a, c-1));      
    }
  }else{
    auto stop = lb(ALL(men),b+1);
    for (auto i = lb(ALL(men),a); i != stop; ++i){ 
      ll c = *i;
      ans = max(ans, dp(c+1,b-1) + V[b].f - V[c].f + dp(a, c-1)); 
    } 
  }
  return memo[a][b] = ans;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input.txt","r",stdin);
  memset(memo ,-1,sizeof(memo));
  cin >> N >> M;
  for (int i=0;i<N;++i){
    cin>>a;
    V.pb(mp(a, 0));
  }
  for (int i=0;i<M;++i){
    cin>>a;
    V.pb(mp(a,1));
  }
  sort(ALL(V));
  for (int i=0;i<N+M;++i){
    if (V[i].s == 1)women.pb(i);
    else men.pb(i);
  }
  sort(ALL(men));
  sort(ALL(women));

  cout << dp(0, N+M-1);
}

