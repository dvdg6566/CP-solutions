#include "garden.h"
#include "gardenlib.h"
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

int alist[300100];
int best[300100], nxt[300100];
vi adjList[300100];
int cyc=INF;
int dst[300100];
int res[300100];
vi opt[300100];

void dfs(int x, int src){
  // cout<<x<<' '<<src<<'\n';
  for (auto i : adjList[x]){
    if (i == src){
      cyc = dst[x]+1;
      continue; 
    }
    if (dst[i] != -1)continue;
    dst[i] = dst[x] + 1;
    dfs(i, src);
  }
}

void count_routes(int N, int M, int P, int R[][2], int Q, int G[])
{
  memset(best,-1,sizeof(best));
  memset(nxt, -1, sizeof(nxt));
  
  for (int i=0;i<M;++i){
    int a = R[i][0], b = R[i][1];
    if (best[a] == -1)best[a] = b;
    else if (nxt[a] == -1)nxt[a] = b;
    if (best[b] == -1)best[b] = a;
    else if (nxt[b] == -1)nxt[b] = a;
  }
  memset(alist,-1,sizeof(alist));
  
  for (int i=0;i<N;++i){
    if (best[best[i]] == i && nxt[best[i]] != -1){
      alist[i] = best[i] + N;
    }else alist[i] = best[i];
    if (nxt[i] != -1){
      if (best[nxt[i]] == i && nxt[nxt[i]] != -1){
        alist[i+N] = nxt[i] + N;
      }else alist[i+N] = nxt[i];
    }
    // cout << "Edge from " << i << " to " << alist[i]<<'\n';;
    // cout << "Edge from " << i+N << " to " << alist[i+N]<< '\n';
    if (alist[i+N] != -1)adjList[alist[i+N]].pb(i+N);
    if (alist[i] != -1)adjList[alist[i]].pb(i);
  }
  memset(dst,-1,sizeof(dst));
  dst[P] = 0;
  dfs(P,P);
  if (cyc == INF){
    for (int i=0;i<N;++i){
      if (dst[i] == -1)continue;
      opt[0].pb(dst[i]);
    } 
    sort(ALL(opt[0]));
    for (int i=0;i<Q;++i){
      res[i] += ub ( ALL(opt[0]), G[i]) - lb( ALL(opt[0]), G[i]);
    }
  }else{
    for (int i=0;i<N;++i){
      if (dst[i] == -1)continue;
      opt[ dst[i] % cyc ].pb(dst[i]);
    } 
    for (int i=0;i<cyc;++i)sort(ALL(opt[i]));
    for (int i=0;i<Q;++i){
      // res[i] += opt[G[i] % cyc].size();
      res[i] += ub(ALL(opt[G[i] % cyc]), G[i]) - opt[G[i] % cyc].begin();
    }
  } 
  if(cyc != INF)for (int i =0;i<cyc;++i)opt[i].clear();
  else opt[0].clear();
  memset(dst,-1,sizeof(dst));
  dst[P+N] = 0;
  cyc = INF;
  dfs(P+N,P+N);
  if (cyc == INF){
    for (int i=0;i<N;++i){
      if (dst[i] == -1)continue;
      opt[0].pb(dst[i]);
    } 
    sort(ALL(opt[0]));
    for (int i=0;i<Q;++i){
      res[i] += ub ( ALL(opt[0]), G[i]) - lb( ALL(opt[0]), G[i]);
    }
  }else{
    for (int i=0;i<N;++i){
      if (dst[i] == -1)continue;
      opt[ dst[i] % cyc ].pb(dst[i]);
    } 
    for (int i=0;i<cyc;++i)sort(ALL(opt[i]));
    for (int i=0;i<Q;++i){
      res[i] += ub(ALL(opt[G[i] % cyc]), G[i]) - opt[G[i] % cyc].begin();
      // res[i] += opt[G[i] % cyc].size();
    }
  }
  // for (int i=0;i<2*N;++i)cout<<i<<' '<<dst[i]<<'\n';
  // cout << "Cycle " << cyc << '\n';
  for (int i=0;i<Q;++i)answer(res[i]);
}
