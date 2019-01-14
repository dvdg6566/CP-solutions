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

int R,C,T,a,b;
vector<int> Co;

int main(){
	//freopen("input.txt","r",stdin);
	while(1){
		cin>>R>>C>>T;
		if(R==0)return 0;
		blocked = -1;
		root = new AugPath(R,C);
		while(T--){
			cin >>a >> b;
			root->AddEdge(a-1,b-1);
		}
		Co.clear();
		int tmp = root->MCBM(); 
		cout << root->MCBM() << ' ';
		vpi x = root->GetMatchings();
		b=0; 
		sort(x.begin(),x.end());
		for (auto i : x){
			blocked = i.f;
			if(tmp==root->MCBM()){
				Co.pb(i.s);
				continue;
			}
			if(!b){b=1;}
			else cout<<' ';
			cout << 'r' << i.f+1;
		}
		sort(Co.begin(),Co.end());
		for (auto i : Co){
			if(!b){b=1;}
			else cout<<' ';
			cout << 'c' << i+1;
		}
		cout << '\n';
	}
}
