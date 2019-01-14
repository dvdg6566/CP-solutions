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

int adjMat[30][30];
int N,E,a,b,c,d,x,y,T,cnt;
string arr[30];

int main(){
	//freopen("input.txt","r",stdin);
	while(1){
		cnt++;
		cin >> N >> E;
		if(N==0)return 0;
		for (int i = 1; i <= N; ++i)cin>>arr[i];
		for(int i=1;i<=N;++i){
			for(int j = 1;j<=N;++j){
				adjMat[i][j]=INF;
				if(i==j)adjMat[i][i]=0;
			}
		}
		
		while(E--){
			cin>>a>>b>>c;
			adjMat[a][b] =c;
			adjMat[b][a] = c;
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
		
		int res=-1,ans=INF;
		for (int i = 1; i <= N; ++i){
			int dist = 0;
			for(int j=1;j<=N;++j)dist+=adjMat[i][j];
			if(dist<ans){res=i;ans=dist;}
		}
		cout << "Case #" << cnt << " : ";
		cout << arr[res] << '\n';
	}
}




