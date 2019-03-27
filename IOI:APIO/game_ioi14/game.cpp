#include "game.h"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<int, pi> pii;
typedef set<int> si;
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
#define ALL(x) x.begin(),x.end()

int con[1510][1510];
int p[1510];
int par(int x) { return (x==p[x])?x:p[x]=par(p[x]);}
void merge(int a, int b) {p[par(a)] = par(b);}
int N;

void initialize(int n) {
  N = n;
  for (int i=0;i<N;++i)p[i] = i;
  for (int i=0;i<N;++i){
    for (int j=0;j<N;++j){
      con[i][j] = 1;
    }
  }
}

int hasEdge(int u, int v) {
  u = par(u);
  v = par(v);
  if (u==v)return 0;
  if (con[u][v] == 1){
    // Merge u and v
    merge(u,v);
    // cout<<u<<' '<<v<<'\n';
    for (int i=0;i<N;++i){
      if (i==u||i==v)continue;
      con[v][i] = con[i][v] = con[v][i] + con[u][i];
    }
    return 1;
  } else{
    con[u][v]--;
    con[v][u]--;
    return 0;
  }
}
