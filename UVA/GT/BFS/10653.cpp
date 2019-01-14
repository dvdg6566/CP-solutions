#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pi;
typedef long long ll;
typedef vector<pi> vpi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define s second
#define f first

int grid[1010][1010];

int a,b,c,d,H,W;
queue<pi> pq;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int main(){
	//freopen("input.txt","r",stdin);
	while(1){
		cin >> H >> W;
		if(H==0&&W==0)return 0;
		memset(grid,0,sizeof(grid));
		cin >> a;
		while(a--){
			cin >> b >> c;
			while(c--){
				cin >> d;
				grid[b][d] = -1;
			}
		}
		cin >> a >> b >> c >> d;
		pq.push(mp(a,b));
		grid[a][b] = 1;
		while(pq.size()){
			int cx = pq.front().f, cy = pq.front().s;
			pq.pop();
			for (int i = 0; i < 4; ++i){
				int nx = cx+dx[i], ny = cy+dy[i];
				if(nx==-1||nx>=H)continue;
				if(ny==-1||ny>=W)continue;
				if(grid[nx][ny]!=0)continue;
				if(nx==c&&ny==d){
					grid[nx][ny] = grid[cx][cy]+1;
					while(pq.size())pq.pop();
					break;
				}
				pq.push(mp(nx,ny));
				grid[nx][ny] = grid[cx][cy]+1;
			}
		}
		cout << grid[c][d]-1 << '\n';
	}
}
