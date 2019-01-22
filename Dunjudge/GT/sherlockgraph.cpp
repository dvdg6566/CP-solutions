#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<int, pi> pii;
typedef set<int> si;
typedef vector<pi> vpi;
typedef double dl;
#define mp make_pair
#define pb push_back
#define f first
#define s second
ll MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
#define INF 10000000
#define SZ(x) x.size()
#define ALL(x) x.begin(),x.end()

int N,M,Q,a,b,c,d;
vi adjList[100100];
si compressed[100100];
int lowlink[100100], depth[100100], p[100100];
int BCC[100100];
stack<int> stk;

void dfs(int x){
	depth[x] = lowlink[x] = a++;
	stk.push(x);
	for (auto it : adjList[x]){
    if(p[it]!=-1){
      if(p[x]!=it)lowlink[x] = min(lowlink[x], lowlink[it]);
      continue;
    }
    p[it] = x;
    dfs(it);
    lowlink[x] = min(lowlink[x], lowlink[it]);
	}
	if (lowlink[x] == depth[x]){
		while (stk.top() != x){
			BCC[stk.top()] = b;
			stk.pop();
		}
		stk.pop();
		BCC[x] = b++;
	}
}

vpi edgeList;
int heavy[100100], head[100100], pos[100100];
int cur;

int dfs3(int x){
  int size = 1;
  int mchild = 0;
  for (auto i : compressed[x]){
    if (p[x] == i)continue;
    p[i] = x;
    depth[i] = depth[x] + 1;
    int cs = dfs3(i);
    size += cs;
    if (cs > mchild){
      mchild = cs;
      heavy[x] = i;
    }
  }
  return size;
}

void decompose(int x, int h){
//cerr<<x<<'\n';
  head[x] = h; pos[x] = cur++;
  if (heavy[x] != -1)decompose(heavy[x], h);
  for (auto i : compressed[x]){
    if (i == p[x])continue;
    if (i == heavy[x])continue;
    decompose(i,i);
  }
}

int fw[100010], fw2[100010];
void update(int x, int y, int v) { //inclusive
    for (int tx=x; tx <= N; tx += tx&(-tx)) fw[tx] += v, fw2[tx] -= v*(x-1);
    for (int ty=y+1; ty <= N; ty += ty&(-ty)) fw[ty] -= v, fw2[ty] += v*y; 
}
int sum (int x) {
    int res = 0;
    for (int tx=x; tx; tx -= tx&(-tx)) res += fw[tx]*x + fw2[tx];
    return res;
}
int range_sum(int x, int y) { //inclusive
    return sum(y)-sum(x-1);
}


void add(int a, int b, int v){
  if (depth[a] > depth[b])swap(a,b);
  for (;head[a]!=head[b];b=p[head[b]]){
    if (depth[head[a]] > depth[head[b]])swap(a,b);
    update(pos[head[b]], pos[b], v);
   // cout << "Updating " << pos[head[b]] << ' ' << pos[b] << " with " << v << '\n';
  }
  if (depth[a] > depth[b])swap(a,b);
  update(pos[a]+1, pos[b], v);
 // cout << "Updating " << pos[a]+1 << ' ' << pos[b] << " with " << v << '\n';
}

int find_dist(int a, int b){
  int res = 0;
  if (depth[a] > depth[b])swap(a,b);
  for (;head[a]!=head[b];b=p[head[b]]){
    if (depth[head[a]] > depth[head[b]])swap(a,b);
    res += range_sum(pos[head[b]], pos[b]);
    //cout << "Query " << pos[head[b]]<<' '<<pos[b]<<'\n';
  }
  if (depth[a] > depth[b])swap(a,b);
  res += range_sum(pos[a]+1, pos[b]);
  //cout<<"Query " << pos[a]+1 << ' ' << pos[b] <<'\n';
  return res;
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin >> N >> M >> Q;
  for (int i=0;i<M;++i){
    cin>>a>>b;
    adjList[a].pb(b);
    adjList[b].pb(a);
    edgeList.pb(mp(a,b));
  }
  memset(p,-1,sizeof(p));
  p[1] = 0;
  b=1;
  dfs(1);
  // for (int i=1;i<=N;++i)cout<<BCC[i]<<' ';cout<<'\n';
  int bcc = b;
  for (auto i : edgeList){
    a = BCC[i.f];
    b = BCC[i.s];
    if (a!=b){
      compressed[a].insert(b);
      compressed[b].insert(a);
    }
  }
  memset(depth,0,sizeof(depth));
  memset(p,0,sizeof(p));
  memset(heavy,-1,sizeof(heavy));
  cur = 1;
  dfs3(1);
  decompose(1,1);
  if (bcc> 1)update(2,bcc,1);
  for (int i=0;i<Q;++i){
    cin>>a>>b>>c>>d;
    a=BCC[a];
    b=BCC[b];
    c=BCC[c];
    d=BCC[d];
    if (c == d){
      cout<<0<<'\n';
      continue;
    }
    add(a,b,-1);
    cout<<find_dist(c,d)<<'\n';
    add(a,b,1);
  }
}
