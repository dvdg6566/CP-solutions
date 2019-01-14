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

int dist[100100], X[100100], Z[100100], P[100100];
vpi adjList[100100], R[100100];
int N,E,x,y,a,b,w;
priority_queue<pi,vector<pi>, greater<pi>> pq;
vpi T;

void dijkstra(int start){
	memset(dist,-1,sizeof(dist));
	dist[start] = 0;
	pq.push(mp(0, start));
	while (!pq.empty()) {
	    pi cur = pq.top();
	    pq.pop();
	    int x = cur.s, d = cur.f;
	    if (d > dist[x]) continue;
	    for (auto it:R[x]) {
	        int nx = it.f, nd = d+it.s;
	        if (dist[nx] != -1 && dist[nx] <= nd) continue;
	        dist[nx] = nd;
	        pq.push(mp(nd, nx));
	    }
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> N >> E;
	for (int i = 0; i < N; ++i)cin >> P[i];
	cin >> x >> y;
	for (int i = 0; i < E; ++i){
		cin >> a >> b >> w;
		adjList[a].pb(mp(b,w));
		R[b].pb(mp(a,w));
	}
	dijkstra(0);
	swap(Z,dist);
	dijkstra(x);
	swap(X,dist);
	for (int i = 1; i < N; ++i){
		if (X[i] == -1)continue;
		int w = Z[i] - X[i] - Z[y]; // w is the maximum amount you can charge
		if (w < 0)continue;
		T.pb(mp(w,P[i]));
	}
	sort(T.begin(),T.end());
	reverse(T.begin(),T.end());
	ll res = 0,cnt = 0;
	for (auto i : T){
		cnt += i.s;
		res = max(res,cnt*i.f);
	}
	cout << res;
}
