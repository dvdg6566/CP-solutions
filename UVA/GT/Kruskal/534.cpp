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
 
int p[300];
vector<pi> adjList[300];
int par(int x) { return (x==p[x])?x:p[x]=par(p[x]);}
vector<edge> edgeList;
bool cmp (edge x, edge y) { return x.w < y.w; } 
ll N,E,w,t,a,b,cntr;
vector<pi> V;
double dist[300];

void dfs(int x){
	for (auto i : adjList[x]){
		if(dist[(int)i.f]!=0)continue;
		dist[(int)i.f] = max(dist[x],i.s);
		dfs(i.f);
	}
}

int main(){
	//freopen("input.txt","r",stdin);
	while(1){
		cntr++;
		cin >> N;
	
		if(N==0)return 0;
		for (int i = 0; i < N; ++i)p[i] = i;
		edgeList.clear();
		V.clear();
		memset(dist,0,sizeof(dist));
		for (int i = 0; i < N; ++i){
			cin >> a >> b;
			V.pb(mp(a,b));
		}
		for (int i = 0; i < N; ++i){
			for (int j = i; j < N; ++j){
				double x = sqrt((V[i].f-V[j].f)*(V[i].f-V[j].f)+(V[i].s-V[j].s)*(V[i].s-V[j].s));
				edgeList.pb({i,j,x});
				edgeList.pb({j,i,x});
			}
		}
		for (int i = 0; i < N; i++)p[i] = i;
		sort(edgeList.begin(), edgeList.end(), cmp);
		for (auto it : edgeList){
			if (par(it.a) == par(it.b)) continue;
			p[par(it.a)] = par(it.b);
			adjList[it.a].pb(mp(it.b,it.w));
			adjList[it.b].pb(mp(it.a,it.w));
		}
		dist[0] = -1;
		dfs(0);
		cout << "Scenario #" << cntr << '\n' << "Frog Distance = "; 
		printf("%.3lf\n\n",dist[1]);
		for (int i = 0;i<N;++i)adjList[i].clear();
	}
}
