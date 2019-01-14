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

vector<pi> adjList[1001001];
priority_queue<pi, vector<pi>, greater<pi> > pq;
int dist[1001001],mat[1101][1101];
int T,H,W;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};


int main(){
	//freopen("input.txt","r",stdin);
	cin >> T;
	while(T--){
		memset(mat,-1,sizeof(mat));
		for (int i = 0; i <= (H+1)*W; ++i)adjList[i].clear();
		cin >> H >> W;
		for (int i = 1; i <=H; ++i){
			for(int j =1; j <=W; ++j)cin>>mat[i][j];
		}
		if(H==1&&W==1){cout<<mat[1][1]<<'\n';continue;}
		for (int i = 1; i <=H; ++i){
			for(int j =1; j <=W; ++j){
				for (int k = 0; k < 4; ++k){
					int cx = i+dx[k],cy=j+dy[k];
					if(mat[cx][cy] == -1)continue;
					if(cx==1&&cy==1)continue;
					adjList[i*W+j].pb(mp(cx*W+cy,mat[cx][cy]));
				}
			}
		}
		int end = (H+1)*W;
		//cout << end << '\n';
		memset(dist, -1, sizeof(dist));
		while(pq.size())pq.pop();
		dist[W+1] = mat[1][1];
		pq.push(mp(mat[1][1], W+1));
		while (!pq.empty()) {
			pi cur = pq.top();
			pq.pop();
			int x = cur.s, d = cur.f;
			//cout << x << ' ' << d << '\n';
			if (d > dist[x]) continue;
			if(x == end){
				while(pq.size())pq.pop();
				break;
			}
			for (auto i : adjList[x]) {
				int nx = i.f, nd = d+i.s;
				if (dist[nx] != -1 && dist[nx] <= nd) continue;
				dist[nx] = nd;
				pq.push(mp(nd, nx));
			}
		}
		cout << dist[end] << '\n';
	}
}

