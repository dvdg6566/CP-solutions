#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
bool cmp (edge x, edge y) { return x.w > y.w; } 
ll N,E,w,t,cntr,cnt=1;
int a,b;
vector<pi> V;
ll dist[300];
string s1,s2;
map<string,int> M;


void dfs(int x){
	for (auto i : adjList[x]){
		if(dist[i.f]!=1234567890)continue;
		dist[i.f] = min(dist[x],i.s);
		dfs(i.f);
	}
}

int main(){
	//freopen("input.txt","r",stdin);
	while(1){
		cntr++;
		cin >> N >> E;
		if(N==0)return 0;
		for (int i = 1; i <= N; ++i)p[i] = i;
		edgeList.clear();
		V.clear();
		cnt=1;
		M.clear();
		while(E--){
			cin >> s1 >> s2 >> w;
			if (M[s1]==0){
				M[s1] = cnt;
				cnt++;
			} 
			if (M[s2]==0){
				M[s2] = cnt;
				cnt++;
			}
			a = M[s1];
			b = M[s2];
			edgeList.pb({a,b,w});
			edgeList.pb({b,a,w});
		}
		
		for(int i = 1; i <= N; ++i)dist[i] = 1234567890;
		sort(edgeList.begin(), edgeList.end(), cmp);
		for (auto it : edgeList){
			if (par(it.a) == par(it.b)) continue;
			p[par(it.a)] = par(it.b);
			adjList[it.a].pb(mp(it.b,it.w));
			adjList[it.b].pb(mp(it.a,it.w));
		}
		cin >> s1 >> s2;
		dist[M[s1]] = 1234567891;
		dfs(M[s1]);
		cout << "Scenario #" << cntr << '\n' << dist[M[s2]] << " tons\n\n"; 
		for (int i = 1;i<=N;++i)adjList[i].clear();
	}
}

