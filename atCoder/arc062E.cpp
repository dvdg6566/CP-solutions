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
ll INF = 1e9;
ll MOD = 1e9;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (ll)x.size()
#define ALL(x) x.begin(),x.end()
#define count(V,x) ub(ALL(V),x,cmp) - lb(ALL(V),x,cmp)

struct cube{
  ll a, b, c, d, orien;
  cube(ll _a, ll _b, ll _c, ll _d): a(_a), b(_b), c(_c), d(_d), orien(1){
    ll m = min({a,b,c,d});
    if (a == b && a == c && a == d)orien = 4;
    else if (a == c && b == d)orien = 2;
  }

  bool fit(cube cmp){
    return a == cmp.a && b == cmp.b && c == cmp.c && d == cmp.d;
  }

  cube rotate(){
    return cube({b,c,d,a});
  }

  void pp(){
    cout<<a<<' '<<b<<' '<<c<<' '<<d<<'\n';
  }
};

bool cmp(cube a, cube b){
  if (a.a != b.a)return a.a < b.a;
  if (a.b != b.b)return a.b < b.b;
  if (a.c != b.c)return a.c < b.c;
  return a.d < b.d;
}

bool biggay = 0;

cube bal(cube t){
  cube q = t.rotate();
  cube r = q.rotate();
  cube u = r.rotate();
  if (cmp(q, t))t = q;
  if (cmp(r, t))t = r;
  if (cmp(u, t))t = u;
  return t;
}

ll N;
ll a,b,c,d;
vector<cube> V,faces,comp;
vi rep;

int main(){
  // freopen("in.txt","r",stdin);
  cin >> N;
  for (int i=0;i<N;++i){
    cin >>a >> b >> c >> d;
    V.pb({a,b,c,d});
    V[i] = bal(V[i]);
  }
  sort(ALL(V), cmp);

  ll ans=0;
  for (int i=0;i<N-1;++i){
    // Base
    // if (i != 0)continue;
    for (int j=i+1;j<N;++j){
      // if (j != 5)continue;
      cube top = V[i];
      cube btm = V[j];
      for (int k=0;k<4;++k){
        ll r = 1;

        faces.pb(bal(cube(top.d,top.c,btm.c,btm.b)));
        faces.pb(bal(cube(top.c,top.b,btm.d,btm.c)));
        faces.pb(bal(cube(top.b,top.a,btm.a,btm.d)));
        faces.pb(bal(cube(top.a,top.d,btm.b,btm.a)));

        sort(ALL(faces), cmp);

        r *= faces[0].orien;
        r *= faces[1].orien;
        r *= faces[2].orien;
        r *= faces[3].orien;
        
        comp.pb(faces[0]);
        rep.pb(1);

        if (comp.back().fit(faces[1])){
          ++rep.back();
        }else{
          comp.pb(faces[1]);
          rep.pb(1);
        }
        if (comp.back().fit(faces[2])){
          ++rep.back();
        }else{
          comp.pb(faces[2]);
          rep.pb(1);
        }
        if (comp.back().fit(faces[3])){
          ++rep.back();
        }else{
          comp.pb(faces[3]);
          rep.pb(1);
        }

        for (int k=0;k<SZ(comp); ++k){
          cube it = comp[k];
          int cnt = count(V, it);
          if (V[i].fit(it))--cnt;
          if (V[j].fit(it))--cnt;
          while(rep[k]){
            --rep[k];
            r *= cnt;
            cnt--;
          }
        }
        ans += r;
        top = top.rotate();
        rep.clear();
        faces.clear();
        comp.clear();
      }
    }
  }
  cout<<ans/3;
}
