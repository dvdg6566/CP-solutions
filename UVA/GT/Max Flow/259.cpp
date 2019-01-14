// Sike. This question isn't max flow. It's MCBM.

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
}*G;

string str,res;
int a,b,c,R;

void end(){
	if(G->MCBM() < R){
		cout << "!\n";
		return;
	}
	res = "__________";
	vpi V = G->GetMatchings();
	for (auto i : V){
		res[i.f] = ((i.s)-11)%26+'A';
	}
	cout << res << '\n';
}

int main(){
	//freopen("input.txt","r",stdin);
	G = new AugPath(10,260);
	while(1){
		getline(cin,str);
		if(cin.eof()){
			end();
			return 0;
		}
		if(str == ""){
			end();
			R=0;
			G = new AugPath(10,260);
			continue;
		}
		a = 11 + str[0] - 'A';
		b = str[1] - '0';
		R+=b;
		str = str.substr(3,str.size()-3);
		str = str.substr(0,str.size()-1);
		for (auto x : str){
			c = x - '0';
			for (int i = 0; i < b; ++i){
				G->AddEdge(c,a+i*26);
			}
		}
	}
}
