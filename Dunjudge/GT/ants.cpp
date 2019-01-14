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
#define INF 123456789098765LL

// Use a postorder sequence for nodes
// Fenwicktree to update
// Querying use LCA to check that distance between the nodes not close to infinity

int M[100001]; // Maps the original index to preorder index

struct edge {
    int a, b, w, safe;
    edge (int _a=0, int _b=0, int _w=0, int _safe=0): a(_a), b(_b), w(_w), safe(_safe) {}
};

int N,E;
vector<edge> EdgeList;
vpi adjList[100001]; // Adjacency list and LCA are static
ll dist[100001];
int start[100001], last[100001], par[100001], depth[100001];
bool visited[100001];
int ind = 1;
int p[1000001][20];

void update(ll x, ll y, ll v) { // inclusive
	//cout << "updated from " << x << " to " << y << " by " << v << '\n';
	x--;
	for(; y; y-=y&(-y)) dist[y] += v;
	for(; x; x-=x&(-x)) dist[x] -= v;
}

ll query(ll x) {
    ll res = 0;
    //cout << "query from " << x;
    for (; x<=N; x+=x&(-x)) res += dist[x];
    //cout << " with a result " << res << '\n';
    return res;
}

void dfs(ll x){
	int cur = query(M[x]);
	for (auto it : adjList[x]){
		if(visited[it.f])continue;
		visited[it.f] = 1;
		par[it.f] = x;
		depth[it.f] = depth[x] + 1;
		update(M[it.f],M[it.f],cur + it.s + 1); // because at first it is -1
		dfs(it.f);
	}
}

void inorder(int x){
	M[x] = ind;
	start[x] = ind;
	++ind;
	for (auto i : adjList[x]){
		if(M[i.f] != -1)continue;
		inorder(i.f);
	}
	last[x] = ind-1;
}

int LCA(int a, int b){
	if (a == b)return a;
	if (depth[a] < depth[b])swap(a,b);
	ll h = depth[a]-depth[b];
	for (ll i = 0; i < 18; i++) {
	  if (((1 << i) & h) > 0) { 
		a = p[a][i];
	  }
	}
	if (a == b)return a;
	for (ll i = 17; i >= 0; i--){
		if (p[a][i] != p[b][i]){
			a = p[a][i];
			b = p[b][i];
		}
	}
	return p[a][0];
}

void tree(int _N, int _E, int A[], int B[], int D[]){
	N = _N;
	E = _E;
	for (int i = 0; i < E; ++i){
		EdgeList.pb({A[i],B[i],D[i],1});
		adjList[A[i]].pb(mp(B[i],D[i]));
		adjList[B[i]].pb(mp(A[i],D[i]));
	}
	memset(M,-1,sizeof(M));
	memset(par,-1,sizeof(par));
	memset(depth,-1,sizeof(depth));
	depth[0] = 0;
	update(1,N,-1);
	M[0] = 0;
	update(1,1,1); // set distance to 1 to 0
	visited[0] = 1;
	inorder(0);
    dfs(0);
    for (int i=0;i<N;i++) p[i][0]=par[i];
	for (int i = 1; i < 18; i++){
		for (int j = 0; j < N; j++){
			if (p[j][i-1] == -1) p[j][i] = -1;
			else p[j][i]=p[p[j][i-1]][i-1];
		}
	}
    return;
}

void adjust(int e, int v) {
	int x = EdgeList[e].b;
	if(EdgeList[e].safe)update(start[x],last[x],v-EdgeList[e].w);
	EdgeList[e].w = v;
    return;
}

void safe(int e) {
    int x = EdgeList[e].b;
	update(start[x],last[x],EdgeList[e].w - INF);
	EdgeList[e].safe = 1;
	return;
}

void dangerous(int e) {
	int x = EdgeList[e].b;
	//cout << "Updating " << x << '\n';
	update(start[x],last[x], INF - EdgeList[e].w);
	EdgeList[e].safe = 0;
    return;
}

int energy(int x, int y) {
    ll ya = query(M[y]);
    ll xa = query(M[x]);
    ll za = query(M[LCA(x,y)]);
    if (abs(xa-za) > 0.9*INF)return 0;
    if (abs(ya-za) > 0.9*INF)return 0;
    return ya-xa;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("input.txt","r", stdin);
    int n, e, q, a[200005], b[200005], d[200005];
    scanf("%d%d%d", &n, &e, &q);
    for ( int i = 0; i < e; i++ ) scanf("%d%d%d", &a[i], &b[i], &d[i]);
    tree(n, e, a, b, d);
    for ( int i = 0; i < q; i++ ) {
        int op, a, b;
        scanf("%d", &op);
        if ( op == 0 ) {
            scanf("%d%d", &a, &b);
            printf("%d\n", energy(a, b));
        }
        else if ( op == 1 ) {
            scanf("%d%d", &a, &b);
            adjust(a, b);
        }
        else if ( op == 2 ) {
            scanf("%d", &a);
            safe(a);
        }
        else if ( op == 3 ) {
            scanf("%d", &a);
            dangerous(a);
        }
    }
}
