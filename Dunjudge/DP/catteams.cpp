#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end
ll INF = 1000000000000000000;

ll dp[20010][2], opt[20010][2];
ll A[20010],B[20010];
ll N,K;

struct SparseTable{
  vector<vector<ll>> ST;
  int lN,lK;
  SparseTable(ll _N, ll a[]): lN(_N){
    lK = MSB(N);
    ST.resize(lK);
    ST[0] = vector<ll>(a,a+N);
    // for (auto i : ST[0])cout<<i<<' ';cout<<'\n';
    for (int k = 1; k < lK; ++k){
      for (int i = 0; i+(1<<k) <= lN; ++i){
        ST[k].pb(min(ST[k-1][i], ST[k-1][i +(1<<(k-1))]));
      }
    }
  }
  
  inline int MSB (unsigned int x){return 32-__builtin_clz(x);}

  ll query (ll x, ll y){
    // --x;--y;
    int k = MSB (y-x+1) - 1;
    return min(ST[k][x], ST[k][y-(1<<k)+1]);
  }
}*maxtable, *mintable;

ll cost(ll a, ll b){
  --a;--b;
  // if (a >= N || b >= N)return -INF;
  // if (a > b)return -INF;
  return - maxtable->query(a,b) - mintable->query(a,b);
}

void dnc(ll s, ll e, ll x, ll y, ll k){
  // cout<<s<<' '<<e<<' '<<x<<' '<<y<<' '<<k<<'\n';
  ll m=(s+e)/2;
  for (int i=x;i<=y&&i+1<=m;++i){
    // cout << i+1 << ' ' << m << ' '<< cost(i+1,m) <<'\n';
    // cout<<"Check " << m<<' '<<dp[i][1-k]<<' '<<cost(i+1,m) <<'\n';
    if (dp[m][k] < dp[i][1-k] + cost(i+1,m)){
      dp[m][k] = dp[i][1-k] + cost(i+1, m);
      opt[m][k] = i;
    }
  }
  // cout<<m<<' '<<dp[m][k]<<'\n';
  if (s < m)dnc(s,m-1,x,opt[m][k], k);
  if (m < e)dnc(m+1,e,opt[m][k],y, k);
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin>>N>>K;
  for (int i=0;i<N;++i){cin>>A[i];B[i] = -A[i];}
  mintable = new SparseTable(N,A);
  maxtable = new SparseTable(N,B);
  for (int i=1;i<=N;++i)dp[i][0] = -INF;
  dp[0][1] = -INF;
  // for (int i=0;i<N;++i){
  //   for (int j=0;j<N;++j){
  //     cout<<cost(i,j)<<' ';
  //   }cout<<'\n';
  // }
  // return 0;
  for (int i=1;i<=K;++i){
    for (int j=0;j<=N;++j)dp[j][i%2] = -INF;
    dnc(i-1,N,max(0,i-2),N-1,i%2);
    // for (int j=1;j<=N;++j)cout<<dp[j][i%2]<<' ';
    // cout<<'\n';
  }
  cout << dp[N][K%2] << '\n';
  return 0;
  for (int i=1;i<=2;++i){
    for (int j=1;j<=K;++j)cout << dp[j][i] << ' ';cout << '\n';
  } 
}
