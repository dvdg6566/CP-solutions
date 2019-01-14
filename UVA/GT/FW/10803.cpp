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
	cin>>T;
	for(int it=1;it<=T;++it){
		cin>>N;
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
		
		for (int i = 1; i < N; ++i){
			for (int j = i+1; j <= N; ++j){
				c = sqrt((V[i].f-V[j].f)*(V[i].f-V[j].f) + (V[i].s-V[j].s)*(V[i].s-V[j].s));
				if(c>10)continue;
				adjMat[i][j]=c;
				adjMat[j][i]=c;
			}
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

		double res = 0;
		for (int i = 1; i <= N; ++i){
			for (int j = i; j <= N; ++j){
				res = max(res,adjMat[i][j]);
			}
		}
		cout << "Case #" << it << ":\n";
		if(res==INF)cout << "Send Kurdy\n\n";
		else printf("%.4lf\n\n",roundf(res*10000)/10000);
	}
}


