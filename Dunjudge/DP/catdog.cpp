#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef double dl;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MOD 1000000007LL
#define lb lower_bound
#define ub upper_bound
#define dst distance
#define INF 1000000000

int R,C;
bool G[2010][2010];
string S;
ll DP[2010][2010];

ll perm(pi a, pi b){
	memset(DP,0,sizeof(DP));
	DP[a.f][a.s] = 1;
	for (int i = a.f; i <= b.f; ++i){
		for (int j = a.s; j <= b.s; ++j){
			if(G[i][j])continue;
			if(i==a.f&&j==a.s)continue;
			DP[i][j] = DP[i-1][j] + DP[i][j-1];
			DP[i][j] %= MOD;
		}
	}
	return DP[b.f][b.s];
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> R >> C;
	for (int i = 1; i <= R; ++i){
		cin >> S;
		for (int j = 1; j <= C; ++j){
			G[i][j] = (S[j-1] == '#');
		}
	}
	ll DR = perm(mp(2,1),mp(R,C-1));
	ll RD = perm(mp(1,2),mp(R-1,C));
	
	ll DD = perm(mp(2,1),mp(R-1,C));
	ll RR = perm(mp(1,2),mp(R,C-1));
	//cout << DR << ' ' << RD << ' ' << DD << ' ' << RR << '\n';
	ll ans = 2*(DR*RD%MOD) - 2*(DD*RR%MOD);
	ans %= MOD;
	if(ans < 0)ans += MOD;
	cout << ans;
}
