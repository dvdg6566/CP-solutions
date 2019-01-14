#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef double dl;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MOD 1e9+7
#define lb lower_bound
#define ub upper_bound
#define dst distance
#define INF 1000000000

int N,R,ctr;
map<string,int> M;
string s1,s2;
int adjMat[51][51];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	while(1){
		ctr++;
		cin >> N >> R;
		if(N==0&&R==0)return 0;
		M.clear();
		int cnt = 1;
		memset(adjMat,-1,sizeof(adjMat));
		for (int i = 0; i < R; ++i){
			cin >> s1 >> s2;
			if(M[s1] == 0){M[s1] = cnt; cnt++;}
			if(M[s2] == 0){M[s2] = cnt; cnt++;}
			adjMat[M[s1]-1][M[s2]-1] = 1;
			adjMat[M[s2]-1][M[s1]-1] = 1;
		}
		for(int i = 0; i < N; ++i)adjMat[i][i] = 0;
		for (int k = 0; k < N; ++k) {
			for (int i = 0; i < N; ++i) {
				for (int j = 0; j < N; ++j) {
					if (adjMat[i][k] == -1 || adjMat[k][j] == -1) continue;
					if (adjMat[i][j] == -1 || adjMat[i][j] > adjMat[i][k] + adjMat[k][j]){
						adjMat[i][j] = adjMat[i][k] + adjMat[k][j];
					}
				}
			}
		}
		int res = -1,ccc=0;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if(adjMat[i][j] == -1){
					cout << "Network " << ctr << ": DISCONNECTED\n\n";
					ccc = 1;
					break;
				}
				res = max(adjMat[i][j],res);
			}
			if(ccc)break;
		}
		if(!ccc)cout << "Network " << ctr << ": " << res << "\n\n";
	}
}
