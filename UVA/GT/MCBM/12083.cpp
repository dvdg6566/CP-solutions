#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MOD 1e9+7
#define lb lower_bound
#define ub upper_bound
#define dst distance
#define INF 1000000000

int blocked = -1;

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
        for (int i =0;i < B; ++i)P[i]=-1;
        for (int i = 0; i < A; ++i) {
			if(i==blocked)continue;
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

struct edge {
    int a;
    string b,c;
    edge (int _a=0, string _b="", string _c=""): a(_a), b(_b), c(_c) {}
};

int T,N,h;
char c;
vector<edge> M,F;
string s1,s2;
int main(){
	//freopen("input.txt","r",stdin);
	cin >> T;
	while(T--){
		F.clear();
		M.clear();
		cin >> N;
		for (int i = 0; i < N; ++i){
			cin >> h >> c >> s1 >> s2;
			if(c == 'F'){
				F.pb({h,s1,s2});
			}else{
				M.pb({h,s1,s2});
			}
		}
		root = new AugPath(F.size(),M.size());
		for (int i = 0; i < F.size(); ++i){
			for (int j = 0; j < M.size(); ++j){
				 if(abs(F[i].a - M[j].a) > 40)continue;
				 if(F[i].b!=M[j].b)continue;
				 if(F[i].c==M[j].c)continue;
				 root->AddEdge(i,j);
			}
		}
		cout << N-root->MCBM() << '\n';
	}
}
