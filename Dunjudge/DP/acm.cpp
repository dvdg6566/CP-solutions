#include<bits/stdc++.h>
using namespace std;
int INF = 1e9;

int dp[150010][12];
int A[150010], B[150010], C[150010];
int N;

int main(){
  cin >> N;
  for (int i=0;i<N;++i)cin>>A[i];
  for (int i=0;i<N;++i)cin>>B[i];
  for (int i=0;i<N;++i)cin>>C[i];
  for (int i=0;i<N;++i)for (int j=0;j<12;++j)dp[i][j] = INF;
  dp[0][0] = A[0];
  dp[0][1] = B[0];
  dp[0][2] = C[0];
  for (int i=1;i<N;++i){
    dp[i][0] = dp[i-1][0] + A[i];
    dp[i][1] = dp[i-1][1] + B[i];
    dp[i][2] = dp[i-1][2] + C[i];
    dp[i][3] = min(dp[i-1][3], dp[i-1][0]) + B[i];
    dp[i][4] = min(dp[i-1][4], dp[i-1][0]) + C[i];
    dp[i][5] = min(dp[i-1][5], dp[i-1][1]) + A[i];
    dp[i][6] = min(dp[i-1][6], dp[i-1][1]) + C[i];
    dp[i][7] = min(dp[i-1][7], dp[i-1][2]) + A[i];
    dp[i][8] = min(dp[i-1][8], dp[i-1][2]) + B[i];
    dp[i][9] = min({dp[i-1][9], dp[i-1][3], dp[i-1][5]}) + C[i];
    dp[i][10] = min({dp[i-1][10], dp[i-1][4], dp[i-1][7]}) + B[i];
    dp[i][11] = min({dp[i-1][11], dp[i-1][6], dp[i-1][8]}) + A[i];
  }
  int ans = min({dp[N-1][9], dp[N-1][10], dp[N-1][11]});
  cout<<ans;
}
// 3 + 6 + 3

// A,B,C,AB,AC,BA,BC,CA,CB,__C,__B,__A