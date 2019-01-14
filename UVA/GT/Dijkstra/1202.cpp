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

vpi adjList[50000];

int m,n,a,b,c,d,z;
double gg,hh;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int dist[50000];
priority_queue<pi, vector<pi>, greater<pi> > pq;

int cnv(pi a){
	return a.f*200 + a.s;
}

void update (pi a, pi b, int w){
	int x = cnv(a), y = cnv(b);
	//cout << "UPDATED " << x << ' ' << y << " to " << w << '\n';
	for (int i = 0; i < adjList[x].size(); ++i){
		pi j = adjList[x][i];
		if(j.f==y){
			adjList[x][i].s = w;
		}
	}
}

void dijkstra(int start){
	memset(dist, -1, sizeof(dist));
	dist[start] = 0;
	pq.push(mp(0, start));
	while (!pq.empty()) {
	    pi cur = pq.top();
	    pq.pop();
	    int x = cur.s, d = cur.f;
	    if (d > dist[x]) continue;
	    if(x == z){
			while(pq.size())pq.pop();
			return;
		}
	    for (auto it:adjList[x]) {
			if(it.s==INF)continue;
	        int nx = it.f, nd = d+it.s;
	        if (dist[nx] != -1 && dist[nx] <= nd) continue;
	        dist[nx] = nd;
	        pq.push(mp(nd, nx));
	    }
	}
}

int main(){
	freopen("input.txt","r",stdin);
	while(1){
		for (int i = 0; i < 40000; ++i)adjList[i].clear();
		cin>>m>>n;
		if(m==-1&&n==-1)return 0;
		for (int i = 0; i < 200; ++i){
			for (int j = 0; j < 200; ++j){
				for (int k = 0; k < 4; ++k){
					int nd = i+dx[k], nx = j + dy[k];
					if(nd<0||nx<0)continue;
					if(nx>=200||nd>=200)continue;
					int x = cnv(mp(i,j)), y = cnv(mp(nd,nx));
					adjList[x].pb(mp(y,0));
				}
			}
		}
		for(int i = 0; i < m; ++i){
			cin >> a >> b >> c >> d;
			if(c==0){
				for (int j = 0; j < d; ++j){
					int x = j + a;
					// upper is (x,b); --> 200*x+b
					// lower is (x,b-1); --> 200*x+b-1
					update(mp(x,b),mp(x,b-1),INF); // No route 
					update(mp(x,b-1),mp(x,b),INF); // No route 
				}
			}else{
				for (int j = 0; j < d; ++j){
					int x = j + b;
					// left is (a-1,x) --> 200*(a-1)+x
					// right is (a,x) --> 200*x+a
					update(mp(a-1,x),mp(a,x),INF); // No route
					update(mp(a,x),mp(a-1,x),INF); // No route
				}
			}
		}
		
		for (int i = 0; i < n; ++i){
			cin >> a >> b >> c;
			if(c==0){
				// top is (a,b);
				update(mp(a,b),mp(a,b-1),1);
				update(mp(a,b-1),mp(a,b),1);
			}else{
				// right is (a-1,b);
				update(mp(a-1,b),mp(a,b),1);
				update(mp(a,b),mp(a-1,b),1);
			}
		}
		// dijkstra from (0,0) to (x,y);
		cin>>gg>>hh;
		z = cnv(mp(floor(gg),floor(hh)));
		if(gg>199||hh>199){cout<<0<<'\n';continue;}
		dijkstra(0);
		cout<< dist[z] << '\n';
	}
}
