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

int adjMat[130][130];
int N,E,a,b,c,d,x,y,T,cnt;

int main(){
	//freopen("input.txt","r",stdin);
	cin>>T;
	while(T--){
		cnt++;
		cin >> N >> E;
		if(N==0)return 0;
		
		for(int i=0;i<N;++i){
			for(int j = 0;j<N;++j){
				adjMat[i][j]=INF;
				if(i==j)adjMat[i][i]=0;
			}
		}
		
		while(E--){
			cin>>a>>b;
			adjMat[a][b] =1;
			adjMat[b][a] = 1;
		}
		
		for (int k = 0; k < N; ++k) {
			for (int i = 0; i < N; ++i) {
				for (int j = 0; j < N; ++j) {
					if (adjMat[i][k] == -1 || adjMat[k][j] == -1) continue;
					if (adjMat[i][j] == -1 || adjMat[i][j] > adjMat[i][k] + adjMat[k][j]) 
						adjMat[i][j] = adjMat[i][k] + adjMat[k][j];
				}
			}
		}
		
		cin>>a>>b;
		int res=-1;
		for(int i=0;i<N;++i){
			res = max(res,adjMat[a][i]+adjMat[i][b]);
		}
		cout << "Case " << cnt << ": ";
		cout << res;
		cout<<'\n';
	}
}
