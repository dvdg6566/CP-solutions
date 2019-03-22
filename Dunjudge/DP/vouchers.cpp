#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[5010][2];
ll N, A[5010], a, ans;

int main() {
    cin>>N;
    for (int i=1;i<=N;++i)cin>>A[i];
    for (int i=0;i<=N;++i)dp[i][0] = dp[i][1] = 1e9;
    ans = 1e9;
    dp[0][0] = 0;
    for (int i=1;i<=N;++i){
        cin >> a;
        ++a;
        //cout<<a<<' '<<A[i]<<'\n';
        for (int j=0;j<N;++j){
            //if (i == 2)cout<<j<<' '<<a+j<<' '<<dp[j][1-i%2]+A[i]<<'\n';
            dp[j][i%2] = min(dp[j][i%2], dp[j][1-i%2]);
            if (a+j >= N)ans = min(ans, A[i] + dp[j][1-i%2]);
            else {
              dp[a+j][i%2] = min(dp[a+j][i%2], dp[j][1-i%2] + A[i]);
            }
        }
        //for (int j=0;j<=N;++j)cout<<j<<' '<<dp[j][0]<<' ';cout<<'\n';
        //for (int j=0;j<=N;++j)cout<<dp[j][1]<<' ';cout<<'\n';
    }
    cout<<ans<<'\n';
}