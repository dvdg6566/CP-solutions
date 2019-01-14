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

int N,E,Q,a,b,w;
struct edge {
    int a, b, w;
    edge (int _a=0, int _b=0, int _w=0): a(_a), b(_b), w(_w) {}
};
int p[50001], size[50001],res[50001], minEdge[50001];

int par(int x) { return (x==p[x])?x:p[x]=par(p[x]);}
vector<edge> EdgeList;
bool cmp (edge x, edge y) { return x.w > y.w; } //Swap the comparator for maximum

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> N >> E >> Q;
	for (int i = 0; i < N; i++){
		p[i] = i;
		size[i] = 1;
		minEdge[i] = INF;
	}
	for (int i = 0; i < E; ++i){
		cin >> a >> b >> w;EdgeList.pb({a,b,w});
	}
	memset(res,-1,sizeof(res));
	res[1] = 0;
	sort(EdgeList.begin(), EdgeList.end(), cmp);
	for(auto it : EdgeList){
	    if (par(it.a) == par(it.b)) continue;
	    size[par(it.b)] += size[par(it.a)];
	    minEdge[par(it.b)] = min({minEdge[par(it.b)],it.w,minEdge[par(it.a)]});
	    p[par(it.a)] = par(it.b);
	    if (res[size[par(it.b)]] == -1)res[size[par(it.b)]] = minEdge[par(it.b)];
	}
	for (int i = N; i > 0; --i){
		if (res[i+1] == INF)continue;
		if (res[i] == INF)res[i] = -1;
		res[i] = max(res[i],res[i+1]);
	}
	for (int i = 0;i < Q; ++i){
		cin >> a;
		if (res[a] == INF)cout << -1 << '\n';
		else cout << res[a] << '\n';
	}
}

