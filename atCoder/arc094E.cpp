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
ll INF = 1e18;
ll MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (ll)x.size()
#define ALL(x) x.begin(),x.end()

ll N,ans,offset,a,b;
vi V;

int main(){
  cin>>N;
  for (int i=1;i<=N;++i){
    cin>>a>>b;
    ans += a;
    if (a <= b){
      offset += (b-a);
    }else V.pb(b);
  }
  if (offset == 0){
    cout<<0;
    return 0;
  }
  ans -= *min_element(ALL(V));
  cout<<ans;
}