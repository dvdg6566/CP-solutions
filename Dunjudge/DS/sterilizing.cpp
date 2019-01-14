#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef pair<ll, pi> pii;
typedef set<ll> si;
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

ll N,Q,K,a,b,c;
ll A[100100];
deque<ll> G;

struct node{
  ll s,e,m,lazy=0;
  node *l, *r;
  deque<ll> dq;
  node(ll x, ll y){
    s=x;
    e=y;
    m=(x+y)/2;
    if (s == e){
      ll r = A[s];
      while(r){
        dq.pb(r);
        r = r / K;
      }
    }else{
      l = new node (s,m);
      r= new node(m+1,e);
      childupdate();
    }
  }

  void childupdate(){
    dq.clear();
    for (ll i=0;i<max(l->dq.size(), r->dq.size());++i)dq.pb(0);
    for (ll i=0;i<l->dq.size();++i)dq[i] += l->dq[i];
    for (ll i=0;i<r->dq.size();++i)dq[i] += r->dq[i];
  }

  ll query(ll x, ll y){
    value();
    if (x == s && y == e){
      if (dq.size())return dq[0];
      return 0;
    }
    if (x>m) return r->query(x, y);
    if (y<=m) return l->query(x, y);
    return l->query(x, m) + r->query(m+1, y);
  }

  void globalupdate(){
    for (ll i=dq.size();i<G.size();++i)dq.pb(0);
    for (ll i=0;i<G.size();++i){
      dq[i] = dq[i] + G[i];
    }
  }

  void up(ll x, ll val){
    value();
    if (s == e){
      deque<ll> tmp;
      tmp.clear();
      while(val){
        tmp.pb(val);
        val = val / K;
      }
      G.clear();
      for (ll i=0;i<tmp.size()&&i<dq.size();++i){
        G.pb(tmp[i] - dq[i]);
      }
      for (ll i=G.size();i<tmp.size();++i){
        G.pb(tmp[i]);
      }
      for (ll i=G.size(); i<dq.size();++i){
        G.pb(-dq[i]);
      }
      globalupdate();
      return;
    }
    if(x>m)r->up(x,val);
    if(x<=m)l->up(x,val);
    globalupdate();
  }

  void divide(ll x, ll y){
    if (s == x && y == e){
      ++lazy;
      return;
    }
    if (x > m)r -> divide(x,y);
    else if (y <= m)l -> divide(x,y);
    else {l->divide(x,m); r->divide(m+1,y);}
    l->value();
    r->value();
    childupdate();
  }

  ll value(){
    if (s == e){
      while(dq.size() && lazy){
        dq.pop_front();
        --lazy;
      }
      lazy = 0;
      if (dq.size() == 0)return 0;
      return dq[0];
    }
    r->lazy += lazy;
    l->lazy += lazy;
    while (dq.size() && lazy){
      dq.pop_front();
      --lazy;
    } 
    lazy = 0;
    if (dq.size() == 0)return 0;
    return dq[0];
  }
} *root;

struct nd {
  ll s, e, m, v;
  nd *l, *r;
  nd(ll _s, ll _e) {
    s = _s; e = _e; m = (s+e)/2;
    v = 0;
    if (s!=e) {
      l = new nd(s, m);
      r = new nd(m+1, e);
      v = l->v+r->v;
    }else{
      v = A[s];
    }
  }
  void up(ll x, ll nv) {
    if (s==e) { v=nv; return; }
    if (x>m) r->up(x, nv);
    if (x<=m) l->up(x, nv);
    v = l->v + r->v;
  }
  ll rsq(ll x, ll y) {
    if (s==x && e==y) return v;
    if (x>m) return r->rsq(x, y);
    if (y<=m) return l->rsq(x, y);
    return l->rsq(x, m)+r->rsq(m+1, y);
  }
}*rt;

int main(){
  // freopen("input.txt","r",stdin);
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>N>>Q>>K;
  for (ll i=1;i<=N;++i)cin>>A[i];
  if (K == 1){
    rt = new nd(1,N);
    for (ll i=0;i<Q;++i){
      cin>>a>>b>>c;
      if(a==1){
        A[b] = c;
        rt -> up(b,c); 
      }
      if (a == 3){
        cout<<rt->rsq(b,c)<<'\n';
      }
    }
    return 0;
  }
  root = new node(1,N);
  for (ll i=0;i<Q;++i){
    cin>>a>>b>>c;
    if(a==1){
      A[b] = c;
      root -> up(b,c); 
    }
    if (a == 2){
       root -> divide(b,c);
    }
    if (a == 3){
      cout<<root->query(b,c)<<'\n';
    }
  }
}
