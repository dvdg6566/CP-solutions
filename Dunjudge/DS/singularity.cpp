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
#define MOD 1e9+7
ll INF = 1e15;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (ll)x.size()
#define ALL(x) x.begin(),x.end()

int A[1001000];

int gcd(int a, int b){
  if (a<b)swap(a,b);
  if (b == 0)return a;
  return gcd(b, a%b);
}

struct SparseTable{
  vector<vi> ST;
  int N,K;
  SparseTable(int _N){
    N=_N;
    K = MSB(N);
    ST.resize(K);
    ST[0] = vi(A,A+N);
    for (int k=1;k<K;++k){
      for (int i=0;i+(1<<k)<=N;++i){
        ST[k].pb(gcd(ST[k-1][i], ST[k-1][i+(1<<(k-1))]));
      }
    }
  }
  inline int MSB(unsigned int x){return 32-__builtin_clz(x);}
  int query(int x, int y){
    if (x == y)return A[x];
    // cout<<x<<' '<<y<<'\n';
    int k = MSB(y-x+1) - 1;
    return gcd(ST[k][x], ST[k][y-(1<<k)+1]);
  }
}*S;

int N;

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin>>N;
  int lower = -1;
  ll ans = 0;
  for (int i=0;i<N;++i)cin>>A[i];
  S = new SparseTable(N); 
  for (int i=0;i<N;++i){
    while(1){
      if (lower >= i)break;
      if (S->query(lower+1,i) != 1)break;
      ++lower;
    }
    // cout<<i<<' '<<lower<<'\n';
    ans += (lower+1);
  }
  cout<<ans;
}
