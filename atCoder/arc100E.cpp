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
 
ll N, tot,p;
ll A[(1<<18)];
pi memo[(1<<18)];

ll ck(ll a){
  if (a == -1)return 0;
  return A[a];
}

pi merge(pi a, pi b){
  if (a.f == b.f){
    if (a.s == b.s)return a;
    if (a.s > b.s)return a;
    else return mp(a.f, b.s);
  }
  if (ck(a.f)>ck(b.f)){
    if (ck(a.s) > ck(b.f))return mp(a.f, a.s);
    return mp(a.f, b.f);
  }else {
    if (ck(a.f) > ck(b.s))return mp(b.f,a.f);
    return mp(b.f,b.s);
  }
}
 
pi dp(ll x){
  if (memo[x].f != -1)return memo[x];
  pi res = mp(x, -1);
  for (int i=0;i<=18;++i){
    if ((1<<i) & x){
      pi t = dp(x - (1 << i));
      res = merge(res, t);
    }
  }
  return memo[x] = res;
}
 
int main(){
  memset(memo,-1,sizeof(memo));
  cin>>N;
  N = (1<<N);
  for (int i=0;i<N;++i)cin>>A[i];
  memo[0] = mp(0, -1);
  dp(N-1);
  ll p = 0;
  //for (int i=1;i<N;++i)cout<<memo[i].f<<' '<<memo[i].s<<'\n';
  for (int i=1;i<N;++i){
    p = max(p, A[memo[i].f]+A[memo[i].s]);
    cout<<p<<'\n';
  }
}