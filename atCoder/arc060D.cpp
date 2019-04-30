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
ll INF = 1e9;
ll MOD = 1e9;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (ll)x.size()
#define ALL(x) x.begin(),x.end()

ll N,S,D;

vi fact;

int main(){
  // freopen("in.txt","r",stdin);
  cin >> N >> S;
  D = N-S;
  if (N < S){
    cout<<-1;
    return 0;
  }

  if (N == S){
    cout<<N+1;
    return 0;
  }

  for (ll i = 2;i*i<=N;++i){
    ll t = N;
    ll d = 0;
    while(t){
      d += t%i;
      t /= i;
    }
    if (d == S){
      cout<<i;
      return 0;
    }
  }


  for (ll i = 1; i*i<N && i<=S;++i){
    if (D%i == 0){
      fact.pb(D/i);
    }
  }
  
  reverse(ALL(fact));

  for (auto v : fact){
    ll b = v+1;
    ll a = D/v;
    ll c = N - a*b;
    if (c > b)continue;
    if ((a+1) * b <= N)continue;
    if (a * b > N)continue;
    if (a + c != S)continue;
    cout<<b;
    return 0;
  }
  cout<<-1;
}
