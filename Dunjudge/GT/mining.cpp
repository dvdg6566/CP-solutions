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

int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};
pi cr,e;
int dp[310][310][140], m[300][300];
string s;
int R,C,K;

struct edge {
    int a, b, h;
    edge (int _a=0, int _b=0, int _h=0): a(_a), b(_b), h(_h){}
};
queue<edge>q;

void bfs(int a, int b, int c){
	while(q.size())q.pop();
	q.push({a,b,c});
	while(q.size()){
		edge cur = q.front();
		int x = cur.a,y = cur.b, z=cur.h;
		assert(dp[x][y][z] < C*R);
		q.pop();
		for (int k = 0; k < 4; k++){
			int cx = x+dx[k], cy = y + dy[k], cz=z;
			if(cx>=R||cy>=C||cx<0||cy<0)continue;
			if(m[cx][cy] == -1)continue;
			if (m[cx][cy] == 1)cz++;
			if (cz>K)continue;
			if(dp[cx][cy][cz] != -1)continue;
			dp[cx][cy][cz] = dp[x][y][z] + 1;
			q.push({cx,cy,cz});
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin>>R>>C>>K;
	for (int i = 0; i < R; ++i){
		cin >> s;
		for (int j = 0; j < C; ++j){
			if (s[j] == 'B')m[i][j] = -1;
			if (s[j] == 'W')m[i][j] = 1;
			if (s[j] == '.')m[i][j] = 0;
			if (s[j] == 'E'){m[i][j] = -3;e = mp(i,j);}
			if (s[j] == 'S'){m[i][j] = -2; cr = mp(i,j);}
		}
	}
	memset(dp,-1,sizeof(dp));
	dp[cr.f][cr.s][0] = 0;
	bfs(cr.f, cr.s, 0);
	int ans = INT_MAX;
	for (int i = 0; i <= K; ++i){
		if(dp[e.f][e.s][i]<0)continue;
		ans = min(ans,dp[e.f][e.s][i]);
	}
	if (ans == INT_MAX)cout << -1;
	else cout << ans;}
