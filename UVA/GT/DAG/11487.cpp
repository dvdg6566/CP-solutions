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
#define MOD 20437
#define lb lower_bound
#define ub upper_bound
#define dst distance
#define INF 1000000000

int N,cntr=1;
string st;
vpi V;
int grid[12][12];
int distances[30][30], SP[12][12], rep[12][12], repDP[30][30];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
queue<pi> Q;

void bfs(int x, int y, int index){
	memset(SP,-1,sizeof(SP));
	memset(rep,-1,sizeof(rep));
	SP[x][y] = 0;
	rep[x][y] = 1;
	Q.push(mp(x,y));
	while(Q.size()){
		int px = Q.front().f, py = Q.front().s;
		//cout << "VISITING: " << px << ' ' << py << '\n';
		Q.pop();
		for (int k = 0; k < 4; ++k){
			int cx = px+dx[k], cy = py+dy[k];
			if(cx>=N||cx<0||cy>=N||cy<0)continue;
			if(SP[cx][cy] == SP[px][py]+1){
				rep[cx][cy]+=rep[px][py];
				rep[cx][cy] %= MOD;
				continue;
			}
			if(SP[cx][cy]!=-1)continue;
			if(grid[cx][cy] == -1)continue;
			if(index+1 < grid[cx][cy])continue;
			SP[cx][cy] = SP[px][py] + 1;
			rep[cx][cy] = rep[px][py];
			Q.push(mp(cx,cy));
			//cout << "PUSHING " << cx << ' ' << cy << '\n';
		}
	}
	for (int i = 0; i < V.size(); ++i){
		//cout << SP[V[i].f][V[i].s] << ' ';
		distances[index][i] = SP[V[i].f][V[i].s];
		repDP[index][i] = rep[V[i].f][V[i].s];
	}
	//cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	while(cntr++){
		cin >> N;
		if(N==0)return 0;
		memset(repDP,0,sizeof(repDP));
		memset(distances,0,sizeof(distances));
		V.clear();
		for (int i = 0; i < 26; ++i){V.pb(mp(-1,-1));}
		memset(distances,0,sizeof(distances));
		for (int i = 0; i < N; ++i){
			cin >> st;
			for (int j = 0; j < N; ++j){
				if (st[j] == '.')grid[i][j] = 0;
				else if (st[j] == '#')grid[i][j] = -1;
				else{
					V[st[j] - 'A'] = mp(i,j);
					grid[i][j] = (st[j] - 'A');
				}
			}
		}
		while(V.back().f==-1)V.pop_back();
		for (int i = 0; i < V.size(); ++i){
			bfs(V[i].f, V[i].s, i);
		}
		int res = 0;
		ll paths = 1;
		for (int i = 0; i < V.size()-1; ++i){
			int a = distances[i][i+1];
			if(a == -1){
				res = -1;
				break;
			}else{
				//cout << repDP[i][i+1] << '\n';
				paths *= repDP[i][i+1];
				paths = paths%MOD;
				res += a;
			}
		}
		if (res == -1)cout << "Case " << cntr-1 << ": Impossible\n";
		else cout << "Case " << cntr-1 << ": " << res << ' ' << paths << '\n';
	}
}
