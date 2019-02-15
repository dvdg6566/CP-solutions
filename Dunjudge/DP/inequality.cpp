#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef pair<ll,pi> pii;
typedef vector<pi> vpi;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MOD 1e9+7
ll INF = 1e15;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (ll)x.size()
#define ALL(x) x.begin(),x.end()

typedef pair<pi,pi> pp;

pp fw[10100];
ll MAXL = 10050;
vpi V;
ll N,a,b;

void update(ll x, ll xc, ll yc, ll v){
  for (;x<=MAXL; x += x&(-x)){
    // cout<<"Update " << x << '\n';
    fw[x].f.f += v;
    fw[x].f.s += xc;
    fw[x].s.f += yc;
    fw[x].s.s++;
  }
}

pp sum(ll x){
  pp res;
  for (;x;x -= (x&(-x))){
    res.f.f += fw[x].f.f;
    res.f.s += fw[x].f.s;
    res.s.f += fw[x].s.f;
    res.s.s += fw[x].s.s;
  }
  return res;
}

ll res,ans;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin>>N;
  for (int i=0;i<N;++i){
    cin>>a>>b;
    V.pb(mp(a,b));
  }
  sort(ALL(V));
  for (auto it : V){
    // cout<< "Query " << it.f<<' '<<it.s<<'\n';
    pp cur = sum(it.s);
    // cout<<cur.f.f<<' '<<cur.f.s<<' '<<cur.s.f<<' '<<cur.s.s<<'\n';
    pp big = sum(MAXL);
    pp oth = mp(mp(big.f.f-cur.f.f, big.f.s - cur.f.s), mp(big.s.f - cur.s.f, big.s.s - cur.s.s));
    ll shaded = it.f * cur.s.f - cur.f.f;
    res = (it.f * cur.s.s - cur.f.s)*it.s - shaded;
    // cout<<shaded << ' ' << res << '\n';
    ans += res;


    shaded = oth.f.f - it.s * oth.f.s;
    res = it.f * (oth.s.f - oth.s.s * it.s)  - shaded;
    ans += res;
    // cout<<shaded << ' ' << res<<'\n';
    // cout<<oth.f.f<<' '<<oth.f.s<<' '<<oth.s.f<<' '<<oth.s.s<<'\n';
    update(it.s, it.f, it.s, it.s*it.f);
    // cout<<ans<<'\n';
  }
  cout<<ans<<'\n';
  return 0;
  // TC checker
  ans = 0;
  for (int i=0;i<N;++i){
    for (int j=0;j<i;++j){
      ans += abs(V[i].f - V[j].f) * abs(V[i].s - V[j].s);
    }
  }
    cout<<ans<<'\n';
}
