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

int N,K;
string S;

int pre[510][510],DP[510][510];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> N >> K >> S;
	S = ";" + S;
	for (int i = 1; i <= N; ++i)for (int j = 1; j <= N; ++j){pre[i][j] = -1;}
	for (int i = 0; i <= N; ++i)for (int j = 0; j <= K; ++j){DP[i][j] = INF;}
	for (int i = 0; i <= N; ++i)pre[i][i] = 0;	
	for (int k = 1; k <= N; ++k){
	  for (int i = 1; i+k <= N; ++i){
	    // From i to i+k (inclusive)
	    if(k==1)pre[i][i+k] = !(S[i] == S[i+k]);
	    else pre[i][i+k] = pre[i+1][i+k-1] + !(S[i] == S[i+k]);
	  }
	}
	//for (int i = 1; i <= N; ++i){for (int j = 1; j <= N; ++j)cout << pre[i][j] << ' ';cout << '\n';}
	DP[0][0] = 0;
	for (int i = 1; i <= N; ++i){
		for (int j = 1; j <= K; ++j){
			DP[i][j] = DP[i][j-1];
			for (int k = 0; k < i; ++k){
				if(DP[k][j-1] == INF)continue;
				DP[i][j] = min(DP[i][j],DP[k][j-1] + pre[k+1][i]);
			}
			DP[i][j] = min(DP[i][j],pre[1][i]);
		}
	}
	/*
	for (int i = 1; i <= N; ++i){
		for (int j = 1; j <= K; ++j){
			cout << DP[i][j] << ' ';
		}cout << '\n';
	}
	* */
	int ans = INF;
	for (int i = 1; i <= K; ++i)ans = min(ans,DP[N][i]);
	cout << ans;
}
