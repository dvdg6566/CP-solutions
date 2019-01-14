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
#define SZ(x) (int)x.size()
#define INF 1000000000
bool debug = 0;
struct query{
  int ind,a,b;
  query(int x,int y,int z): ind(x), a(y), b(z) {}
};

vector<query> V;
int N,C,Q,a,b;
int A[200100];
int cli[200100];
int nxt[200100];

struct node {
  int s, e, m, v;
  node *l, *r;
  node(int _s, int _e) {
    s = _s; e = _e; m = (s+e)/2;
    v = INF;
    if (s!=e) {
      l = new node(s, m);
      r = new node(m+1, e);
    }
  }
  void up(int x, int nv) {
    if (s==e) { v=nv; return; }
    if (x>m) r->up(x, nv);
    if (x<=m) l->up(x, nv);
    v = min(l->v, r->v); //Modify the value of v after updating children
  }
  int rmq(int x, int y) {
    if (s==x && e==y) return v;
    if (x>m) return r->rmq(x, y);
    if (y<=m) return l->rmq(x, y);
    return min(l->rmq(x, m), r->rmq(m+1, y));
  }
}*root;

int out[200100];
bool cmp(query a, query b){
  return a.a < b.a;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  if(debug)freopen("input.txt","r",stdin);
  cin >> N >> C >> Q;
  for (int i=0;i<N;++i)cin>>A[i];
  for(int i=0;i<C;++i)cli[i] = -1;
  for (int i=N-1;i>=0;--i){
    nxt[i] = cli[A[i]];
    cli[A[i]] = i;
  }
  if(debug)for(int i=0;i<N;++i)cout<<nxt[i]<<' ';cout<<'\n';
  root = new node (0,N);
  for (int i=0;i<N;++i){
    if (nxt[i] == -1)continue;
    root->up(nxt[i], nxt[i] - i);
    if(debug)cout << "Updating " << nxt[i] << " with " << nxt[i] - i << '\n';
  }
  for (int i=0;i<Q;++i){
    cin>>a>>b;
    V.pb({i,a,b});
  }
  sort(V.begin(),V.end(),cmp);
  int curind = 0;
  for (auto i : V){
    while (i.a > curind){
      if (nxt[curind] == -1){++curind;continue;}
      root->up(nxt[curind], INF);
      if(debug)cout << "Updating " << nxt[curind] << " to " << INF << '\n';
      ++curind;
    }
    out[i.ind] = root->rmq(i.a, i.b);
    if(debug)cout << "Minimum between " << i.a << " and " << i.b << " is " << out[i.ind] << '\n';
  }
  for (int i=0;i<Q;++i){
    if (out[i] == INF)cout<<"-1\n";
    else cout<<out[i]<<'\n';
  }
}
