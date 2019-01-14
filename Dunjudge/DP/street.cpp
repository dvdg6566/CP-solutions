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

int N,K,T;
int H[510];
int DP[510][510];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> N >> K >> T;
	for(int i = 1; i <= N; ++i)cin >> H[i];
	for (int i = 1; i <= N; ++i){
		for (int j = 1; j <= K; ++j){
			DP[i][j] = max(DP[i-1][j],DP[i][j-1]);
			int RMQ = INF;
			for (int k = i; k > max(i-T,0); --k){
				RMQ = min(RMQ,H[k]);
				DP[i][j] = max(DP[i][j], DP[k-1][j-1] + RMQ * (i+1-k));
			}
			res = max(res,DP[i][j]);
		}
	}
	cout << res;
}
