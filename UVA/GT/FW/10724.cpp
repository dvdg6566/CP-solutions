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

double adjMat[110][110],S[110][110];
int N,E,d,x,y,T;
double z=0;
double a,b,c;
vector<pair<double,double>> V;


int main(){
	//freopen("input.txt","r",stdin);
	while(cin>>N>>E){
		if(N==0)return 0;
		V.clear();V.pb(mp(0,0));
		memset(S,0,sizeof(S));
		for(int i=1;i<=N;++i){
			for(int j = 1;j<=N;++j){
				adjMat[i][j]=INF;
				if(i==j)adjMat[i][i]=0;
			}
		}
		
		for(int i = 1; i <= N; ++i){
			cin >> a >> b;
			V.pb(mp(a,b));
		}
		
		for (int i = 0; i < E; ++i){
			cin >> x >> y;	
			c = sqrt( (V[x].f-V[y].f)*(V[x].f-V[y].f) + (V[x].s-V[y].s)*(V[x].s-V[y].s));
			adjMat[x][y] = c;
			adjMat[y][x] = c;
			S[x][y]=1;S[y][x]=1;
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

		pi res=mp(-1,-1);
		double ans=-1;
		for (int i = 1; i < N; ++i){
			for (int j = i+1; j <= N; ++j){
				c = sqrt((V[i].f-V[j].f)*(V[i].f-V[j].f) + (V[i].s-V[j].s)*(V[i].s-V[j].s));
				 double tt = 0;
				 for (int it = 1; it <= N; ++it){
					for(int itt = 1; itt <= N; ++itt){
						double m = min(adjMat[it][i] + adjMat[itt][j] + c,adjMat[it][j] + adjMat[itt][i] + c);
						tt += max(z,adjMat[it][itt]-m);
					}
				}
				if(tt>ans){
					res=mp(i,j);
					ans=tt;
				}
			}
		}
		if(ans<1){
			cout<<"No road required\n";
		}else{
			cout <<res.f << ' ' << res.s << '\n';
		}
	}
}


