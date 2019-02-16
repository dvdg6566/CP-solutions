#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef pair<ll,pi> pii;
typedef vector<pi> vpi;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define f first
#define s second
ll INF = 1e15;
ll MOD = 1e18+7;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (ll)x.size()
#define ALL(x) x.begin(),x.end()

ll qexp(ll a, ll b){
  if (b <= 0)return 1;
  ll H = qexp(a,b/2);
  H = (H*H)%MOD;
  if (b %2==1)H = (H*a)%MOD;
  return H;
}

ll T,N,K;

int main(){
  // freopen("input.txt","r",stdin);
  cin>>T;
  for (int i=0;i<T;++i){
    cin>>N>>K;
    ll len = 1, cnt = 0;
    while (cnt < N){
     cnt += qexp(K,len);
     ++len; 
    }
    --len;
    N -= (cnt - qexp(K,len));
    // cout<<N<<' '<<len<<'\n';
    for (ll j=len-1; j >= 0; --j){
      ll eac = qexp(K, j);
      ll ind = (N+eac-1) / eac;
      N -= (ind-1) * eac;
      cout<<(char)(ind+'a'-1);
    }
    cout<<'\n';
  }
}