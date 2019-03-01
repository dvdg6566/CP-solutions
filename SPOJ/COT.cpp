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
ll N,Q,W[120100];
map<ll,ll> M;
vi aList[120100];

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
  /*
  ll rsq(ll x, ll y){
    if (x == s && y == e)return v;
    if (y <= m)return l->rsq(x,y);
    if (x > m)return r->rsq(x,y);
    return l->rsq(x,m) + r->rsq(m+1,y);
  }
  */
}*A[120100];

ll P[120100][20], depth[120100],T;

void dfs(ll x, ll p){
  for (auto i : aList[x]){
    if (i == p)continue;
    // cout<<i<<' '<<W[i]<<' '<<x<<'\n';
    A[i] = new node(0, T-1, W[i], A[x]);
    depth[i] = depth[x] + 1;
    // cout<<i<<' '<<depth[i]<<'\n';
    P[i][0] = x;
    dfs(i,x);
  }
}

ll lca(ll a, ll b){
  if (depth[a]<depth[b])swap(a,b);
  ll h = depth[a] - depth[b];
  for (ll i=0;i<18;++i)if ((1<<i) & h)a = P[a][i];
  assert(depth[a] == depth[b]);
  if (a==b)return a;
  for (ll i=17;i>=0;--i)if (P[a][i] != P[b][i]){a = P[a][i]; b = P[b][i];}
  assert(P[a][0] == P[b][0]);
  return P[a][0];
}

ll query(ll a, ll b, ll k){
  ll c = lca(a,b);
  ll d = P[c][0];
  // cout<<a<<' '<<b<<' '<<c<<' '<<d<<'\n';
  node *x = A[a], *y=A[b], *w=A[c], *z=A[d];
  ll l = 0, u = T-1;
  while (u > l+1){
    // cout<<"Query between " << l <<' ' << (l+u)/2<<": ";
    // cerr<<k<<' '<<l<<' '<<u<<' '<<x->l->v<<' '<<y->l->v<<' '<<w->l->v<<' '<<z->l->v<<'\n';
    // cout<<y->l->s<<' '<<y->l->e<<' '<<y->l->v<<'\n';
    if (x->l->v + y->l->v - w->l->v - z->l->v >= k){
      u = (l+u)/2;
      x=x->l;
      y=y->l;
      z=z->l;
      w=w->l;
    }else {
      l = (l+u)/2+1;
      k -= (x->l->v + y->l->v - w->l->v - z->l->v);
      x=x->r;
      y=y->r;
      z=z->r;
      w=w->r;
    }
  }
  // return l;
  // cout<<x->s<<' '<<x->e<<'\n';
  // cout<<l<<' '<<u<<'\n';
  if (l == u)return l;
  ll cnt = x->l->v+ y->l->v- w->l->v- z->l->v;
  if (cnt>=k)return l;
  return u;
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin>>N>>Q;
  assert(N<=100000);
  for (ll i=1;i<=N;++i){
    cin>>W[i];
    assert(W[i]< 1e18);
    des.pb(W[i]);
  }
  ll a,b,c;
  for (ll i=1;i<N;++i){
    cin>>a>>b;
    aList[a].pb(b);
    aList[b].pb(a);
  }
  sort(ALL(des));
  des.resize(unique(ALL(des)) - des.begin());
  for (ll i=0;i<SZ(des);++i)M[des[i]] = i;
  for (ll i=1;i<=N;++i)W[i] = M[W[i]];
  T = SZ(des);
  A[0] = new node(0,T-1, -1, A[10]);
  A[1] = new node(0, T-1, W[1], A[0]);
  dfs(1, 0);
  for (ll i=1;i<=17;++i){
    for (ll j=2;j<=N;++j){
      if (P[j][i-1] != -1)P[j][i] = P[P[j][i-1]][i-1];
    }
  }
  // for (ll i=1;i<=N;++i)cout<<A[i]->v<<' ';cout<<'\n';
  while(Q--){
    cin>>a>>b>>c;
    cout<<des[query(a,b,c)]<<'\n';
  }
}
