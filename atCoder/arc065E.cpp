#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef pair<ll,ll> pii;
typedef vector<pi> vpi;
typedef set<ll> si;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define f first
#define s second
ll INF = 1e9;
ll MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (ll)x.size()
#define ALL(x) x.begin(),x.end()

vpi V;
ll N,A,B,a,b,R;
vi des;
vector<ll> add[600100], dif[600100];
set<pi> add2[600100], dif2[600100];
ll height[100100];
ll used[100100];

int main(){
  // freopen("in.txt","r",stdin);
  cin >> N >> A >> B;
  for (ll i=0;i<N;++i){
    cin >>a  >> b;
    V.pb(mp(a,b));
  }
  --A;--B;
  R = abs(V[A].f - V[B].f) + abs(V[A].s - V[B].s);
  for (ll i=0;i<N;++i){
    a = V[i].f, b = V[i].s;
    des.pb(a+b);
    des.pb(b-a);
    des.pb(a+b-R);
    des.pb(a+b+R);
    des.pb(b-a+R);
    des.pb(b-a-R);
  }

  sort(ALL(des));
  des.resize(unique(ALL(des)) - des.begin());
  for (ll it=0;it<SZ(V);++it){
    pi i = V[it];
    ll sum = i.f + i.s;
    ll d = i.s - i.f;
    add[lb(ALL(des), sum) - des.begin()].pb(i.f);
    add2[lb(ALL(des), sum) - des.begin()].insert(mp(i.f, it));
    dif[lb(ALL(des), d) - des.begin()].pb(i.f);
    dif2[lb(ALL(des), d) - des.begin()].insert(mp(i.f, it));
  }
  ll ans = 0;

  for (ll i=0;i<SZ(des);++i)sort(ALL(add[i]));
  for (ll i=0;i<SZ(des);++i)sort(ALL(dif[i]));

  queue<ll> q;
  stack<ll> st;
  used[A] = used[B] = 1;
  q.push(A);
  q.push(B);
  while(SZ(q)){
    ll x = q.front();
    // cout<<"Visit " << x << '\n';
    q.pop();
    a = V[x].f;
    b = V[x].s;
    ll t = V[x].f + V[x].s + R;
    ll ind = lb(ALL(des), t) - des.begin();
    for (auto it = add2[ind].lb(mp(a+1,0)); it != add2[ind].ub(mp(a+R, INF)); ++it){
      if (used[it->s])continue;
      used[it->s] = 1;
      st.push(it->s);
    }

    t = a+b-R;
    ind = lb(ALL(des), t) - des.begin();
    for (auto it = add2[ind].lb(mp(a-R, 0)); it != add2[ind].ub(mp(a-1, INF)); ++it){
      if (used[it->s])continue;
      used[it->s] = 1;
      st.push(it->s);
    }

    t = b+R-a;
    ind = lb(ALL(des), t) - des.begin();
    for (auto it = dif2[ind].lb(mp(a-R+1, 0)); it != dif2[ind].ub(mp(a, INF)); ++it){
      if (used[it->s])continue;
      used[it->s] = 1;
      st.push(it->s);
    }

    t = b-a-R;
    ind = lb(ALL(des), t) - des.begin();
    for (auto it = dif2[ind].lb(mp(a, 0)); it != dif2[ind].ub(mp(a+R-1, INF)); ++it){
      if (used[it->s])continue;
      used[it->s] = 1;
      st.push(it->s);
    }

    while(SZ(st)){
      ll x = st.top(); st.pop();
      pi i = V[x];
      ll sum = i.f + i.s;
      ll d = i.s - i.f;
      add2[lb(ALL(des), sum) - des.begin()].erase(mp(i.f, x));
      dif2[lb(ALL(des), d) - des.begin()].erase(mp(i.f, x));
      q.push(x);
    }
  }

  // for (ll i=0;i<N;++i)cout<<used[i]<<' ';
  // cout<<'\n';

  for (ll i=0;i<N;++i){
    if (!used[i])continue;
    ll t = V[i].f + V[i].s + R;
    ll ind = lb(ALL(des), t) - des.begin();
    a = V[i].f;
    b = V[i].s;
    ll rep = ub(ALL(add[ind]), a+R) - lb(ALL(add[ind]), a+1);

    t = a + b- R;
    ind = lb(ALL(des), t) - des.begin();
    rep += ub(ALL(add[ind]), a-1) - lb(ALL(add[ind]), a-R);

    t = b + R - a;
    ind = lb(ALL(des), t) - des.begin();
    rep += ub(ALL(dif[ind]), a) - lb(ALL(dif[ind]), a-R+1);


    t = b - R - a;
    ind = lb(ALL(des), t) - des.begin();
    rep += ub(ALL(dif[ind]), a+R-1) - lb(ALL(dif[ind]), a);

    ans += rep;
  }
  cout<<ans/2;
}
