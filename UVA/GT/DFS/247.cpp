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
#define MOD 1000007
#define lb lower_bound
#define ub upper_bound
#define dst distance
#define INF 1000000000

map<string,int> M;
vector<string> V;
vi adjList[30];
int N,E,a,b,tc=1;
string s1,s2;

int ind[30], currstack[30], lowlink[30], SCC[30];
vi out[30];
stack<int> stk;

void dfs(int x){
	if (ind[x] != -1)return;
	ind[x] = a;
	lowlink[x] = a;
	a++;
	currstack[x] = 1;
	stk.push(x);
	for (auto it : adjList[x]){
		if (SCC[it] != -1)continue;
		if (ind[it] == -1){
			dfs(it);
			lowlink[x] = min(lowlink[x], lowlink[it]);
			continue;
		}
		else if (currstack[it]){
			lowlink[x] = min(lowlink[x], ind[it]);
		}
	}
	if (lowlink[x] == ind[x]){
		while (stk.top() != x){
			currstack[stk.top()] = 0;
			SCC[stk.top()] = b;
			stk.pop();
		}
		stk.pop();
		SCC[x] = b;
		b++;
	}
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("input.txt","r",stdin);
	while(tc++){
		cin >> N >> E;
		if(N==0)return 0;
		V.clear();
		M.clear();
		for(int i = 0; i <= N; ++i){adjList[i].clear();out[i].clear();}
		memset(ind,-1,sizeof(ind));
		memset(SCC, -1, sizeof(SCC));
		memset(currstack, 0, sizeof(currstack));
		memset(lowlink, 0, sizeof(lowlink));
		while(stk.size())stk.pop();
		V.pb("X");
		int cnt = 1;
		for (int i = 0; i < E; ++i){
			cin >> s1 >> s2;
			if(M[s1] == 0){M[s1] = cnt; cnt++;V.pb(s1);}
			if(M[s2] == 0){M[s2] = cnt; cnt++;V.pb(s2);}
			adjList[M[s1]].pb(M[s2]);
		}
		a=b=0;
		for (int i = 1; i <= N; ++i){
			dfs(i);
		}
		for (int i = 1; i <= N; ++i){
			assert(SCC[i] != -1);
			out[SCC[i]].pb(i);
		}
		cout << "Calling circles for data set " << tc-1 << ":\n";
		for (int i = 0; i <= N; ++i){
			if(!out[i].size())break;
			for (auto j:out[i]){
				if(j!=out[i][0])cout << ", ";
				cout << V[j];
			}
			cout << '\n';
		}
		cout << '\n';
	}
}
