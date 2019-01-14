#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MOD 1e9+7
#define lb lower_bound
#define ub upper_bound
#define dst distance
#define INF 10000

int DP[100][100][10][3],G[100][100];
int N,K,cntr;
int dx[] = {0,0,1};
int dy[] = {1,-1,0};

int query(int a, int b, int c, int d){
	if (DP[a][b][c][d] != INT_MIN)return DP[a][b][c][d];
	int res = -INF;
	int e = c;
	if(G[a][b] < 0)e--;
	if (e < 0){
		DP[a][b][c][d] = -INF;
		return -INF;
	}
	int cx = a - dx[d], cy = b - dy[d];
	if(cx<0||cy<0||cx>=N||cy>=N){DP[a][b][c][d] = -INF; return -INF;} // Out of grid
	for (int l = 0; l < 3; ++l){
		if (d + l == 1)continue; // Repeated
		int x = query(cx,cy,e,l);
		if (x == -INF)continue;
		res = max(res,x+G[a][b]);
	}
	DP[a][b][c][d] = res;
	return res;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	while(1){
		cntr++;
		cin >> N >> K;
		if (N==0&&K==0)return 0;
		for (int i = 0; i < N; ++i){
			for (int j =0; j < N; ++j){
				cin >> G[i][j];
			}
		}
		for (int i = 0; i < N; ++i){
			for (int j = 0; j < N; ++j){
				for (int k = 0; k <= K; ++k){
					for (int l = 0; l < 3; ++l){
						DP[i][j][k][l] = INT_MIN;
					}
				}
			}
		}
		for (int k = (G[0][0] < 0); k <= K; ++k){
			DP[0][0][k][0] = G[0][0];
			DP[0][0][k][1] = G[0][0];
			DP[0][0][k][2] = G[0][0];
		}
		int res = max({query(N-1,N-1,K,0),query(N-1,N-1,K,1),query(N-1,N-1,K,2)});
		if(res == -INF){cout << "Case " << cntr << ": impossible\n";}
		else cout << "Case " << cntr << ": " <<  res << '\n';
	}
}
