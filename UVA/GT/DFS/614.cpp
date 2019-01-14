#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;

#define f first
#define s second
#define mp make_pair
#define pb push_back

int grid[55][55];
int route[55][55];
int a,b,c,d,e,g;
int dx[] ={0,-1,0,1};
int dy[] = {-1,0,1,0};
int len = 1;

bool dfs(pi cur){
	route[cur.f][cur.s] = len;
	len++;
	for (int i = 0; i < 4; ++i){
		pi nxt = mp(cur.f+dx[i], cur.s+dy[i]);
		if (nxt.f ==0||nxt.s==0)continue; //Leaving the maze
		if (nxt.f ==a+1 ||nxt.s==b+1)continue; //Leaving the maze
		if(route[nxt.f][nxt.s] != 0)continue; //Already visited
		if (i == 1){
			if (grid[nxt.f][nxt.s] >= 2)continue; // Destination has downward wall when wanting to go up
		}
		if (i == 3){
			if (grid[cur.f][cur.s] >= 2)continue; // Wanna go downwards but current has southern wall
		}
		if (i == 2){
			if (grid[cur.f][cur.s]%2==1)continue; // Wanna go east but current has eastern wall
		}
		if (i == 0){
			if (grid[nxt.f][nxt.s]%2==1)continue; // Wanna go West but destination has eastern wall
		}
		if (nxt.f==e&&nxt.s==g){
			route[e][g] = len;
			//cout << e<< ' ' <<g << '\n';
			return 1;
		}
		bool x = dfs(nxt);
		if (x == 1){
			return 1;
		}
	}
	len--;
	route[cur.f][cur.s] = -1;
	return 0;
}

int cnt = 0;
int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	while(1){
		cin >> a >> b >> c >> d >> e >> g;
		if (max({a,b,c,d,e,g})==0){return 0;}
		cnt++;
		cout<<"Maze " << cnt << '\n'<<'\n';
		memset(route,0,sizeof(route));
		memset(grid,0,sizeof(grid));
		len = 0;
		for (int i = 1; i <= a; ++i){
			for (int j = 1; j <= b; ++j){
				cin >> grid[i][j];
			}
		}
		len = 1;
		if(e==c&&g==d)route[c][d] = 1;
		else dfs(mp(c,d));
		for(int i=0;i<b;++i)cout<<"+---";cout<<'+';cout<<'\n';
		for(int i=1;i<=a; ++i){
			cout<<'|';
			for (int j =1; j <= b;++j){
				if(route[i][j]==-1)cout<< "???";
				else if(route[i][j] == 0)cout<<"   ";
				else if(route[i][j] <= 9)cout<< "  " << route[i][j];
				else if (route[i][j] <= 99)cout << " " << route[i][j];
				else {cout << route[i][j];assert(0);}
				if(j!=b){
					if(grid[i][j]%2==1)cout << '|';
					else cout << ' ';
				}
			}
			cout << '|';
			cout << '\n';
			if(i==a){
				for (int j = 1; j<=b;++j)cout<<"+---";
				cout << "+\n";
				continue;
			}
			for (int j = 1; j<=b;++j){
				if(grid[i][j]>=2)cout << "+---";
				else cout <<"+   ";
			}
			cout<<"+\n";
		}
		cout << "\n\n";
	}
}
