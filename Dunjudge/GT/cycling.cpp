#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef pair<ll,pi> ppi;
typedef vector<pi> vpi;
typedef double dl;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MOD 1e9+7
#define lb lower_bound
#define ub upper_bound
#define INF 1000000000

int N,M,S,a,b,w;
ll minimax[501000];
map<ll,ll> adjList[501000];

priority_queue<pi, vector<pi>, greater<pi> > pq;
priority_queue<ppi, vector<ppi>, greater<ppi> > pq2;

void fill_minimax(int start){
	memset(minimax, -1, sizeof(minimax));
	minimax[start] = 0;
	pq.push(mp(0, start));
	while (!pq.empty()){
	    pi cur = pq.top();
	    pq.pop();
	    ll x = cur.s, d = cur.f;
	    if (d > minimax[x]) continue;
	    for (auto it:adjList[x]) {
	        ll nx = it.f, nd = max(d,it.s);
	        if (minimax[nx] != -1 && minimax[nx] <= nd) continue;
	        minimax[nx] = nd;
	        pq.push(mp(nd, nx));
	    }
	}
}

map<int,bool> Mp;
ll dist[501000];

void dijkstra(int start){
	memset(dist, -1, sizeof(dist));
	dist[start] = 0;
	pq2.push(mp(0, mp(start, 0)));
	while (!pq2.empty()) {
	    ppi cur = pq2.top();
	    pq2.pop();
	    ll x = cur.s.f, d = cur.f, m = cur.s.s;
	    if (d > dist[x]) continue;
	    assert(m >= minimax[x]);
	    if (m == minimax[x] && x != S)Mp[x] = 1;
	    for (auto it:adjList[x]) {
	        ll nx = it.f, nd = d+it.s, nm = max(m,it.s);
	        if (dist[nx] != -1 && dist[nx] <= nd) continue;
	        dist[nx] = nd;
	        pq2.push(mp(nd, mp(nx,nm)));
	    }
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> N >> M >> S;
	while(M--){
		cin >> a >> b >> w;
		adjList[a][b] = w;
		adjList[b][a] = w;
	}
	//Firstly, we greedily choose minimax.
	fill_minimax(S);
	dijkstra(S);
	for (auto i : Mp){
		cout << i.f << ' ';
	}
}
