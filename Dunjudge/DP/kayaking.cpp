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
ll MOD = 1e9;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (ll)x.size()
#define ALL(x) x.begin(),x.end()

vpi V;

double dst(int a, int b){
  if (a == 0)a = 1;
  return sqrt((double)( (V[a].f-V[b].f)*(V[a].f-V[b].f) + (V[a].s-V[b].s)*(V[a].s-V[b].s) ));
}

ll N,a,b;
double dp[1010][1010];

int main(){
  // freopen("in.txt","r",stdin);
  cin >> N;
  V.pb(mp(-1,-1));
  for (int i=0;i<N;++i){
    cin>>a>>b;
    V.pb(mp(a,b));
  }
  sort(ALL(V));

  // for (int i=1;i<=N;++i){
    // for (int j=1;j<=N;++j)cout<<dst(i,j)<<' ';
    // cout<<'\n';
  // }
  // cout<<"\n\n";
  dp[1][0] = 0;
  for (int i=2;i<=N;++i){
    double x = INF;
    for (int j=0;j<i-1;++j){
      dp[i][j] = dp[i-1][j] + dst(i-1,i);
    }
    for (int j=0;j<i-1;++j){
      x = min(x, dp[i-1][j] + dst(j,i) );
    }
  
    dp[i][i-1] = x;
    // for (int j=0;j<i;++j)cout<<dp[i][j]<<' ';
    // cout<<'\n';
  }
  // cout<<"\n\n";
  double ans = INF;
  for (int i=1;i<N;++i){
    // cout<<dp[N][i]<<' '<<dst(i,N)<<'\n';
    ans = min(ans, dp[N][i] + dst(i, N));
  }

  // cout<<'\n';
  cout<<roundf(ans);
}
