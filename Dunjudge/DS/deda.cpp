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
#define INF 1000000000
#define SZ(x) x.size()
#define ALL(x) x.begin(),x.end()


struct node {
  int s, e, m, v;
  node *l, *r;
  set<int> val;
  node(int _s, int _e) {
    s = _s; e = _e; m = (s+e)/2;
    v = 0;
    val.insert(INF);
    if (s!=e) {
      l = new node(s, m);
      r = new node(m+1, e);
    }
  }
  void up(int x, int nv) {
      val.insert(nv);
    if (s==e) {
      return;
    }
    if (x>m) r->up(x, nv);
    if (x<=m) l->up(x, nv);
  }
  int query(int x, int y, int B) {
    if (s==x && e==y){
      return *val.lb(B);
    }
    if (x>m) return r->query(x, y,B);
    if (y<=m) return l->query(x, y,B);
    return min(l->query(x, m, B), r->query(m+1, y,B));
  }
}*root;

int N,Q;
char C[200100];
int A[200100], B[200100];
vi V;
map<int,int> M;

int main(){
  // freopen("input.txt","r",stdin);
  cin>>N>>Q;
  for (int i=0;i<Q;++i){
    cin>>C[i]>>A[i]>>B[i];
    V.pb(A[i]);  
  }
  sort(ALL(V));
  unique(ALL(V));
  int cnt;
  for (cnt=0;cnt < V.size();++cnt){
    M[V[cnt]] = cnt;
  } 
  root = new node(0,cnt);
  for (int i=0;i<Q;++i){
    if (C[i] == 'M'){
      root -> up(M[A[i]], B[i]);
    }else{
      int x = root -> query(0, M[A[i]], B[i]);
      if (x != INF)cout<<x<<'\n';
      else cout << "-1\n";
    }
  }
}
