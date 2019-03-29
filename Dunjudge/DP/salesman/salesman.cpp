#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef vector<ll> vi;
typedef vector<pi> vpi;
#define mp make_pair
#define pb push_back
#define SZ(x) (ll)x.size()
#define ALL(x) x.begin(), x.end()
#define f first
#define s second
ll INF = 1e9;

ll N,U,D,S;
vector< pair<ll, pi> > V;
ll a,b,c;
ll ans;

struct node{
  int s,e,m; ll v;
  node *l, *r;
  node(int _s, int _e){
    s =_s;e=_e;
    m = (s+e)/2; v = -INF;
    if (s != e){
      l = new node(s,m);
      r = new node(m+1, e);
    }
  }
  
  void up(ll x, ll val){
    // if (s == 0 && e == 500000)cerr<<"Updating " << x << " to " << val << '\n';
    if (s == e){
      v = max(v, val);
      return;
    }
    if (x <= m)l->up(x,val);
    if (x > m)r->up(x,val);
    v = max(l->v, r->v);
  }

  ll rmq(ll x, ll y){
    if (s == x && y == e)return v;
    if (y <= m)return l->rmq(x,y);
    if (x > m)return r->rmq(x,y);
    return max(l->rmq(x,m), r->rmq(m+1, y));
  }
}*upstream, *downstream;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // freopen("in.txt","r",stdin);
  cin >>N >> U >> D >> S;
  for (ll i=0;i<N;++i){
    cin>>a>>b>>c;
    V.pb(mp(a, mp(b,c)));
  }
  sort(ALL(V));
  // for (auto i : V)cout<<i.f<<' '<<i.s.f<<' '<<i.s.s<<'\n';
  upstream= new node(0, 500001);
  downstream = new node(0, 500001);
  upstream -> up(S, 0 - U * S);
  downstream -> up(S, 0 + D * S);
  vector<pi> cur;
  vector<ll> outs;
  vector<ll> ins;

  for (ll it=0;it<SZ(V);++it) {
    cur.clear();
    outs.clear();
    ins.clear();
    cur.pb(V[it].s);

    while (it < N-1 && V[it+1].f == V[it].f){
      ++it;
      cur.pb(V[it].s);
    }

    sort(ALL(cur));

    for (auto i : cur){
      ll l = i.f;
      ll p = i.s;
      ll u = upstream -> rmq(l, 500001);
      ll d = downstream -> rmq(0, l);
      ll t = max(d - D * l, u + U * l) + p;
      ins.pb(t);
      outs.pb(t);
    }
    
    ll val = ins[0];
    ll curloc = cur[0].f;
    for (ll i=1;i<SZ(cur);++i){
      ll l = cur[i].f;
      ll p = cur[i].s;
      val = max(val + p - D * (l- curloc), ins[i]);
      curloc = l;
      // cout<<l<<' '<<p<<' '<<val<<'\n';
      outs[i] = max(outs[i], val);
    }

    val = ins.back();
    curloc = cur.back().f;
    for (int i = SZ(cur) - 2; i >= 0; --i){
      ll l = cur[i].f;
      ll p = cur[i].s;
      val = max(val + p - U * (curloc - l), ins[i]);
      curloc = l;
      outs[i] = max(outs[i], val);
    }

    for (ll i=0;i<SZ(cur);++i){
      ll l = cur[i].f;
      ll p = cur[i].s;
      ll t = outs[i];
      upstream -> up(l, t - U * l);
      downstream -> up (l, t + D * l);
      if (l > S){
        ans = max(ans, U * (S - l) + t);
      }
      else{
        ans = max(ans, D * (l - S) + t);
      }
    }
  }
  cout<<ans;
}
