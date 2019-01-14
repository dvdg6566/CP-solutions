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
int N,E,a,b,c,d,x,y,z,T;
priority_queue<pi, vector<pi>, greater<pi> > pq;
int dist[110];

int main(){
	//freopen("input.txt","r",stdin);
	cin>>T;
	while(T--){
		cin >> N >> E;
		
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
			cin >> a >> b >> c >> d;
			c = c*1000+d;
			adjMat[a][b]=min(c,adjMat[a][b]);
			adjMat[b][a]=min(c,adjMat[b][a]);
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
		
		cin>>E;
		while(E--){
			cin >> a >> b;
			if(adjMat[a][b]!=INF)cout << "Distance and time to reach destination is " << adjMat[a][b]%1000 << " & " << adjMat[a][b]/1000 <<'.' << '\n';
			else cout << "No Path.\n";
		}
		if(T)cout << '\n';
	}
}

