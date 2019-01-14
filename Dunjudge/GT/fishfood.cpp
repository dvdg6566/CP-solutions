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

vpi adjList[501000];
priority_queue<pi, vector<pi>, greater<pi> > pq;
int dist[501000];

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
	        if (dist[nx] != -1 && dist[nx] <= nd) continue;
	        dist[nx] = nd;
	        pq.push(mp(nd, nx));
	    }
	}
}

int fishfood(int N, int E, int K, int A[], int B[], int T[]) {
	for (int i = 0; i < E; ++i){
		adjList[A[i]].pb(mp(B[i],T[i]));
		adjList[B[i]].pb(mp(A[i],T[i]));
	}
	dijkstra(0);
	for (int i = 0; i < N; ++i)if(dist[i] == -1)dist[i] = INF;
	sort(dist,dist+N);
	if(dist[K-1] == INF)return -1;
    return dist[K-1];
}

static int N, E, K, A[500000], B[500000], T[500000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("input.txt","r",stdin);
    scanf("%d%d%d", &N, &E, &K);
    for ( int i = 0; i < E; i++ ) scanf("%d%d%d", &A[i], &B[i], &T[i]);
    printf("%d\n", fishfood(N, E, K, A, B, T));
    return 0;
}

