#include "factories.h"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<int,pi> pii;
typedef vector<pi> vpi;
typedef double dl;
#define mp make_pair
#define pb push_back
#define f first
#define s second
int MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
ll INF = 100000000000000000;
#define SZ(x) x.size()
#define Aint(x) x.begin(),x.end()

int N;

struct CentDecomp{
  vector<vpi> V;
  vi par;
  vi sub;
  vi ban;
  ll dst[500100][19];
  int N,c;

  CentDecomp(int _N){
    N = _N;
    sub.resize(N+1,0);
    par.resize(N+1,0);
    ban.resize(N+1,-1);
    V.resize(N+1);
  }

  void build(int u, int p, int l){
    // cerr<<"BUILD " << u << '\n';
    int n = dfs1(u,p,l); //Find the size of each subtree
    int cent = dfs2(u, p, n); // Find the Centroid
    if (p == -1)p = cent; // Parent of root is urself
    par[cent] = p;
    ban[cent] = l;
    for (auto v : V[cent]){
      if (ban[v.f]!=-1)continue; 
      dst[v.f][l] = v.s;
      build(v.f, cent,l+1);
    }
  }
  
  int dfs1(int u, int p, int l){
    sub[u] = 1;
    for (auto v : V[u]){
      if (ban[v.f]!=-1)continue;
      if (v.f == p)continue;
      if (l)dst[v.f][l-1] = dst[u][l-1] + v.s;
      sub[u] += dfs1(v.f,u,l);
    }
    return sub[u];
  }

  int dfs2(int u, int p, int n){
    for (auto v : V[u]){
      if (ban[v.f]!=-1)continue;
      if (v.f != p && sub[v.f] > n/2){
        ++c;
        return dfs2(v.f,u,n);
      }
    }
    return u;
  }
}*G;

ll ans[500100];
stack<int> st;

void update(int x){
  // cout<<"Update " << x << '\n';
  int lvl = G->ban[x];
  int y = x;
  while(lvl!=-1){
    ans[y] = min(ans[y], G->dst[x][lvl]);
    // cout<<y<<' '<<ans[y]<<'\n';
    st.push(y);
    y = G->par[y];
    --lvl;
  }
}

ll query(int x){
  ll res = INF;
  int lvl = G->ban[x];
  int y = x;
  while(lvl!=-1){
    // cout<<"C "<<y<<'\n';
    res = min(res, ans[y] + G->dst[x][lvl]);
    y = G->par[y];
    --lvl;
  }
  return res;
}

void Init(int _N, int A[], int B[], int D[]) {
  N = _N;
  G = new CentDecomp(N);
  for (int i=0;i<N-1;++i){
    G->V[A[i]].pb(mp(B[i],D[i]));
    G->V[B[i]].pb(mp(A[i],D[i]));
  }
  G->build(0,-1,0);
  for (int i=0;i<N;++i)ans[i] = INF;
  // for (int i=0;i<N;++i)cout<<G->par[i]<<' '<<G->ban[i]<<' '<<G->dst[i][0]<<'\n';cout<<'\n';
}

long long Query(int S, int X[], int T, int Y[]) {
  for (int i=0;i<S;++i)update(X[i]);
  ll res = INF;
  for (int i=0;i<T;++i)res = min(res, query(Y[i]));
  while(st.size()){
    ans[st.top()] = INF;
    st.pop();
  }
  return res;
}
