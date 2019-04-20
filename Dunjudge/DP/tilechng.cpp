#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<int,pi> pii;
typedef vector<pi> vpi;
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

int N, tar, a, cur, T;
vi V;
int dp[111000][2];

int main(){
  // freopen("in.txt","r",stdin);
  cin >> N >> tar;
  for (int i=0;i<N;++i){
    cin >> a;
    V.pb(a);
    cur += a*a;
  }
  T = cur - tar; 
  // cout<<T<<'\n';
  for (int k=0;k<=110000;++k)dp[k][0] = dp[k][1] = INF;
  dp[10000][0] = dp[10000][1] = 0;

  for (int i=0;i<N;++i){
    int c = V[i];
    for (int j=c;j>=0;--j){
      int cost = (c-j)*(c-j);
      int save = c*c - j*j;
      // cout<<"Knapsack 1 with " << cost<<' '<<save<<'\n';
      for (int k=save; k<=100000;++k){
        dp[k+10000][i%2] = min(dp[k+10000][i%2], dp[k-save+10000][1-i%2] + cost);
        // if (dp[k+10000][i%2] != INF)cout<<k<<' '<<dp[k+10000][i%2]<<'\n';
      }
    }
    for (int j=1+c;j<=100 && j*j <= tar;++j){
      int cost = (c-j)*(c-j);
      int save = j*j - c*c;
      // cout<<"Knapsack 2 with " << cost << ' ' << save << '\n';
      for (int k=100000-save; k>=save-10000;--k){
        // if (dp[k+save+10000][1-i%2] + cost < dp[k+10000][i%2]){
          // cout<<k<<' ';
        // }
        dp[k+10000][i%2] = min(dp[k+10000][i%2], dp[k+save+10000][1-i%2] + cost);
        // if (dp[k+10000][i%2] != INF)cout<<k<<' ';
      }
      // cout<<'\n';
    }

  }
  // for (int i=0;i<110000;++i)if (dp[i][1-N%2] != INF)cout<<i-10000<<' ';cout<<'\n';
  if (dp[T+10000][1-N%2] == INF){
    cout<<-1;
    return 0;
  }
  cout<<dp[T+10000][1-N%2];
}
