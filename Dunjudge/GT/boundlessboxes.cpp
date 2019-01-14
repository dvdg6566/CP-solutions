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

int adjMat[1100][1100];
queue<pi> q;
set<int> X;
int N,M,S,a,b;
int dx[] = {1,-1,0,0,1,-1,1,-1}, dy[] = {0,0,-1,1,1,1,-1,-1};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> N >> M >> S;
	memset(adjMat,-1,sizeof(adjMat));
	while(S--){
		cin >> a >> b;
		q.push(mp(a-1,b-1));
		adjMat[a-1][b-1] = 0;
	}
	while (!q.empty()){
		pi c = q.front();
		int x = c.first,y = c.second;
		q.pop();
		for (int k = 0; k < 8; k++){
			int cx = x+dx[k], cy = y + dy[k];
			if (cx < N && cy < M && cx > -1 && cy > -1){
				if (adjMat[cx][cy] != -1)continue;
				adjMat[cx][cy] = adjMat[x][y] + 1;
				q.push(mp(cx,cy));
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < N; ++i){for (int j = 0; j < M; ++j){
		if (adjMat[i][j] == -1)continue;
		if (X.lb(adjMat[i][j]) != X.ub(adjMat[i][j]))continue;
		else X.insert(adjMat[i][j]);
		ans ++;
	}}
	cout << ans;
}
