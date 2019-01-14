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

priority_queue<pi, vector<pi>, greater<pi> > pq;

ll dist[50000];
vpi adjList[50000];

void dijkstra(int start){ 
	memset(dist,-1,sizeof(dist));
	dist[start] = 0;
	pq.push(mp(0, start));
	while (!pq.empty()) {
	    pi cur = pq.top();
	    pq.pop();
	    int x = cur.s, d = cur.f;
	    if (d > dist[x])continue;
	    for (auto it:adjList[x]) {
	        int nx = it.f, nd = d+it.s;
	        if (dist[nx] != -1 && dist[nx] <= nd){continue;}
	        dist[nx] = nd;
	        pq.push(mp(nd, nx));
	    }
	}
}

int N,M,S,T,a,b,w,cnt,tc;

int main(){
	//freopen("input.txt","r",stdin);
	cin>>tc;
	while(tc--){
		cnt++;
		cin>>N>>M>>S>>T;
		for(int i=0;i<N;++i)adjList[i].clear();
		while(M--){
			cin>>a>>b>>w;
			adjList[a].pb(mp(b,w));
			adjList[b].pb(mp(a,w));
		}
		dijkstra(S);
		cout<<"Case #"<<cnt<<": ";
		if(dist[T]==-1)cout<<"unreachable\n";
		else cout <<dist[T] << '\n';
	}
}


