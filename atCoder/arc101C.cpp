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

ll left[100100], right[100100];
ll ans;
ll N,K;
ll A[100100];

int main(){
  cin>>N>>K;
  for (int i=1;i<=N;++i)cin>>A[i];
  --K;
  ans = INF;
  for (int i=1;i<=N;++i){
    if (i+K > N)break;
    ll a = A[i], b = A[i+K];
    if ((a > 0 && b > 0) || (a < 0 && b < 0))ans = min(ans, max(abs(a), abs(b)));
    else ans = min(ans, abs(a)+abs(b)+ min(abs(a),abs(b) ) );
  }
  cout<<ans;
}