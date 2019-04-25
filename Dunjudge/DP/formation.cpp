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
ll INF = 7e18;
ll MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (ll)x.size()
#define ALL(x) x.begin(),x.end()

ll MAXN = 262144;
ll dp[262144];
ll bm;
ll ans=INF;

vi V;
ll N,a;

ll calc(ll b){
  if (dp[b] != -1)return dp[b];  
  if (b == 0)return dp[b] = 0;
  vi t;
  ll opt = INF;
  for (int i=0;i<N;++i)if (1<<i & b)t.pb(i);
  for (int w = 2; w < SZ(t); ++w){
    for (int x = 1;x<w;++x){
      for (int y=0;y<x;++y){
        opt = min(opt, V[t[w]] * V[t[x]] * V[t[y]] + calc(b - (1<<t[w]) - (1<<t[x]) - (1<<t[y])));
      }
    }
  }
  return dp[b] = opt;
}

int main(){
  // freopen("in.txt","r",stdin);
  cin >> N;
  memset(dp, -1, sizeof(dp));
  for (ll i=0;i<N;++i){
    cin >> a;
    V.pb(a);
  }
  sort(ALL(V));
  while(N%3){
    V.pop_back();
    --N;
  }
  bm = (1<<N)-1;
  ll L = 3*((N+3)/6);
  ll R = N - L;
  for (ll i=0;i<=bm;++i){
    ll c = 0;
    for (ll j=0;j<N;++j)if (i & (1<<j))++c;
    if (L != c)continue;
    // cout<<i<<' '<<bm-i<<'\n';
    ans = min(ans, calc(i) + calc(bm-i));
  }
  // for (int i=1;i<=64;++i)cout<<dp[i]<<'\n';
  cout<<ans;
}