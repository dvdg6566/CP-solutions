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

int T,N,Q;
map<string,int> M;
vector<string> nodes;
string st1,st2,name;
int adjMat[210][210],p[210][210];

void printPath(int i, int j) {
	if (i != j) printPath(i, p[i][j]);
	if (i == j){}else {cout << ' ';}
	cout << nodes[j%N];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> T;
	while(T--){
		cin >> N;
		nodes.clear();
		M.clear();
		for (int i = 0; i < N; ++i){
			cin >> st1;
			M[st1] = i;
			nodes.pb(st1);
		}
		memset(adjMat,-1,sizeof(adjMat));
		for (int i = 0; i < N; ++i){
			for (int j = 0; j < N; ++j){
				cin >> adjMat[i][j];
				adjMat[i][j+N] = adjMat[i][j];
			}
		}
		for (int i = 0; i < 2*N; ++i){
			for (int j = 0; j < 2*N; ++j){
				p[i][j] = i;
			}
		}
		for (int k = 0; k < 2*N; ++k) {
			for (int i = 0; i < 2*N; ++i) {
				for (int j = 0; j < 2*N; ++j) {
					if (adjMat[i][k] == -1 || adjMat[k][j] == -1) continue;
					if (adjMat[i][j] == -1 || adjMat[i][j] > adjMat[i][k] + adjMat[k][j]){
						adjMat[i][j] = adjMat[i][k] + adjMat[k][j];
						p[i][j] = p[k][j];
					}
				}
			}
		}
		cin >> Q;
		while(Q--){
			cin >> name >> st1 >> st2;
			if(adjMat[M[st1]][M[st2]+N] == -1){
				cout << "Sorry Mr " << name << " you can not go from " << st1 << " to " << st2 << "\n";
				continue;
			}
			cout << "Mr " << name << " to go from " << st1 << " to " << st2 << ", you will receive " << adjMat[M[st1]][M[st2]+N] << " euros\n";
			cout << "Path:";
			printPath(M[st1],M[st2]+N);
			cout << '\n';
		}
	}
}
