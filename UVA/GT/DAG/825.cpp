#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
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
#define INF 1000000000

int H,W,T,a,b,grid[800][800],dp[800][800];
string st;
stringstream ss;
int dx[] = {1,0} , dy[] = {0,1};

int main(){
	//freopen("input.txt","r",stdin);
	cin >> T;
	while(T--){
		memset(dp,0,sizeof(dp));
		memset(grid,0,sizeof(grid));
		cin >> H >> W;
		cin.ignore();
		for (int i = 0; i < H; ++i){
			cin >> a;
			getline(cin,st);
			if(st.size() == 0)continue;
			int x = 0;
			//st = st.substr(1,st.size()-1);
			for(auto it : st)x += (it == ' ');
			ss.clear();
			ss << st;
			for (int j = 0; j < x; ++j){
				ss >> b;
				grid[i][b-1] = 1;
			}
		}
		dp[0][0] = 1;
		for (int i = 0; i < H; ++i){
			for (int j = 0; j < W; ++j){
				if(grid[i][j])dp[i][j] = 0;
				if(!dp[i][j])continue;
				for (int k = 0; k < 2; ++k){
					int tx = i + dx[k], ty = j + dy[k];
					if(tx==H||ty==W)continue;
					dp[tx][ty] += dp[i][j];
				}
			}
		}
		cout << dp[H-1][W-1] << "\n\n";
	}
}
