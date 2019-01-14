#include<bits/stdc++.h>
using namespace std;
typedef double ll;
typedef pair<ll,ll> pi;
typedef vector<int> vi;

#define f first
#define s second
#define mp make_pair
#define pb push_back

struct edge {
    int a, b;
    ll w;
    edge (int _a=0, int _b=0, ll _w=0): a(_a), b(_b), w(_w) {}
};
 
int p[200];
vector<pi> adjList[200];
int par(int x) { return (x==p[x])?x:p[x]=par(p[x]);}
vector<edge> edgeList;
bool cmp (edge x, edge y) { return x.w > y.w; } 
ll N,E,Q,w,t,cntr;
int a,b;
ll dist[200];

void dfs(int x){
	for (auto i : adjList[x]){
		if(dist[(int)i.f]!=1234567890)continue;
		dist[(int)i.f] = min(dist[x],i.s);
		dfs(i.f);
	}
}

int main(){
	//freopen("input.txt","r",stdin);
	while(1){
		cntr++;
		cin >> N >> E;
		if(N==0)return 0;
		for (int i = 1; i <= N; ++i){p[i] = i;dist[i]=1234567890;}
		edgeList.clear();
		
		while(E--){cin >> a >> b >> w;edgeList.pb({a,b,w});}
		for (int i = 1; i <= N; i++)p[i] = i;
		sort(edgeList.begin(), edgeList.end(), cmp);
		for (auto it : edgeList){
			if (par(it.a) == par(it.b)) continue;
			p[par(it.a)] = par(it.b);
			adjList[it.a].pb(mp(it.b,it.w));
			adjList[it.b].pb(mp(it.a,it.w));
			//cout << it.w << ' ';
		}
		
		cout << "Scenario #" << cntr << '\n' << "Minimum Number of Trips = ";
		cin >> a  >> b >> w;
		dist[a] = 1234567890;
		dfs(a);
		//cout << dist[b] << ' ';
		
		cout << ceil((float)w/(float)(dist[b] - 1)) << '\n' << '\n';
		for (int i = 1;i<=N;++i)adjList[i].clear();
	}
}
