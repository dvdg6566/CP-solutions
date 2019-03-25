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
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end() 
ll MOD = 1e9+7;


ll mod(ll a, ll m){
 a %= m;
 if (a < 0)a += m;
 return a;
}

ll inverse(ll a, ll m){
 a = mod(a, m);
 if (a <= 1)return a;
 return mod((1 - inverse(m, a) * m) / a,m);
}

ll MAXN = 1000010;
ll pre[1000100],N,a,b,c;
ll fact[1000100];
ll A[1000010], B[1000010], C[1000010];
ll ans = 1, m;

ll query(ll st, ll en){
  if (st == 0)return pre[en];
  return (MOD + pre[en] - pre[st-1])%MOD;
}

int main(){
  fact[0] = 1;
  for (int it = 1;it<=MAXN;++it)fact[it] = (fact[it-1] * it)%MOD;
  pre[0] = pre[1] = 1;
  for (int it = 2; it <= MAXN; ++it){
    pre[it] = (pre[it-1] * inverse(it, MOD) )%MOD;
  }
  for (int it = 1;it<=MAXN;++it)pre[it] = (pre[it-1] + pre[it]) % MOD;
  cin >> N;
  for (int i=0;i<N;++i)cin>>A[i];
  for (int i=0;i<N;++i)cin>>B[i];
  for (int i=0;i<N;++i)cin>>C[i];
  for (int i=0;i<N;++i){
    a = A[i], b = B[i], c = C[i];
    m += b;
    swap(b,c);
    b = a - b;
    c = a - c;
    ll t = (fact[a] * query(b, c)) %MOD;
    ans = (ans * t) %MOD;
  }
  if(!m)--ans;
  cout<<ans;
  //for (int i=0;i<=10;++i)cout<<i<<' '<<pre[i]<<' '<<(5040 * pre[i])%MOD<<'\n';
}