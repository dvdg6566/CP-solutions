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

int L,N;
vi direct;

int main(){
  cin>>L;
  for (int i=1;i<=20;++i){
    if (!L)break;
    ++N;
    if (L % 2 == 1){
      --L;
      direct.pb(i);
    }
    L /= 2;
  }
  direct.pop_back();
  cout<<N<<' '<<SZ(direct)+2*(N-1)<<'\n';
  for (int i=1;i<N;++i){
    cout<<i<<' '<<i+1<<" 0\n";
    cout<<i<<' '<<i+1<<' '<<(1<<(i-1))<<'\n';
  }
  reverse(ALL(direct));
  int T = (1<<(N-1));
  for (auto i : direct){
    cout<<i<<' '<<N<<' '<<T<<'\n';
    T += (1<<(i-1));
  }
}