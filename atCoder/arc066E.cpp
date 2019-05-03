#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef pair<ll,ll> pii;
typedef vector<pi> vpi;
typedef set<ll> si;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define f first
#define s second
ll INF = 1e9;
ll MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (ll)x.size()
#define ALL(x) x.begin(),x.end()

ll ans;
char c;
ll N,a,t,out;
vpi V;

int main(){
  // freopen("in.txt","r",stdin);
  cin >> N;
  cin >> ans;
  for (int i=1;i<N;++i){
    cin >> c >> a;
    if (SZ(V) == 0 && c == '+'){
      ans += a;
      continue;
    }
    ans += a;
    if (SZ(V) && V.back().f && c == '+'){
      V.back().s += a;
      continue;
    }
    V.pb(mp(c == '+', a));
  }
  if (SZ(V)) ans -= 2*V[0].s;
  if (SZ(V) < 2){
    cout<<ans;
    return 0;
  }
  if (V[1].f == 0){
    // If second one is negative
    cout << ans;
    return 0;
  }
  out = max(out, ans - 2*V[1].s);
  int T = SZ(V);
  V.pb(mp(0,0));
  for (int i=1; i<T; ++i){
    // cout<<i<<'\n';
    if (V[i].f == 1)continue;
    if (V[i+1].f == 0){
      // cout<<"Case A " << i << '\n';
      out = max(out, ans - 2 * V[i].s);
      break;
    }
    else{
      // cout<<"Case B " << i << '\n';
      out = max(out, ans - 2 * V[i].s - 2*V[i+1].s);
    }
    ans -= 2*V[i].s;
  }
  cout<<out;
}
