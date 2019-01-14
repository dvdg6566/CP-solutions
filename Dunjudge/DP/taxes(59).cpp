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
ll N,a,b,ans;
vpi V;
vector<ll> V2;

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  freopen("input.txt","r",stdin);
  bool st5 = 1, st6 = 1;
  cin>>N;
  for (int i=0;i<N;++i){
    cin>>a>>b;
    V.pb(mp(a,b));
    if (b != 0)st5 = 0;
    if (a != b)st6 = 0;
  }
  sort(ALL(V));
  if (st5){
    for (int i=0;i<N;++i){
      ans = max(ans, (N-i) * V[i].f);
    }
    cout << ans;
    return 0;
  }
  if (st6){
    for (auto i : V)V2.pb(i.f);
    ll dp[75100];
    for (int i=0;i<N;++i){
      dp[i] = (N-i) * V2[i];
      cout << dp[i]<<' ';
    }
    return 0;
  }
  for (int i=0;i<N;++i){
    ll tmp = 0;
    V2.clear();
    for (int j =0;j<i;++j){
      V2.pb(V[j].s);
    }
    sort(ALL(V2));
    for (int j=0;j<V2.size();++j){
      ll t = (V2.size() - j) * (V2[j]);
      tmp = max(tmp, t );
    }
    tmp += (N-i)*V[i].f;
    ans = max(ans, tmp);
  }
  cout << ans;
}
