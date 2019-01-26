#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef pair<ll,pi> pii;
typedef vector<pi> vpi;
typedef double dl;
#define mp make_pair
#define pb push_back
#define f first
#define s second
ll MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
ll INF = 100000000000000000;
#define SZ(x) x.size()
#define ALL(x) x.begin(),x.end()

ll N,K,a,b,off;
vpi V,D;
map<ll,ll>M,M2,tmp;

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin>>N>>K;
  for (int i=0;i<N;++i){
    cin>>a>>b;
    if (b == 0)continue;
    if (a == 0){
      off += b;
      continue;
    }
    V.pb(mp(a,b));
  }
  N = SZ(V);
  ll hp = (N+1)/2;
  // cout<<hp<<'\n';
  M[0] = 0;
  for (int i=0;i<hp;++i){
    for (auto it : M){
      if (it.f + V[i].f > K)continue;
      M2[it.f + V[i].f] = max(M2[it.f + V[i].f], M[it.f] + V[i].s);
    }
    for (auto it : M2){
      M[it.f] = max(M[it.f], it.s);
    }
    M2.clear();
  }
  for (auto i : M){
    D.pb(mp(i.f, i.s));
  }
  M.clear();
  M[0] = 0;
  for (int i=hp;i<N;++i){
    for (auto it : M){
      if (it.f + V[i].f > K)continue;
      M2[it.f + V[i].f] = max(M2[it.f + V[i].f], M[it.f] + V[i].s);
    }
    for (auto it : M2){
      M[it.f] = max(M[it.f], it.s);
    }
    M2.clear();
  }
  // for (auto i : M)cout<<i.f<<' '<<i.s<<'\n';;
  ll stop = SZ(D) - 1;
  ll curind  = 0LL;
  V.clear();
  for (auto i : M){
    V.pb(mp(i.f, i.s));
  }
  reverse(ALL(V));
  ll t = 0, ans = 0;
  for (auto i : V){
    // cout<<i.f<<' '<<i.s<<' ';
    while (curind + 1 <= stop && D[curind + 1].f + i.f <= K){
      ++curind;
      t = max(t, D[curind].s);
    }
    // cout<<curind << ' ' << t << '\n';
    ans = max(ans, t + i.s);
  }
  cout<<ans+off;
}

