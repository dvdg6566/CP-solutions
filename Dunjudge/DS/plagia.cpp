#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MOD 1e9+7
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()

ll A[100100];
ll N,Q,a,b,c,d;

struct node{
  ll s,e,m,lazy;
  int v[33];
  ll out;
  node *l, *r;
  node (int _s, int _e){
    memset(v,0,sizeof(v));
    s = _s;
    e = _e;
    lazy = out = 0;
    m = (s+e)/2;
    if (s == e){
      out = A[s];
      for (int i=0;i<33;++i) if ( (1LL << i) & out )v[i] = 1;
    }else{
      l = new node(s, m);
      r = new node(m+1, e);
      for (int i=0;i<33;++i)v[i] = l->v[i] + r->v[i];
      out = l->out + r->out;
    }
  }
  ll query(ll x, ll y){
     value();
     if (x == s && y == e){
       return out;
     }
     if (x > m)return r->query(x,y);
     if (y <= m)return l->query(x,y);
     return l->query(x,m) + r->query(m+1,y);
  }
  void up(ll x, ll y, ll z){
    if (s == x && y == e){
      // cout << "Uppdating " << s << ' ' << e << '\n';
      lazy = lazy ^ z;
      return;
    }
    if (x > m)r -> up(x,y,z);
    else if (y <= m) l->up(x,y,z);
    else {l->up(x,m,z); r->up(m+1,y,z);}
    out = l->value() + r->value();
    for (int i=0;i<33;++i)v[i] = l->v[i] + r->v[i];
  }
  ll value(){ 
    if (lazy == 0)return out;
    if (s == e){
      out = 0;
      for (int i=0;i<33;++i){
        if (lazy & ( 1LL<< i) ) v[i] = 1 - v[i]; 
        out += (1LL << i) * v[i];
      }
      // cout << s << ' ' << e << ' ' << out << '\n';
      lazy = 0;
      return out;
    }
    out = 0;
    r->lazy = r->lazy ^ lazy;
    l->lazy = l->lazy ^ lazy;
    for (int i=0;i<33;++i){
      if(lazy & (1LL << i)) {
        v[i] = (e - s + 1) - v[i];
      }
      out += (1 << i) * v[i];
    }
    // cout << s << ' ' << e << ' ' << out << '\n';
    lazy = 0;
    return out;
  }
} *root;

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  freopen("input.txt","r",stdin);
  cin >> N >> Q;
  for (int i=0;i<N;++i)cin>>A[i];
  root = new node(0,N-1);
  for (int i=0;i<Q;++i){
    cin>>a;
    if (a == 0){
      cin>>b>>c;
      cout << root -> query(b,c) << '\n';
    }
    else {
      cin>>b>>c>>d;
      root -> up(b,c,d);
    }
  }
}
