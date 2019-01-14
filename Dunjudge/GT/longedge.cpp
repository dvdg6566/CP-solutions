#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef double dl;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MOD 1e9+7
#define lb lower_bound
#define ub upper_bound
#define INF 1000000000

int adjMat[110][110];
int N,M,a,b,w,ans;

struct edge{
	int a,b,w;
	edge(int _a, int _b, int _w): a(_a),b(_b),w(_w){}
};
vector<edge> edgeList;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> N >> M;
	for(int i=1;i<=N;++i){
		for(int j =1;j<=N;++j){
			adjMat[i][j]=INF;
		}
		adjMat[i][i] = 0;
	}
	for (int i = 0; i < M; ++i){
		cin >> a >> b >> w;
		adjMat[a][b] = adjMat[b][a] = w;
		edgeList.pb({a,b,w});
	}
	for (int k =1; k <=N; k++){
		for (int i = 1; i <=N; i++){
			for (int j = 1; j <=N; j++){
				if (adjMat[i][k] + adjMat[k][j] < adjMat[i][j]) {
					adjMat[i][j] = adjMat[i][k] + adjMat[k][j];
				}
			}
		}
	}
	for (auto i : edgeList){
		bool chk = 0;
		for (int j = 1; j <= N; ++j){
			if (adjMat[j][i.a] + i.w == adjMat[j][i.b]){chk = 1;break;}
			if (adjMat[j][i.b] + i.w == adjMat[j][i.a]){chk = 1;break;}
		}
		if(chk)++ans;
	}
	cout << M-ans;
	
}
