#include<bits/stdc++.h>
using namespace std;
long dp[10001],v[5001],w[5001];
long n,q,a,b,ans,mw;

int main(){
	//freopen("input.cpp","r",stdin);
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n;
    for (long i = 1; i <= n; ++i)cin >> w[i] >> v[i];
    cin >> q;
    for (long i= 0; i < q; ++i){
      cin >> a >> b >> mw;
      ans = 0;
      for (long j = a; j <= b; ++j){
		  for (long k = mw; k >= w[j]; --k){
				dp[k] = max(dp[k],v[j] + dp[k-w[j]]);
		  }
	  }
	  for (long i = 1; i <= mw; ++i){
	       ans = max(ans,dp[i]);
	      dp[i] = 0;
	  }
	  cout << ans << '\n';
    }
}
