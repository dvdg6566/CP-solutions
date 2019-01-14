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


struct edge {
    int start, end, d;
    edge (int _start=0, int _end=0, int _d=0): start(_start), end(_end), d(_d) {}
};

map<string, int> M;
vector<edge> adjList[120];
int N,E,a,b,c;
string S;
vector<pi> V;
int dist[120],p[120];
priority_queue<pi,vector<pi>,greater<pi>> pq;

void dijkstra(pi x){
	memset(dist,-1,sizeof(dist));
	memset(p,-1,sizeof(p));
	dist[x.f] = x.s;
	pq.push(mp(x.s,x.f));
	while(pq.size()){
		pi cur=pq.top();
		pq.pop();
		int x = cur.s, d = cur.f;
	    if (d > dist[x]) continue;
	    for (auto it:adjList[x]) {
			if(it.start < d)continue;
	        int nx = it.d, nd = it.end;
	        if (dist[nx] != -1 && dist[nx] <= nd) continue;
	        dist[nx] = nd;
	        p[nx] = x;
	        pq.push(mp(nd, nx));
	    }
	}
}

int main(){
	//freopen("input.txt","r",stdin);
	while(1){
		M.clear();
		cin>>N;
		if(!N)return 0;
		for (int i = 1; i <= 119; ++i)adjList[i].clear();
		for (int i = 1; i <= N; ++i){
			cin>>S;
			M[S] = i;
		}
		cin >> E;
		
		for (int i = 0; i < E; ++i){
			cin >> a;
			V.clear();
			for (int j = 0; j < a; ++j){
				cin>>b>>S;
				V.pb(mp(M[S],b));
			}
			for (int j = 0; j < a-1; ++j){
				if(V[j].s>V[j+1].s)continue;
				adjList[V[j].f].pb({V[j].s,V[j+1].s,V[j+1].f});
			}
		}
		cin >> a;
		cin>>S;b = M[S];
		cin>>S;c=M[S];
		dijkstra(mp(b,a));
		if(dist[c] == -1){cout<<"No connection\n";continue;}
		int d = c;
		while(p[d]!=b){d = p[d];}
		int ans = 0;
		for (auto i : adjList[b]){
			if (i.d == d && i.end == dist[d])ans = max(ans,i.start);
		}
		int tmp = ans, res = dist[c];
		for (int i = tmp; i <= 2400; ++i){
			dijkstra(mp(b,i));
			if (dist[c] > res||dist[c] == -1)break;
			else ans++;
		}
		if(ans<10)cout<<'0';
		if(ans<100)cout<<'0';
		if(ans<1000)cout<<'0';
		cout << ans-1 << ' ';
		if(res<10)cout<<'0';
		if(res<100)cout<<'0';
		if(res < 1000)cout<<'0';
		cout << res << '\n';
	}
}
