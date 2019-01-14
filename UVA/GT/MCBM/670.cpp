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

vpi bob,ralph;
int T,a,b,c,B,R;
int middle[110];

double D(pi a, pi b){
	return sqrt((double)(a.f-b.f) * (double)(a.f-b.f) + (double)(a.s-b.s) * (double)(a.s-b.s));
} 

int main(){
	//freopen("input.txt","r",stdin);
	cin >> T;
	while(T--){
		memset(middle,-1,sizeof(middle));
		bob.clear();
		ralph.clear();
		cin >> B >> R;
		for (int i = 0; i < B; ++i){
			cin >> a >> b;
			bob.pb(mp(a,b));
		}
		for (int i = 0; i < R; ++i){
			cin >> a >> b;
			ralph.pb(mp(a,b));
		}
		root = new AugPath(B-1,R);
		for (int i = 0; i < B-1; ++i){
			double h = D(bob[i],bob[i+1]);
			for (int j = 0; j < R; ++j){
				double dog = D(bob[i],ralph[j]) + D(ralph[j],bob[i+1]);
				if(h*2<dog)continue;
				root->AddEdge(i,j);
			}
		}
		root->MCBM();
		vpi res = root->GetMatchings();
		for (auto i : res){
			middle[i.f] = i.s;
		}
		cout << res.size()+B << '\n';
		for (int i = 0; i < B; ++i){
			if(i!=0)cout<<' ';
			cout << bob[i].f << ' ' << bob[i].s;
			if(middle[i]>=0){
				int j = middle[i];
				cout << ' ' << ralph[j].f << ' ' << ralph[j].s;
			}
		}
		cout << "\n";
		if(T)cout<<'\n';
	}
}
