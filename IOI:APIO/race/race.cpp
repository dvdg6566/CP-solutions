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
#include "race.h"

vpi adjList[200100];
map<ll,ll> M[200100];
ll p[200100];
ll D[200100], dst[200100];
ll ans=INF,N,K;

void dfs(int x){
    for (auto i : adjList[x]){
      if (p[i.f] != -1)continue;
      p[i.f] = x;
      dst[i.f] = dst[x] + 1;
      dfs(i.f);
    }
}

void dfs2(int x){
  ll m=0, a = -1, b = -1;
  if (adjList[x].size() == 1 && x != 0){
    D[x] = 0;
    M[x][0] = dst[x];
    return;
  }
  for (auto i : adjList[x]){
    if (p[i.f] != x)continue;
    dfs2(i.f);
    if (M[i.f].size() > m){
      m = M[i.f].size();
      a = i.f;
      b = i.s;
    }
  }
  swap(M[x], M[a]);
  D[x] = D[a] + b;
  // cout<<"Visiting " << x << '\n';
  // cout << "Copy map from " << a << '\n';
  // for (auto i : M[x])cout<<i.f<<' '<<i.s<<'\n';
  // cout << "Displacement of " << D[x] << '\n';
  if (M[x][-D[x]] == 0 || M[x][-D[x]] > dst[x])M[x][-D[x]] = dst[x];
  // cout << "Querying " << 0 << ' ' << dst[x] << '\n';
  ll req = K - D[x];
  if (M[x][req] != 0){
    ans = min(ans, M[x][req]-dst[x]);
  }else M[x].erase(req);
  for (auto i : adjList[x]){
    if (p[i.f] != x)continue;
    if (i.f == a)continue; 
    ll dif = i.s + D[i.f];
    for (auto j : M[i.f]){
      ll q = j.f + D[i.f] + i.s;
      ll req = K - D[x] - q; 
      // cout<<"Querying " << q<<' '<<j.s - dst[x]<<'\n';
      if (M[x][req] == 0){
        M[x].erase(req);
        continue;
      }
      // cout<< "Answer " << M[x][req]-dst[x] << ' ' <<  M[x][req] + j.s - 2*dst[x] << '\n';
      ans = min(ans, M[x][req] + j.s - 2*dst[x]);
    }
    for (auto j : M[i.f]){
      ll nd = j.f + D[i.f] + i.s - D[x];
      if (M[x][nd] != 0 && M[x][nd] <= j.s)continue;
      M[x][nd] = j.s;
      // cout<<"Add " << nd << ' ' << j.s << '\n';
    }
  }
  // for (auto i : M[x])cout<<i.f<<' '<<i.s<<'\n';
}

int best_path(int _N, int _K, int H[][2], int L[])
{
  N = _N; K = _K;
  for (int i=0;i<N-1;++i){
    adjList[H[i][0]].pb(mp(H[i][1], L[i]));
    adjList[H[i][1]].pb(mp(H[i][0],L[i]));
  } 
  memset(p,-1,sizeof(p));
  p[0] = 0;
  dst[0] = 1;
  dfs(0);
  // for (int i=0;i<N;++i)cout<<i<<' '<<dst[i]<<'\n';
  dfs2(0);
  // cout<<ans<<'\n';
  if (ans == INF)ans= -1;
  return ans;
}


