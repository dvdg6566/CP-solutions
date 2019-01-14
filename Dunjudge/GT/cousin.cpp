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
vi adjList[200001], D[200001];
int depth[200001];
int pre[200001], post[200001];
int p[200001][20];
int c;

void dfs(int x){
	++c;
	pre[x] = c;
	if (!adjList[x].size())return;
	for (auto i : adjList[x]){
		depth[i] = depth[x] + 1;
		dfs(i);
	}
	post[x] = c;
}

int fp(int c, int d){
  for (int i = 0; i < 20; i++) {
    if (((1 << i) & d) > 0) {
      if (c==-1) return -1;
      c = p[c][i];
    }
  }
  return c;
}

void init(int N, int P[]) {
	for (int i = 1; i < N; ++i)adjList[P[i]].pb(i);
	memset(pre,-1,sizeof(pre));
	memset(post,-1,sizeof(post));
	memset(depth,-1,sizeof(depth));
	depth[0] = 1;
	dfs(0);
	for (int i = 0; i < N; ++i){
		int x = pre[i];
		D[depth[i]].pb(x);
	}
	int R = max(0,*max_element(depth,depth+N));
	for (int i = 0; i <= R; ++i)sort(D[i].begin(),D[i].end());
    for (int i = 0; i < N; ++i) p[i][0] = P[i];
    for (int i = 1; i < 20; i++){
      for (int j = 0; j < N; j++){
        if (p[j][i-1] == -1) p[j][i] = -1;
        else p[j][i]=p[p[j][i-1]][i-1];
     }
   }
}

int count_cousins(int X, int K) {
   int par = fp(X,K);
   int l = depth[par] + K;
   int r = ub(D[l].begin(),D[l].end(),post[par]) - lb(D[l].begin(),D[l].end(),pre[par] + 1) - 1;
   return r;
}

int main() {
	freopen("input.txt","r",stdin);
	int N, Q;
	scanf("%d%d", &N, &Q);
	int P[N];
	for (int i = 0; i < N; i++) scanf("%d", &P[i]);
	init(N, P);
	for (int i = 0; i < Q; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", count_cousins(a, b));
	}
}
