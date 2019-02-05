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
ll INF = 1e15;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (ll)x.size()
#define ALL(x) x.begin(),x.end()

set<ll> S;
ll A[500100], N, ind[500100];
ll ans;


int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin>>N;
  for (ll i=1;i<=N;++i){
    cin>>A[i];
    ind[A[i]] = i;
  }
  S.insert(0);
  S.insert(N+1);
  for (ll i=1;i<=N;++i){
    ll x = ind[i];
    ll left = *(--S.lb(x));
    ll right = *(S.lb(x));
    ll l = x - left;
    ll r = right - x;
    ans += (i * l * r);
    S.insert(x);
  }
  cout<<ans;
}
