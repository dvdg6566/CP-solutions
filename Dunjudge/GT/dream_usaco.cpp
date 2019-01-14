#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef pair<pi,pi> pii;
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

int G[1010][1010],DP[1010][1010][2];
int M,N;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
priority_queue<pii, vector<pii>, greater<pii>> pq;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> M >> N;
	for (int i = 1; i <= M; ++i)for(int j = 1; j <= N; ++j)cin >> G[i][j];
	memset(DP,-1,sizeof(DP));
	pq.push(mp(mp(0,1),mp(1,0)));
	DP[1][1][0] = 0;
	while (pq.size()){
		pii c = pq.top(); pq.pop();
		for (int k = 0; k < 4; ++k){
			pii d = mp(mp(-1,c.f.s + dx[k]),mp(c.s.f + dy[k], c.s.s));
			if (d.f.s > M || d.f.s <= 0 || d.s.f > N || d.s.f <= 0)continue;
			if (G[d.f.s][d.s.f] == 0)continue; // Red tile: Impassable
			if (G[d.f.s][d.s.f] == 1){
				// Pink tile
				if(DP[d.f.s][d.s.f][d.s.s] != -1)continue;
				DP[d.f.s][d.s.f][d.s.s] = DP[c.f.s][c.s.f][c.s.s] + 1;
				d.f.f = DP[d.f.s][d.s.f][d.s.s];
				pq.push(d);
			}
			if (G[d.f.s][d.s.f] == 2){
				d.s.s = 1;
				if(DP[d.f.s][d.s.f][d.s.s] != -1)continue;
				DP[d.f.s][d.s.f][d.s.s] = DP[c.f.s][c.s.f][c.s.s] + 1;
				d.f.f = DP[d.f.s][d.s.f][d.s.s];
				pq.push(d);
			}
			if (G[d.f.s][d.s.f] == 3){
				// Only if smell like oranges
				if (!d.s.s)continue;
				if(DP[d.f.s][d.s.f][d.s.s] != -1)continue;
				DP[d.f.s][d.s.f][d.s.s] = DP[c.f.s][c.s.f][c.s.s] + 1;
				d.f.f = DP[d.f.s][d.s.f][d.s.s];
				pq.push(d);
			}
			if (G[d.f.s][d.s.f] == 4){
				d.s.s = 0; // Purple removes colour
				int T = 1;
				while(1){
					++T;
					d.f.s = d.f.s + dx[k];
					d.s.f = d.s.f + dy[k];
					if (d.f.s > M || d.f.s <= 0 || d.s.f > N || d.s.f <= 0){
						d.f.s -= dx[k];
						d.s.f -= dy[k];
						if(DP[d.f.s][d.s.f][d.s.s] != -1)break;
						DP[d.f.s][d.s.f][d.s.s] = DP[c.f.s][c.s.f][c.s.s] + T - 1;
						d.f.f = DP[d.f.s][d.s.f][d.s.s];
						pq.push(d);
						break;
					}
					if(G[d.f.s][d.s.f] == 4)continue;
					if (G[d.f.s][d.s.f] == 0 || G[d.f.s][d.s.f] == 3){
						// Blocked at previous
						d.f.s -= dx[k];
						d.s.f -= dy[k];
						--T;
					}
					if(DP[d.f.s][d.s.f][d.s.s] != -1)break;
					DP[d.f.s][d.s.f][d.s.s] = DP[c.f.s][c.s.f][c.s.s] + T;
					d.f.f = DP[d.f.s][d.s.f][d.s.s];
					pq.push(d);
					break;
				}
			}
		}
	}
	//cout << DP[M][N][0] << ' ' << DP[M][N][1] << '\n';
	if (DP[M][N][0] == -1 && DP[M][N][1] == -1){cout << -1; return 0;}
	if (DP[M][N][0] == -1 && DP[M][N][1] != -1){cout << DP[M][N][1]; return 0;}
	if (DP[M][N][0] != -1 && DP[M][N][1] == -1){cout << DP[M][N][0]; return 0;}
	if (DP[M][N][0] != -1 && DP[M][N][1] != -1){cout << min(DP[M][N][0],DP[M][N][1]); return 0;}
}
