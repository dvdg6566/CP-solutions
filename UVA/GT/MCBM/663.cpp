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

int disallowed_a,disallowed_b;

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
			if(x == disallowed_a && it == disallowed_b)continue;
            if (P[it] == -1) {
                P[it] = x;
                return 1;
            }
        }
        for (auto it:G[x]) {
			if(x == disallowed_a && it == disallowed_b)continue;
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

struct edge {
    int a, b, c, d;
    edge (int _a=0, int _b=0, int _c=0, int _d = 0): a(_a), b(_b), c(_c), d(_d) {}
};
int N,a,b,c,d,cnt;
vector<edge> V;
vpi res;

int main(){
	//freopen("input.txt","r",stdin);
	while(1){
		cnt++;
		cin >> N;
		if(!N)return 0;
		root = new AugPath(N,N);
		disallowed_a = -1;
		disallowed_b = -1;
		V.clear();
		for (int i = 0; i < N; ++i){
			cin >> a  >> b >> c >> d;
			V.pb({a,b,c,d});
		}
		for (int i = 0; i < N; ++i){
			cin >> a >> b;
			for (int j = 0; j < N; ++j){
				if(a<V[j].a||a>V[j].b)continue;
				if(b<V[j].c||b>V[j].d)continue;
				root->AddEdge(i,j);
			}
		}
		cout << "Heap " << cnt << '\n';
		int x = root -> MCBM();
		vpi tmp = root->GetMatchings();
		res.clear();
		for (auto i : tmp){
			disallowed_a = i.f;
			disallowed_b = i.s;
			int p = root->MCBM();
			if (p!=x){
				res.pb(mp(i.f,i.s));
			} 
		}
		if(res.size() == 0){cout<<"none\n\n";continue;}
		for (int i = 0; i < N; ++i){
			swap(res[i].f,res[i].s);
		}
		sort(res.begin(),res.end());
		for (auto i : res){
			char x = i.f + 'A';
			if(i.f != res[0].f)cout<<' ';
			cout <<  '(' << x << ',' << i.s+1 <<')';
		}
		cout << "\n\n";
	}
}
