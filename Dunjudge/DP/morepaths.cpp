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

ll N,M,K;
ll dp[501][501];
ll req[501][501];
ll G[501][501];
priority_queue<ll,vector<ll>, greater<ll>> S[501][501];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> N >> M >> K;
	for (int i = 0; i < N; ++i)for(int j = 0; j < M; ++j)cin >> G[i][j];
	dp[N-1][M-1] = 1;
	for (int i = N-1; i >= 0; --i){
		for (int j = M-1; j >= 0; --j){
			if (i+1==N&&j+1==M)continue;
			dp[i][j] = dp[i][j+1] + dp[i+1][j];
			if (dp[i][j] > K)dp[i][j] = K;
		}
	}
	for (int i = 0; i < N; ++i)for (int j = 0; j < M; ++j){
    req[i][j] = K/dp[i][j];
    if (K%dp[i][j])++req[i][j];
  }
	 for (int i = 0; i < N; ++i){for (int j = 0; j < M; ++j)cout << req[i][j] << ' ';cout << '\n';}
  S[0][0].push(G[0][0]);
  for (int i = 0; i < N; ++i){	
    for (int j = 0; j < M; ++j){
      if (i+1==N&&j+1==M)continue;
      //cout << S[i][j].top() << ' ';
      while(S[i][j].size()){
        ll c = S[i][j].top();
        S[i][j].pop();
        S[i+1][j].push(c+G[i+1][j]);
        S[i][j+1].push(c+G[i][j+1]);
        if (S[i+1][j].size() > K)S[i+1][j].pop();
        if (S[i][j+1].size() > K)S[i][j+1].pop();
      }  
    }
    //cout << '\n';
  }
  cout << S[N-1][M-1].top();
  return 0;
  for (int i = 0; i < N; ++i){
    for (int j = 0; j < M; ++j){
      if (!S[i][j].size()){
        cout << -1 << ' ';
      }else cout << S[i][j].top() << ' ';
    }
    cout << '\n';
  }
}
