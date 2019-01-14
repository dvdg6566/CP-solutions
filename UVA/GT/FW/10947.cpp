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

struct node {
    double a, b, c;
    node (double _a=0, double _b=0, double _c=0): a(_a), b(_b), c(_c) {}
};

double adjMat[110][110];
int N,E,d,x,y,T;
double z=0;
double a,b,c;
vector<node> V;

int main(){
	//freopen("input.txt","r",stdin);
	while(1){
		cin>>a;
		if(cin.eof())return 0;
		cin>>b;
		z =a*b;
		V.clear();V.pb({0,0,0});
		cin >> a >> b >> c;
		V.pb({a,b,c});
		cin >> a >> b >> c;
		V.pb({a,b,c});
		cin >>N;
		N+=2;
		//cout << N << ' ';
		for(int i=1;i<=N;++i){
			for(int j = 1;j<=N;++j){
				adjMat[i][j]=INF;
				if(i==j)adjMat[i][i]=0;
			}
		}
		
		for(int i = 1; i <= N-2; ++i){
			cin >> a >> b >> c;
			V.pb({a,b,c});
		}
		
		for (int i = 1; i < N; ++i){
			for (int j = i+1; j <= N; ++j){
				c = sqrt((V[i].a-V[j].a)*(V[i].a-V[j].a) + (V[i].b-V[j].b)*(V[i].b-V[j].b)) - V[i].c - V[j].c;
				if(c>z)continue;
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
		
		if(adjMat[1][2]==INF)cout << "Larry and Ryan will be eaten to death.\n";
		else cout << "Larry and Ryan will escape!\n";
	}
}



