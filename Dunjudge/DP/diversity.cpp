#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef pair<ll,pi> pii;
typedef vector<pi> vpi;
typedef double dl;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MOD 1e9+7
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (int)x.size()
#define INF 1000000000

ll N,K,a,lower=-1,ans;
deque<pi> small, big;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin >> N >> K;
  for (int i =0; i < N; ++i){
    cin >> a;
    while (small.size()){
      if (small.back().f >= a){
        // cout << "Small removing " << small.back().f << '\n';
        small.pop_back();
      }else break;
    }
    small.pb(mp(a,i));
    while (big.size()){
      if (big.back().f <= a){
        // cout << "Big removing " << big.back().f << '\n';
        big.pop_back();
      }else break;
    }
    big.pb(mp(a,i));
    // cout << "Difference between " << big[0].f << " and " << small[0].f << '\n';
    while (big[0].f - small[0].f >= K){
      if (big.size() >  1 && big[0].s < small[0].s){
        // cout << "Pop front " << small[0].f <<  " from big\n";
        lower = big[0].s;
        big.pop_front();
      }else if (small.size() > 1 && small[0].s < big[0].s){
        // cout << "Pop front " << small[0].f <<  " from small\n";
        lower = small[0].s;
        small.pop_front();
      }else break;
    }
    // cout <<i << ' ' << lower << '\n';
    ans += (lower+1);
  }
  cout << ans;
}
