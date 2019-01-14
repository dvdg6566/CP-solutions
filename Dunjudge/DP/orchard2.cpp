#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<int, pi> pii;
typedef set<int> si;
typedef vector<pi> vpi;
typedef double dl;
#define mp make_pair
#define pb push_back
#define f first
#define s second
ll MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
#define INF 100000000
#define SZ(x) x.size()
#define ALL(x) x.begin(),x.end()

ll dp[210][510], p[210][210], cost[210][210];
ll N,M,T;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin >> N >> M >> T;
  for (int i=0;i<N;++i){
    for (int j=0;j<M;++j){
      cin >> p[N-i-1][j];
    }
  }
  for (int i=0;i<N;++i){
    for (int j=0;j<M;++j){
      cin >> cost[N-i-1][j];
    }
  }
  for (int i=0;i<M;++i){
    ll curcost = 0;
    ll curprof = 0;
    for (int j=0;j<N;++j){
      curcost += cost[j][i];
      curprof += p[j][i];
      // cout << curcost<< ' ' <<curprof<<'\n';
      for (ll k=curcost;k<=T;++k){
        dp[i+1][k] = max(dp[i][k - curcost] + curprof, dp[i+1][k]);
      }
    }
    for (int k=0;k<=T;++k)dp[i+1][k] = max(dp[i+1][k], dp[i][k]);
    // for (int k=0;k<=T;++k)cout<<dp[i+1][k]<<' ';cout<<'\n';
  }
  cout << dp[M][T]<<'\n';
}
