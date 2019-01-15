#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
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

ll dp[5010],dp2[5010];
ll N,D,x,s,a,b;


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
  // freopen("input.txt","r",stdin);
	cin >> N >> D;
	for (int i=0;i<N;++i){
		cin >> x >> s >> a >> b;
		if (a + b == 0){
			for (int j=0;j<=D;++j)dp[j] = dp2[j] = dp[j] + x*s;
			continue;
		}
		--s;
		for (int j=D;j>=a;--j)dp[j] = dp[j - a] + x;
    for (int j=a-1;j>=0;--j)dp[j] = -INF;
		if (b == 0){
			for (int j=0;j<=D;++j){
				dp[j] = dp2[j] = max(dp2[j], dp[j] + x*s);
			}
			continue;
		}
		s = min(s, D/b + 1);
		int t = 0;
		for (int it = 1; it+t <= s; it *= 2){
      // cout << it << '\n';
			t += it;
			for (int j=D;j>=it*b;--j)dp[j] = max(dp[j], dp[j-it*b] + x*it);
		}
		t = s - t;
    // cout << t << '\n';
		for (int j=D;j>=t*b;--j)dp[j] = max(dp[j], dp[j-t*b] + x*t);
		for (int it=0;it<=D;++it){
			dp2[it] = dp[it] = max(dp2[it], dp[it]);
		}
	}
	cout << *max_element(dp,dp+D+1);
}
