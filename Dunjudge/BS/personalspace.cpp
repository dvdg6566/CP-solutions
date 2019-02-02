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

ll N,D,a,b,cnt;
vpi V;
ll DP[1001000];

ll query(ll t){
  memset(DP,0,sizeof(DP));
  ll start = 0, m = 0;
  for (ll i=1;i<=N;++i){
    while (V[start].f + t <= V[i].f){
      ++start;
      m = max(m, DP[start-1]);
    }
    DP[i] = m + V[i].s;
  }
  return *max_element(DP+1,DP+N+1);
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin>>N>>D;
  V.pb(mp(0,0));
  for (int i=0;i<N;++i){
    cin>>a;
    V.pb(mp(a,0));
  }
  for (int i=1;i<=N;++i){
    cin>>b;
    V[i].s = b;
    cnt += b;
  }
  sort(ALL(V));
  V.pb(mp(1e10,1));
  ll lb = 0;
  ll ub = 5e9;
  if (cnt < D){
    cout<< -2;return 0;
  }
  if (query(ub) >= D){
    cout << -1;return 0;
  }
  while (ub > lb+1){
    ll mid = (ub + lb)/2;
    if (query(mid)>=D)lb = mid;
    else ub = mid;
  }
  if (query(ub)>=D)cout<<ub;
  else cout<<lb;
}
