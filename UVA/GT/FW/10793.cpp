#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef vector<ll> vi;
typedef pair<pi,pi> pii;
typedef pair<int,pi> ii;
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define INF 100000000

int adjMat[110][110];
int N,E,d,x,y,T,a,b,c,z;

int main(){
	freopen("input.txt","r",stdin);
	cin >> T;
	for(int ss =1;ss<=T; ++ss){
		cin>>N>>E;

		for(int i=1;i<=N;++i){
			for(int j = 1;j<=N;++j){
				adjMat[i][j]=INF;
				if(i==j)adjMat[i][i]=0;
			}
		}
		
		while(E--){
			cin >> a >> b >> c;
			adjMat[a][b] = c;
			adjMat
		}
		for (int k = 1; k <= N; ++k) {
			for (int i = 1; i <= N; ++i) {
				for (int j = 1; j <= N; ++j) {
					if (adjMat[i][k] == -1 || adjMat[k][j] == -1) continue;
					if (adjMat[i][j] == -1 || adjMat[i][j] > adjMat[i][k] + adjMat[k][j]) 
						adjMat[i][j] = adjMat[i][k] + adjMat[k][j];
				}
			}
		}
		int ans=INF,res=-1;
		for (int i = 6; i <= N; ++i){
			a = adjMat[i][1];
			cout << a << ' ';
			for (int j=2;j<=5;++j){
				if(adjMat[i][j]!=a){a=-1;break;}
			}
			if(a==-1)continue;
			b=0;
			for (int j=6; j<=N; ++j){
				b = max(b,adjMat[i][j]);
			}
			if(b<ans){
				ans=b;res=i;
			}
		}
		cout << "Map " << ss << ':' << ' ' << res << '\n';
	}
}



