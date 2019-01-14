#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
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

vpi adjList[1200];
int N,E,a,b,w,tc;

priority_queue<pi, vector<pi>, greater<pi> > pq;
int dist[1200];

void dijkstra(){
	memset(dist, -1, sizeof(dist));
	dist[0] = 0;
	pq.push(mp(0, 0));
	while (!pq.empty()) {
	    pi cur = pq.top();
	    pq.pop();
	    int x = cur.s, d = cur.f;
	    if (d > dist[x]) continue;
	    for (auto it:adjList[x]) {
	        int nx = it.f, nd = d+it.s;
	        if (dist[nx] != -1 && dist[nx] <= nd) continue;
	        dist[nx] = nd;
	        pq.push(mp(nd, nx));
	    }
	}
}


int main(){
	//freopen("input.txt","r",stdin);
	while(1){
		tc++;
		cin>>N;
		for(int i = 0; i <= 2*N; ++i)adjList[i].clear();
		if(cin.eof())return 0;
		cin>>E;
		for (int i = 0; i < E ; ++i){
			cin>>a>>b>>w;
			// Enter while carrying is 0 to N-1
			// Enter while riding is N to 2N-1
			adjList[N+a].pb(mp(b,w));
			adjList[b].pb(mp(N+a,w));
			adjList[N+b].pb(mp(a,w));
			adjList[a].pb(mp(N+b,w));
		}
		// end is 2N-1
		dijkstra();
		cout<<"Set #" << tc<<'\n';
		if(dist[N-1] == -1)cout<<'?'<<'\n';
		else cout<<dist[N-1]<<'\n';
	}
}
