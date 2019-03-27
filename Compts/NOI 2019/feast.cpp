#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<ll> vi;
typedef vector<pi> vpi;

#define pb push_back
#define mp make_pair
#define f first 
#define s second
#define SZ(x) x.size()
#define ALL(x) x.begin(), x.end()
#define lb lower_bound
#define ub upper_bound

ll A[300010], m,ans,N,K,cnt,ss;

int main(){
	//freopen("in.2.txt","r",stdin);
	cin>>N>>K;
	for (int i=1;i<=N;++i){
		cin >> A[i];
		if (A[i] < 0)cnt++;
	}
	if (cnt == 0 || (cnt == 1 && K >= 2) ){
		for (int i=1;i<=N;++i)ss += max(0LL,A[i]);
		cout<<ss;
		return 0;
	}
	if (cnt == 1){
		ll left=0, right=0, tot=0;
		for (int i=1;i<=N;++i){
			if (A[i] < 0)break;
			left += A[i];
		}
		for (int i=N;i>=1;--i){
			if (A[i] < 0)break;
			right += A[i];
		}
		for (int i=1;i<=N;++i)tot += A[i];
		cout<<max({left, right, tot});
		return 0;
	}
	if (K == 1){
		ll ans = 0, cur = 0;
		for (int i=1;i<=N;++i){
			cur += A[i];
			if (cur < 0)cur = 0;
			ans = max(ans, cur);
		}
		cout<<ans;
		return 0;
	}
	for (int i=1;i<=N;++i)A[i] += A[i-1];
	ll dp[2][2010];
	memset(dp, 0, sizeof(dp));
	for (int i=1;i<=K;++i){
		m = 0;
		for (int j=1;j<=N;++j){
			m = max(m,dp[1-i%2][j] - A[j]);
			//cout<<"Add "<<dp[1-i%2][j] - A[j]<<'\n';
			dp[i%2][j] = max(dp[i%2][j-1], m + A[j]);
			//cout<<dp[i%2][j]<<'\n';
			ans = max(dp[i%2][j], ans);
		}
		//cout<<'\n';
	}
	cout<<ans;
}
