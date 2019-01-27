#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<int,pi> pii;
typedef vector<pi> vpi;
typedef double dl;
#define mp make_pair
#define pb push_back
#define f first
#define s second
int MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
int INF = 100000000000000000;
#define SZ(x) x.size()
#define Aint(x) x.begin(),x.end()

int A,B,N;
int M;
int dp[300100];

int __attribute__((optimize("03"),target("arch=sandybridge"))) main(){
  // freopen("input.txt","r",stdin);
  cin>>A>>B;
  N = A+B;
  while(1){
    ++M;
    N -= M;
    if (N<0)break;
  }
  --M;
  dp[0] = 1;
  B = M*(M+1)/2 - B;
  N = M*(M+1)/2;
  for (int i=1;i<=M;++i){
    int t = min(A,i*(i+1)/2);
    for (int j=t;j>=(B-(N-t))&&j>=i;--j){
      dp[j] += dp[j-i]; 
      dp[j] %= MOD;
    }
    // for (int j=0;j<=t&&j<=A;++j)cout<<dp[j]<<' ';cout<<'\n';
  }
  int ans = 0;
  for (int it=B; it <=A; ++it)ans = (ans + dp[it])%MOD;
  cout<<ans;
}