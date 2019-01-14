#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef vector<ll> vi;
typedef pair<pi,pi> pii;
typedef pair<int,pi> ii;
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define INF 100000000

vector<pi> adjList[110];
int adjMat[110][110],S[110];
int N,E,a,b,c,d,x,y,z;
priority_queue<pi, vector<pi>, greater<pi> > pq;
int dist[110];

int main(){
	//freopen("input.txt","r",stdin);
	while(1){
		cin >> N;
		if(cin.eof())return 0;
		cin >> E >> a >> b >> c >> d;
		for(int i=1;i<=N;++i){
			adjList[i].clear();
			dist[i]=-1;
			S[i]=0;
			for(int j = 1;j<=N;++j){
				adjMat[i][j]=INF;
				if(i==j)adjMat[i][i]=0;
			}
		}
		
		while(E--){
			cin >> x >> y >> z;
			adjList[x].pb(mp(y,z));
			adjList[y].pb(mp(x,z));
			adjMat[x][y]=z;
			adjMat[y][x]=z;
		}
		
		for (int k = 1; k <= N; ++k) {
			for (int i = 1; i <= N; ++i) {
				for (int j = 1; j <= N; ++j) {
					if (adjMat[i][k] == -1 || adjMat[k][j] == -1) continue;
					if (adjMat[i][j] == -1 || adjMat[i][j] > adjMat[i][k] + adjMat[k][j]) 
						adjMat[i][j] = adjMat[i][k] + adjMat[k][j];
				}
			}
		}
		
		for (int i = 1; i <= N; ++i){
			if(adjMat[a][b] == adjMat[a][i] + adjMat[i][b]){
				S[i]=1;
			}
		}
		
		dist[c]=0;
		while(pq.size())pq.pop();
		if(!S[c])pq.push(mp(0,c));
		while (!pq.empty()) {
			pi cur = pq.top();
			pq.pop();
			int x = cur.s, d = cur.f;
			if (d > dist[x]) continue;
			for (auto it:adjList[x]){
				if(S[it.f]){continue;}
				int nx = it.f, nd = d+it.s;
				if (dist[nx] != -1 && dist[nx] <= nd) continue;
				dist[nx] = nd;
				pq.push(mp(nd, nx));
			}
		}
		if(dist[d] == -1||S[d]||S[c])cout << "MISSION IMPOSSIBLE.\n";
		else cout << dist[d] << '\n';
	}
}
