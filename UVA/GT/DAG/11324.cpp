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

set<int> adjList[1010];
int N,E,T,a,b;
vpi compressed[1010];
ll ind[1010], currstack[1010], lowlink[1010];
ll SCC[1010],SCCsize[1010],dist[1010];
bool visited[1010];
stack<int> stk;
stack<pi> edgeList;
vi topo;

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

void topodfs(int x){
   visited[x] = 1;
   for (auto i : compressed[x]) {
        if (visited[i.f]) continue;
        topodfs(i.f);
    }
    topo.pb(x);
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> T;
	while(T--){
		cin >> N >> E;
		for(int i = 1; i <= N; ++i){
			adjList[i].clear();
			compressed[i].clear();
		}
		while(E--){
			cin >> a >> b;
			if(a==b)continue;
			adjList[a].insert(b);
			edgeList.push(mp(a,b));
		}
		memset(ind,-1,sizeof(ind));
		memset(SCC, -1, sizeof(SCC));
		memset(lowlink,0,sizeof(lowlink));
		memset(currstack,0,sizeof(currstack));
		memset(SCCsize,0,sizeof(SCCsize));
		memset(visited,0,sizeof(visited));
		memset(dist,0,sizeof(dist));
		a = b = 0;
		for (int i = 1; i <= N; ++i){
			dfs(i);
			SCCsize[SCC[i]]++;
			//cout << "NODE " << i << " in SCC " << SCC[i] << '\n';
		}
		int S = b;
		//for (int i = 0; i < S; ++i)cout << "SCC " << i << " has " <<  SCCsize[i] << " nodes\n";
		while (!edgeList.empty()){
			a = SCC[edgeList.top().f];
			b = SCC[edgeList.top().s];
			edgeList.pop();
			if (a == b)continue;
			//cout << "EDGE " << a << ' ' << b << '\n';
			compressed[a].pb(mp(b,SCCsize[b]));
		}
		topo.clear();
		for (int i = 0; i < S; ++i){
			topodfs(i);
		}
		reverse(topo.begin(),topo.end());
		for (auto i : topo){
			if(dist[i] == 0)dist[i] = SCCsize[i];
			for (auto j : compressed[i]){
				dist[j.f] = max(dist[i] + j.s, dist[j.f]);
			}
		}
		cout << *max_element(dist,dist+S) << '\n';
	}
}

