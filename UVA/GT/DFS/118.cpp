#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;

#define f first
#define s second
#define mp make_pair
#define pb push_back

int a,b,c,d,e;
string str;
char dir;
bool grid [100][100];
map<char,pi> M;

char rotate(char x, bool y){ //y is 0 if clockwise, 1 if anticlockwise
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

int main(){
	//freopen("input.txt","r",stdin);
	M['N'] = mp(0,1);
	M['S'] = mp(0,-1);
	M['W'] = mp(-1,0);
	M['E'] = mp(1,0);
	
	cin >> a >> b;
	b++;a++;b++;a++;
	while(!cin.eof()){
		cin >> c;
		if (cin.eof())return 0;
		cin >> d >> dir;
		cin >> str;
		pi cur = mp(c+1,d+1);
		//assert(min(cur.f,cur.s)>0);
		bool x = 0;
		for (auto i : str){
			if (i == 'F'){
				bool y = 0;
				pi nxt = mp(cur.f+M[dir].f,cur.s+M[dir].s);
				if (nxt.f>=a || nxt.f <= 0 || nxt.s>=b || nxt.s <= 0){
					if(!grid[cur.f][cur.s]==1){
						grid[cur.f][cur.s] = 1;
						//cout << "CHANGE " << nxt.f-1 << ' ' << nxt.s-1 << '\n';
						//cur = nxt;
						x = 1;
						break;
					}else y = 1;
				}
				if(!y)cur = nxt;
				continue;
			}
			if (i == 'L'){
				dir = rotate(dir,1);
				continue;
			}
			if (i == 'R'){
				dir = rotate(dir,0);
				continue;
			}
			assert(0);
		}
		cout << cur.f-1 << ' ' << cur.s-1 << ' ' << dir;
		if (x)cout << ' ' << "LOST";
		cout << '\n';
	}
}
