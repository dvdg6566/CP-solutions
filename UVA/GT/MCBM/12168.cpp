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

int T,C,D,P,a,b;
char x,y;
vpi Cat,Dog;

int main(){
	//freopen("input.txt","r",stdin);
	cin>>T;
	while(T--){
		Cat.clear();
		Dog.clear();
		cin >> C >> D >> P;
		for (int i = 0; i < P; ++i){
			cin >> x >> a >> y >> b;
			if(x=='C'){
				Cat.pb(mp(a,b));
			}else{
				Dog.pb(mp(a,b));
			}
		}
		root = new AugPath(Cat.size(),Dog.size());
		for (int i = 0; i < Cat.size(); ++i){
			for (int j = 0; j < Dog.size(); ++j){
				if(Cat[i].f == Dog[j].s)root->AddEdge(i,j);
				if(Cat[i].s == Dog[j].f)root->AddEdge(i,j);
			}
		}
		cout << P - root->MCBM() << '\n';
	}	
}
