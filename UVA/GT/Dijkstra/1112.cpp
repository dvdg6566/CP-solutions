#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
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

vpi adjList[1001];
ll dist[1001];
int T,N,E,M,tc,a,b,w;

priority_queue<pi, vector<pi>, greater<pi> > pq;
void dijkstra(int start){ 
	memset(dist, -1, sizeof(dist));
	dist[start] = 0;
	pq.push(mp(0, start));
	while (!pq.empty()) {
	    pi cur = pq.top();
	    pq.pop();
	    int x = cur.s, d = cur.f;
	    if (d > dist[x]) continue;
	    for (auto it:adjList[x]) {
	        int nx = it.f, nd = d+it.s;
	        if(nd>T)continue;
	        if (dist[nx] != -1 && dist[nx] <= nd) continue;
	        dist[nx] = nd;
	        pq.push(mp(nd, nx));
	    }
	}
}

int main(){
	//freopen("input.txt","r",stdin);
	cin>>tc;
	while(tc--){
		cin >> N >> E >> T >> M;
		for (int i = 1; i<=N;++i)adjList[i].clear();
		while(M--){
			cin>>a>>b>>w;
			adjList[b].pb(mp(a,w));
		}
		dijkstra(E);
		a=0;
		for(int i = 1; i <= N; ++i){
			if(dist[i] != -1 && dist[i] <= T)a++;
		}
		cout<<a<<'\n';
		if(tc)cout<<'\n';
	}
}
