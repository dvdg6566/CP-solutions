#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;

#define f first
#define s second
#define mp make_pair
#define pb push_back

map<char,pi> M;

char rotate(char x, bool y){ //y is 0 if right, 1 if left
	if (y){
		if (x=='N')return 'W';
		if (x=='W')return 'S';
		if (x=='S')return 'E';
		if (x=='E')return 'N';
	}
	if (x=='N')return 'E';
	if (x=='W')return 'N';
	if (x=='S')return 'W';
	if (x=='E')return 'S';
	assert(0);
	return 'N';
}

int a,b,c,d,t;
string x,y,z;
int grid[70][70];

int main(){
	//freopen("input.txt","r",stdin);
	M['N'] = mp(-1,0);
	M['S'] = mp(1,0);
	M['W'] = mp(0,-1);
	M['E'] = mp(0,1);
	cin >> t;
	while(t--){
		memset(grid,0,sizeof(grid));
		cin >>a >> b;
		cin.ignore();
		for (int i = 1; i <= a; ++i){
			getline(cin,x);
			for (int j = 1; j <= b; ++j){
				grid[i][j] = (x[j-1] == '*');
			}
		}
		cin >> c >> d;
		pi cur = mp(c,d);
		char dir = 'N';
		bool  cnt = 1;
		while (cnt){
			cin >> x;
			for (auto i : x){
				if (i == 'Q'){
					cnt = 0;
					cout << cur.f << ' ' << cur.s << ' ' << dir << '\n';
					if(t!=0)cout << '\n';
				}
				if (i == 'R')dir = rotate(dir,0);
				if(i=='L')dir = rotate(dir,1);
				if (i == 'F'){
					pi nxt = mp(cur.f+M[dir].f,cur.s+M[dir].s);
					if (grid[nxt.f][nxt.s] == 1)continue;
					cur = nxt;
				}
			}
		}
	}	
}
