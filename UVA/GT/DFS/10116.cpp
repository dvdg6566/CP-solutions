#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;

#define f first
#define s second
#define mp make_pair
#define pb push_back

char G[1001][1001];
int S[1001][1001];
int a,b,c;
map<char,pi>M;

char rotate(char x, bool y){ //y is 0 if left, 1 if right
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
	M['N'] = mp(-1,0);
	M['S'] = mp(1,0);
	M['W'] = mp(0,-1);
	M['E'] = mp(0,1);
	
	//freopen("input.txt","r",stdin);
	while(1){
		cin >> a >> b >> c;
		if(a==0&&b==0&&c==0)return 0;
		memset(S,0,sizeof(S));
		memset(G,0,sizeof(G));
		for (int i = 1; i <= a; ++i){
			for(int j  = 1; j <= b;++j)cin>>G[i][j];
		}
		pi cur = mp(1,c);
		int cnt = 2;
		S[1][c] = 1;
		while(1){
			int i = cur.f,j=cur.s;
			pi nxt = mp(M[G[i][j]].f+cur.f,M[G[i][j]].s+cur.s);
			if(nxt.f==0||nxt.s==0||nxt.f>a||nxt.s>b){
				cout << cnt-1 << " step(s) to exit\n";
				break;
			}
			if(S[nxt.f][nxt.s]!=0){
				cout << S[nxt.f][nxt.s]-1 << " step(s) before a loop of " << cnt-S[nxt.f][nxt.s] << " step(s)\n";
				break;
			}
			S[nxt.f][nxt.s] = cnt;
			cnt++;
			cur = nxt;
		}
	}
}
