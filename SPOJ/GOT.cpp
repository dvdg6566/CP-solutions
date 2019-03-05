#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef pair<ll,pi> pii;
typedef vector<pi> vpi;
typedef set<ll> si;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define f first
#define s second
ll INF = 1e18;
ll MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (ll)x.size()
#define ALL(x) x.begin(),x.end()


struct node{
  int s,e,m,v;
  node *l, *r;
  node(int _s, int _e, int up, node *previous) { // Up refers to the index to update. Sometimes may need to add entry val 
    s = _s; e = _e; m = (s+e)/2;
    if (up == -1){ // Means that this is the original segment tree
      if (s == e){
        v = 0;
        return;
      }
      l = new node(s,m,up,previous);
      r = new node(m+1, e, up, previous);
      return;
    }
    if (s == e){
      v = previous->v + 1;
      return;
    }
    if (up <= m){
      l = new node(s, m, up, previous->l);
      r = previous->r;
    }else{
      l = previous->l;
      r = new node(m+1,e, up, previous->r);
    }
  }
 int query(int a){
      if (s == e)return v;
      if (a <= m)return l->query(a);
      return r->query(a);
    }

}*A[100100], *root;

int N,Q,a,b,c,cnt,T;
map<int,int> M;
vi aList[100100];
int V[100100], p[100100][20], depth[100100];

void dfs(int x){
  for (auto i : aList[x]){
    if (i == p[x][0])continue;
    A[i] = new node(1, cnt, V[i], A[x]);
    p[i][0] = x;
    depth[i] = depth[x] + 1;
    dfs(i);
  }
}

int lca(int a, int b){
  if (a == b)return a;
  if (depth[a] < depth[b])swap(a,b);
  int h = depth[a] - depth[b];
  for (int i=0;i<18;++i){
    if (h & (1<<i))a = p[a][i];
  }
  if (a == b)return a;
  for (int i=17;i>=0;--i)if (p[a][i] != p[b][i]){a = p[a][i]; b = p[b][i];}
  return p[a][0];
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  // freopen("input.txt","r",stdin);
  while(1){
  cin>>N;
  if (cin.eof())return 0;
  cin>>Q;
  M.clear();
  for (int i=1;i<=N;++i){
    aList[i].clear();
    cin>>V[i];
    if (M[V[i]] == 0)M[V[i]] = ++cnt;
    V[i] = M[V[i]];
  }
  int T = cnt;
  for (int i=1;i<N;++i){
    cin>>a>>b;
    aList[a].pb(b);
    aList[b].pb(a);
  }
  memset(p,0,sizeof(p));
  A[0] = new node(1,cnt,-1, root);
  A[1] = new node(1, cnt, V[1], A[0]);
  // for (int i=1;i<=N;++i)cout<<V[i]<<' ';cout<<'\n';
  dfs(1);
  p[1][0] = 0;
  for (int i=1;i<18;++i){
    for (int j=2;j<=N;++j){
      if (p[j][i-1]) p[j][i] = p[p[j][i-1]][i-1];
    }
  }
  for (int i=0;i<Q;++i){
    cin>>a>>b>>c;
    if (M[c] == 0){cout<<"NotFind\n";continue;}
    c = M[c];
    int rep = A[a]->query(c) + A[b]->query(c) - 2*A[p[lca(a,b)][0]]->query(c);
    if (rep)cout<<"Find\n";
    else cout<<"NotFind\n";
  }
  }
}
