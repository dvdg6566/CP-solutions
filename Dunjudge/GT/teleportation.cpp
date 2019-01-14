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

vector<int> adjList[100000], compressed[100000];
int ind[100000], currstack[100000], lowlink[100000];
int SCC[100000];
stack<int> stk;
stack<pi> edgeList;
int N,E,a,b;

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
	cin >> N >> E;
	while(E--){
		cin >> a >> b;
		adjList[a].pb(b);
	}
	memset(ind,-1,sizeof(ind));
	memset(SCC, -1, sizeof(SCC));
	a = b = 0;
	for (int i = 0; i < N; ++i)dfs(i);
	for (int i = 0; i < N; ++i)cout << SCC[i] << ' ';cout << '\n';
	cout << N-1+b;
	
}
