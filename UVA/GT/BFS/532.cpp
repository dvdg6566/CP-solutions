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

int grid[50][50][50];

int a,b,c,d,e,f,L,H,W;
string st;

struct node {
    int x,y,z;
    node (int _x=0, int _y=0, int _z=0): x(_x), y(_y), z(_z) {}
};
 

int dx[] = {1,-1,0,0,0,0};
int dy[] = {0,0,1,-1,0,0};
int dz[] = {0,0,0,0,1,-1};
queue<node> pq;

int main(){
	//freopen("input.txt","r",stdin);
	while(1){
		cin >> L >> H >> W;
		if(L==0&H==0&&W==0)return 0;
		memset(grid,0,sizeof(grid));
		for(int i = 0; i < L; ++i){
			for(int j = 0; j < H; ++j){
				cin >> st;
				for (int k = 0; k < W; ++k){
					if(st[k]=='.')continue;
					if(st[k]=='S'){a=i;b=j;c=k;}
					if(st[k]=='E'){d=i;e=j;f=k;}
					if(st[k]=='#')grid[i][j][k]=-1;
				}
			}
		}
		pq.push({a,b,c});
		grid[a][b][c] = 1;
		//cout << a << ' ' << b << ' ' << c << '\n';
		while(pq.size()){
			int cx = pq.front().x, cy = pq.front().y, cz = pq.front().z;
			//cout << cx << ' ' << cy << ' ' << cz << ' ' << grid[cx][cy][cz]<< '\n';
			pq.pop();
			for (int i = 0; i < 6; ++i){
				int nx = cx+dx[i], ny = cy+dy[i], nz=cz+dz[i];
				if(nx==-1||nx>=L)continue;
				if(ny==-1||ny>=H)continue;
				if(nz==-1||nz>=W)continue;
				if(grid[nx][ny][nz]!=0)continue;
				if(nx==d&&ny==e&&nz==f){
					grid[nx][ny][nz] = grid[cx][cy][cz]+1;
					while(pq.size())pq.pop();
					break;
				}
				pq.push({nx,ny,nz});
				grid[nx][ny][nz] = grid[cx][cy][cz]+1;
			}
		}
		/*for(int i = 0; i < L; ++i){
			for(int j = 0; j < H; ++j){
				for (int k = 0; k < W; ++k){
					cout<<grid[i][j][k]<<' ';
				}cout<<'\n';
			}cout<<'\n';
		}*/
		if(grid[d][e][f])cout << "Escaped in " << grid[d][e][f]-1  << " minute(s)." << '\n';
		else cout << "Trapped!\n";
	}
}

