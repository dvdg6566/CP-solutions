#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dl;
typedef pair<dl,dl> pi;
typedef vector<pi> vpi;
typedef vector<int> vi;
typedef pair<int,dl> pd;

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
int N,M,V;
vpi nodes;
double a,b,H;
vector<pi> adjList[10100];
double dist[10010];

double dst(pi a, pi b){
	return sqrt((a.f-b.f)*(a.f-b.f)+(a.s-b.s)*(a.s-b.s));
}


void dijkstra(int start){
	dist[start] = 0;
	pq.push(mp(0, start));
	while (!pq.empty()) {
	    pi cur = pq.top();
	    pq.pop();
	    int x = cur.s;
	    dl d = cur.f;
	    if (d > dist[x]) continue;
	    for (auto it:adjList[x]) {
	        int nx = it.f;
	        dl nd = d+it.s;
	        if (dist[nx] != -1 && dist[nx] <= nd) continue;
	        dist[nx] = nd;
	        pq.push(mp(nd, nx));
	    }
	}
}


int main(){
	//freopen("input.txt","r",stdin);
	while(1){
		cin >> N >> M;
		if(N==0)break;
		nodes.clear();
		cin >> V;
		for (int i = 0; i < V+10; ++i)adjList[i].clear();
		for (int i = 0; i <= V+10; ++i)dist[i] = -1;
		nodes.pb(mp((double)0,(double)0));
		for (int i = 0; i < V; ++i){
			cin >> a >> b;
			nodes.pb(mp(a,b));
		}
		cin >> H;
		nodes.pb(mp((double)N,(double)M));
		for (int i = 0; i < V+2; ++i){
			for(int j = 0; j < V+2; ++j){
				if(i==j)continue;
				double d = dst(nodes[i],nodes[j]);
				if(d>1.5)continue;
				adjList[i].pb(mp(j,d));
			}
		}
		dijkstra(0);
		if(dist[V+1] <= H && dist[V+1] != -1)cout << "I am lucky!\n";
		else cout << "Boom!\n";
	}
}
