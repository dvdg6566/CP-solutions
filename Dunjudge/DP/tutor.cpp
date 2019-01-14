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
#define MOD 1e9+7
#define lb lower_bound
#define ub upper_bound
#define dst distance
#define INF 1000000000

int T,L,P,ans;
int books[4];
int memo[1001][21][5];

int main(){
	ios_base::sync_with_stdio(0);
	//freopen("input.txt","r",stdin);
	cin >> T >> L >> P;
	for (int i = 0; i < 4; ++i)cin >> books[i];
	memset(memo,-1,sizeof(memo));
	memo[0][0][0] = 0;
	for (int i = 0; i <= T; ++i){
		for (int j = 0; j <= 20; ++j){
			for (int k = 0; k <= 4; ++k){
				//cout << memo[i][j][k] << ' ';
				if (memo[i][j][k] == -1)continue;
				ans = max(ans,memo[i][j][k]);
				if (i+2 <= T){ // Teach
					memo[i+2][j][k] = max(memo[i+2][j][k], memo[i][j][k] + 10 + j*P);
				}
				if (k != 4 && memo[i][j][k] >= books[k] && i + k <= T){ // buy
					memo[i+k][j][k+1] = max(memo[i+k][j][k+1], memo[i][j][k] - books[k]);
				}
				int time = max(1, (int) ((double) 8 / (double)max(1,k * L)));
				if (i+time <= T && memo[i][j][k] >= 20 && j != 20){ // Train
					memo[i+time][j+1][k] = max(memo[i+time][j+1][k], memo[i][j][k]-20);
				}
			}
			//cout << '\n';
		}
		//cout << '\n';
		//cout << '\n';
	}
	
	cout << ans;
}
