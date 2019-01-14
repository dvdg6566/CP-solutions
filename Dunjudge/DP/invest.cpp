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

int N,DP[1010][1010][5];
int D[1010][5];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> N;
	for (int i = 1; i <= N+1; ++i){
		for (int j = 0; j < 5; ++j){
			cin >> D[i][j];
		}
	}
	for (int i = 1; i <= N; ++i){
		for (int j = 0; j < 5; ++j){
			D[i][j] = 2520/D[i][j]*D[N+1][j];
		}
	}
	memset(DP,-1,sizeof(DP));
	DP[0][0][0] = DP[0][0][1] = DP[0][0][2] = DP[0][0][3] = DP[0][0][4] = 0;
	for (int i = 0; i <= N; ++i){
		for (int j = 0; j <= i; ++j){
			for (int k = 0; k < 5; ++k){
				if(DP[i][j][k] == -1)continue;
				DP[i+1][j+1][k] = max(DP[i+1][j+1][k],DP[i][j][k] + D[i+1][k]); // Not changing
				if (j >= 15){
					for (int l = 0; l < 5; ++l){
						if(l==k)continue;
						DP[i+1][1][l] = max(DP[i+1][1][l], DP[i][j][k] + D[i+1][l]);
					}
				}
			}
		}
	}
	int R = 0;
	for (int j = 0; j <= N; ++j)for(int k = 0; k < 5; ++k) R = max(R,DP[N][j][k]);
	cout << R;
}
