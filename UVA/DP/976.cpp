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

int grid[1010][1010],dist[1010];
int dp[110][1010];
int R,C,B,S;
string st;
int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};

void bfs(pi x){
	queue<pi> Q;
	Q.push(x);
	while(Q.size()){
		pi cur = Q.front();
		Q.pop();
		for (int i = 0; i < 4; ++i){
			int cx = dx[i] + cur.f;
			int cy = dy[i] + cur.s;
			if(cx<0||cx>=R)continue;
			if(cy<0||cy>=C)continue;
			if(grid[cx][cy] == 1){
				grid[cx][cy] = 2;
				Q.push(mp(cx,cy));
			}
		}
	}
}

int query(int col, int L){
	if(L==0)return 0;
	if(col+(S+1)*(L-1)>=C)return -1;
	if(dp[L][col] != 0)return dp[L][col];
	int res = INF;
	int t = query(col+1,L);
	if(t!=-1)res = min(res,t); //Case one where there is no bridge
	t = dist[col] + query(col+S+1,L-1); // Case 2 where there is a bridge
	if(t!=-1)res = min(res,t);
	dp[L][col] = res;
	if(res==INF)res=-1;
	return res;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	while(cin>>R){
		if(cin.eof())return 0;
		cin >> C >> B >> S;
		memset(grid,0,sizeof(grid));
		for (int i = 0; i < R; ++i){
			cin >> st;
			for (int j = 0; j < C; ++j){
				if(st[j] == '#')grid[i][j] = 1;
			}
		}
		bfs(mp(0,0));
		for (int i = 0; i < C; ++i){
			int lowt = 0;
			int highl = INF;
			for (int j = 0; j < R; ++j){
				if(grid[j][i] == 1)highl = min(highl,j);
				if(grid[j][i] == 2)lowt = max(lowt,j);
			}
			dist[i] = highl - lowt - 1;
		}
		//for (int i = 0; i < C; ++i)cout << dist[i] << ' ';cout << '\n';
		cout  << query(0,B) << '\n';
		memset(dp,0,sizeof(dp));
	}
}
