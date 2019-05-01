#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f first
#define s second

typedef long long ll;
vector<pair<ll, pair<ll,ll> > > V;
typedef long double ld;
typedef pair<ld, ll> pi;

priority_queue<pi, vector<pi>, greater<pi> >pq;

ld dst[1010];

ld find_d(ll a, ll b){
  ll w = V[a].s.f;
  ll x = V[b].s.f;
  ll y = V[a].s.s;
  ll z = V[b].s.s;

  return max((ld)0, sqrt( (ld) ((w-x) * (w-x) + (y-z)*(y-z))) -V[a].f - V[b].f);
}

ll N,a,b,c,d,e,f;
int main(){
  // freopen("in.txt","r",stdin);
  cin >> a >> b >> c >> d;
  V.pb(mp(0, mp(a,b)));
  cin >> N;
  for (ll i=0;i<N;++i){
    cin >> a >> b >> e;
    V.pb(mp(e,mp(a,b)));
  }
  V.pb(mp(0,mp(c,d)));

  memset(dst, -1,sizeof(dst));
  dst[0] = 0;
  pq.push(mp(0,0));
  while(pq.size()){
    pi c = pq.top();
    pq.pop();
    ll x = c.s;
    ld d = c.f;
    if (dst[x] < d)continue;
    for (ll i=1;i<=N+1;++i){
      ld t = d + find_d(x,i);
      if (dst[i] != -1 && dst[i] <= t)continue;
      dst[i] = t;
      pq.push(mp(t, i));
    }
  }
  printf("%.11Lf",dst[N+1]);
}
