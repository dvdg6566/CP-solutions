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

struct AugPath {
    int A, B;   //size of left, right groups
    vector<vector<int> > G; //size A
    vector<bool> visited;   //size A
    vector<int> P;          //size B
    
    AugPath(int _A, int _B): A(_A), B(_B), G(_A), P(_B, -1) {}
    
    void AddEdge(int a, int b) {    //a from left, b from right
        G[a].push_back(b);
    }
    
    bool Aug(int x) {
        if (visited[x]) return 0;
        visited[x] = 1;
        /* Greedy heuristic */
        for (auto it:G[x]) {
            if (P[it] == -1) {
                P[it] = x;
                return 1;
            }
        }
        for (auto it:G[x]) {
            if (Aug(P[it])) {
                P[it] = x;
                return 1;
            }
        }
        return 0;
    }
    int MCBM() {
        int matchings = 0;
        for (int i = 0; i < A; ++i) {
            visited.resize(A, 0);
            matchings += Aug(i);
            visited.clear();
        }
        return matchings;
    }
    vector<pair<int, int> > GetMatchings() {
        vector<pair<int, int> > matchings;
        for (int i = 0; i < B; ++i) {
            if (P[i] != -1) matchings.emplace_back(P[i], i);
        }
        return matchings;
    }
}*root;

dl dist(pi a, pi b){
	return sqrt((a.f-b.f)*(a.f-b.f) + (a.s-b.s)*(a.s-b.s));
}

int T,N,X,a,b,H;
vi blue, red;
string S;
vpi C;
bool B[120];

bool works (int L){
	root = new AugPath(red.size(),blue.size());
	for (int i = 0; i < red.size(); ++i){
		for (int j = 0; j < blue.size(); ++j){
			if (dist(C[red[i]],C[blue[j]]) < (dl)L){
				root->AddEdge(i,j);
			}
		}
	}
	if (root->MCBM() < X)return 0;
	else return 1;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> T;
	while(T--){
		C.clear();
		memset(B,0,sizeof(B));
		H = 0;
		blue.clear();
		red.clear();
		cin >> N >> X;
		for (int i = 0; i < N; ++i){
			cin >> a >> b >> S;
			C.pb(mp(a,b));
			if (S == "red"){
				B[i] = 1;
				red.pb(i);
			}else blue.pb(i);
			for (int j = 0; j < i; ++j){
				dl D = dist(C[i],C[j]);
				H = max(H,(int)ceil(D));
			}
		}
		int low = 0, high = H;
		while(high > low+1){
			int mid = (high+low)/2;
			if (works(mid))high = mid;
			else low = mid;
		}
		if (works(low))cout << low << '\n';
		else if (works(high))cout << high << '\n';
		else cout << "Impossible\n";
	}
}
