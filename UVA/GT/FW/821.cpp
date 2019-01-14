#include<bits/stdc++.h>
using namespace std;

#define INF 100000000
#define pb push_back
#define f first
#define s second

int N,a,b,c,cnt,E;
int adjMat[30][30],p[30][30];
string s;
char x,y,z;
map<char,int> M;
vector<char>V;

void printPath(int i, int j) {
	if (i != j) printPath(i, p[i][j]);
	if(i!=j)cout<<' ';
	cout << V[j];
}

int main(){
	//freopen("input.txt","r",stdin);
	while(1){
		M.clear();
		V.clear();
		V.pb(' ');
		cin >> N;
		if(cin.eof())return 0;
		for(int i=0;i<=N;++i){
			for(int j =0;j<=N;++j){
				adjMat[i][j]=INF;
				p[i][j]=i;
				if(i==j)adjMat[i][i]=0;
			}
		}
		cin >> E;
		int cnt=1;
		while(E--){
			cin >> x >> y >> a;
			a = a*50+1;
			if(M[x]==0){
				M[x]=cnt;
				V.pb(x);
				cnt++;
			}
			if(M[y]==0){
				M[y]=cnt;
				V.pb(y);
				cnt++;
			}
			
			adjMat[M[x]][M[y]]=a;
			adjMat[M[y]][M[x]]=a;
		}
		
		for (int k = 1; k <= N; ++k){
			for (int i = 1; i <= N; ++i){
				for (int j = 1; j <= N; ++j){
					if (adjMat[i][k] + adjMat[k][j] < adjMat[i][j]) {
						adjMat[i][j] = adjMat[i][k] + adjMat[k][j];
						p[i][j] = p[k][j];
					}
				}
			}
		}
		cin>> E;
		while(E--){
			cin >> x >> y;
			a=M[x];
			b=M[y];
			printPath(a,b);cout<<'\n';
		}
	}
}


