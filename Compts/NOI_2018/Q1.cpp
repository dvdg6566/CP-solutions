#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pi;
#define f first
#define s second
#define mp make_pair
ll a,b,R,C,D,Q;
string s;
stack<pi> gay;

int main(){
	cin >> R >> C >> D >> Q;
	ll dp[R+20][C+20];
	memset(dp,0,sizeof(dp));
	for (int i = 1; i <= R; ++i){
		cin >> s;
		for (int j = 1; j <= C; ++j){
			if (s[j-1] == 'S')dp[i][j] = 1;
			if(s[j-1] == 'M')gay.push(mp(i,j));
		}
	}
	
	for (int i = 1; i <= R; ++i){
		for (int j = 1; j <= C; ++j){
			dp[i][j] += (dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1]);
		}
	}
	
	ll ans = 0;
	while(gay.size()){
		ll x = gay.top().f, y = gay.top().s;
		gay.pop();
		ll xh = min(R,x+D), yh = min(C,y+D), xm = max(1LL,x-D), ym = max(1LL,y-D);
		ll area = dp[xh][yh] - dp[xm-1][yh] - dp[xh][ym-1] + dp[xm-1][ym-1];
		if (area >= Q)ans++;
	}
	cout << ans;
}