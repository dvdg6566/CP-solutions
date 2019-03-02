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
ll INF = 1e15;
ll MOD = 1e9;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (ll)x.size()
#define ALL(x) x.begin(),x.end()

vi des;
int T;
map<int,int> M;

struct node{
  ll s,e,m,v;
  node *l, *r;
  node(ll _s, ll _e, ll up, node *previous) { // Up refers to the index to update. Sometimes may need to add entry val 
    s = _s; e = _e; m = (s+e)/2; v = 0;
    if (up == -1){ // Means that this is the original segment tree
      if (s == e){
        return;
      }
      l = new node(s,m,up,previous);
      r = new node(m+1, e, up,previous);
      return;
    }
    if (s == e){
      v = (previous->v)+1;
      // cout<<s<<' '<<v<<'\n';
      return;
    }
    if (up <= m){
      l = new node(s, m, up,previous->l);
      r = previous->r;
    }else{
      l = previous->l;
      r = new node(m+1,e, up,previous->r);
    }
    v = l->v + r->v;
 }
}*A[120100];

int V[120100],N,Q,a,b,c;

int ask(int a, int b, int k){
  node *x = A[b], *y = A[a-1];
  // cout<<"Query " <<a <<' '<<b-1<<'\n';
  int l = 0, u = T-1;
  while(u>l+1){
    // cout<<l<<' '<<u<<' '<<x->s<<' '<<x->e<<'\n';
    if (x->l->v - y->l->v >= k){
      u = (l+u)/2;
      x = x->l;
      y = y->l;
    }else{
      k -= (x->l->v - y->l->v);
      l = (l+u)/2+1;
      x = x->r;
      y = y->r;
    }
  }
  // cout<<l<<' '<<u<<'\n';
  if (l == u)return l;
  if (x->l->v - y->l->v >= k)return l;
  return u;
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin>>N>>Q;
  for (int i=1;i<=N;++i){
    cin>>V[i];
    des.pb(V[i]);
  }
  sort(ALL(des));
  des.resize( unique(ALL(des)) - des.begin());
  T = SZ(des);
  for (int i=0;i<T;++i)M[des[i]] = i;
  for (int i=1;i<=N;++i){
    V[i] = M[V[i]];
  }
  A[0] = new node(0, T-1, -1, A[10]);
  for (int i=1;i<=N;++i){
    A[i] = new node(0,T-1,V[i], A[i-1]);
    // cout<<i<<' '<<V[i]<<'\n';
  }
  while(Q--){
    cin>>a>>b>>c;
    cout<<des[ask(a,b,c)]<<'\n';
  }
}
