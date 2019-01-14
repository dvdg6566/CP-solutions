#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<double,ll> pi;
typedef pair<ll,double> pid;
typedef pair<ll,pi> ppi;
typedef vector<pi> vpi;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MOD 1e9+7
#define lb lower_bound
#define ub upper_bound
#define INF 123456789098765LL

struct node{
	int x,y;
	double r;
	node(int _x=0, int _y=0, double _r=0): x(_x), y(_y), r(_r){}
};

double time(node a, node b){
	double dist = sqrt((double) (a.x-b.x)*(a.x-b.x) + (double) (a.y - b.y)* (a.y - b.y));
	//cout << dist << '\n';
	if (dist < a.r + b.r)return dist/340;
	return (dist - a.r - b.r)/3 + (a.r + b.r) / 340;
}

priority_queue<pi, vector<pi>, greater<pi> > pq;
double dist[510];
vector<pid> adjList[510];

void dijkstra(int start){
	memset(dist, -1, sizeof(dist));
	dist[start] = 0;
	pq.push(mp(0, start));
	while (!pq.empty()) {
	    pi cur = pq.top();
	    pq.pop();
	    int x = cur.s;
	    double d = cur.f;
	    if (d > dist[x]) continue;
	    for (auto it:adjList[x]) {
	        int nx = it.f;
	        double nd = d+it.s;
	        if (dist[nx] != -1 && dist[nx] <= nd) continue;
	        dist[nx] = nd;
	        pq.push(mp(nd, nx));
	    }
	}
}

vector<node> V;
int N,a,b;
double w;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> N;
	for (int i = 0; i < 2; ++i){
		cin >> a >> b;
		V.pb({a,b,0});
	}
	for (int i = 0; i < N; ++i){
		cin >> a >> b >> w;
		V.pb({a,b,w});
	}
	N += 2;
	for (int i = 0; i < N-1; ++i){
		for (int j = i+1; j < N; ++j){
			if (i==0&&j==1)continue;
			double t = time(V[i],V[j]);
			adjList[i].pb(mp(j,t));
			adjList[j].pb(mp(i,t));
			//cout << i << ' ' << j << ' ' << t << '\n';
		}
	}
	dijkstra(0);
	printf("%.1lf",roundf(dist[1]*10)/10);
}
