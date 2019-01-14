#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
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

int N,E,Q,a,b,H,W;
int p[200100][18], depth[200100];
int D[200100][18];
int pp[200100];
vpi adjList[200100];
string st;
int par(int x) { return (x==pp[x])?x:pp[x]=par(pp[x]);}
void merge(int a, int b) {pp[par(a)] = par(b);}
int G[2010][2010];
pi bfs[2010][2010];

void dfs(int x){
  for (auto i : adjList[x] ){
	if (p[i.f][0] != -1)continue;
	depth[i.f] = depth[x] + 1;
	p[i.f][0] = x;
	D[i.f][0] = i.s;
	dfs(i.f);
  }
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
	for (int i = 17; i >= 0; i--){
		if (p[a][i] != p[b][i]){
			a = p[a][i];
			b = p[b][i];
		}
	}
	return p[a][0];
}

int fd(int c, int d){ // Distance from c to its d-th parent
  int ans = 0;
  for (int i = 0; i < 20; i++) {
    if (((1 << i) & d) > 0) {
      if (c==-1) return -1;
      ans = max(ans,D[c][i]);
      c = p[c][i];
    }
  }
  return ans;
}

queue<pi> pq;
queue<pair<int,pi>> delay;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin >> H >> W >> N >> Q;
  for (int i = 0; i < H; ++i){
    cin >> st;
    for (int j=0;j<W;++j){
      bfs[i][j] = mp(-1,-1);
      if (st[j] == '#')G[i][j] = -1;
    }
  }
  for (int i = 0;i < N; ++i){
    pp[i] = i;
    cin >> a >> b;
    --a;--b;
    pq.push(mp(a,b));
    bfs[a][b] = mp(i,0);
  }
  int wgt = 0;
  while(pq.size()){
    pi cur = pq.front();
      // cout << cur.f << ' ' << cur.s << ' ' << bfs[cur.f][cur.s].s << '\n';
    if (bfs[cur.f][cur.s].s != wgt){
      wgt = bfs[cur.f][cur.s].s;
      // Must empty delay queue
      while(delay.size()){
        int t = delay.front().s.f;
        int cn = delay.front().s.s;
        int wt = delay.front().f;
        delay.pop();
        if (par(t) == par(cn))continue;
        adjList[t].pb(mp(cn, wt + 1));
        adjList[cn].pb(mp(t,wt+1));
        merge(cn,t);
      }
    }
    pq.pop();
    for (int k = 0; k < 4; ++k){
      int cx = cur.f+dx[k]; int cy = cur.s+dy[k];
      if (cx<0||cy<0||cx>=H||cy>=W)continue;
      if (G[cx][cy] == -1)continue;
      if(bfs[cx][cy].f != -1){
        int t = bfs[cx][cy].f, wt = bfs[cx][cy].s + bfs[cur.f][cur.s].s;
        int cn = bfs[cur.f][cur.s].f;
        if (par(t) == par(cn))continue;
        if (wt%2){
          delay.push(mp(wt,mp(t,cn)));
          continue;
        }
        // cout << t << ' ' << cn << ' ' << wt+1 << '\n';
        adjList[t].pb(mp(cn, wt + 1));
        adjList[cn].pb(mp(t,wt+1));
        merge(cn,t);
        continue;
      }
      bfs[cx][cy] = bfs[cur.f][cur.s];
      bfs[cx][cy].s++;
      pq.push(mp(cx,cy));
    }
  }
  /*
  cout << '\n'; 
  for (int i =0;i<H;++i){
    for (int j=0;j<W;++j){
      cout << bfs[i][j].f << ' ';
    }cout << '\n';
  }
  cout << '\n';
  for (int i =0;i<H;++i){
    for (int j=0;j<W;++j){
      cout << bfs[i][j].s << ' ';
    }cout << '\n';
  }
  for (int i=0;i<N;++i){
    cout<<"Printing neighbours of MST of node " << i << '\n';
    for (auto i : adjList[i])cout << i.f << ' ' << i.s << '\n';
  }
  return 0;
  */
	for (int i = 0; i < N; ++i)p[i][0] = -1;
// 	dfs(0);
 	for (int i =0; i < N; ++i){
 	    if(p[i][0] == -1){
 	        dfs(i);
 	    }
 	}
    for (int i = 1; i < 18; i++){
      for (int j = 0; j < N; j++){
        if (p[j][i-1] == -1) {
			p[j][i] = -1;
			D[j][i] = -1;
		}
        else {
			p[j][i]=p[p[j][i-1]][i-1];
			D[j][i] = max(D[p[j][i-1]][i-1], D[j][i-1]);
		}
     }
   }
   for (int i = 0; i < Q; ++i){
	  cin >> a >> b;
    --a;--b;
    if (par(a) != par(b)){cout << -1 << '\n';continue;}
	  int l = LCA(a,b);
	  cout << max(fd(a,depth[a] - depth[l]), fd(b,depth[b]-depth[l]))-1 << '\n';
	}
}
