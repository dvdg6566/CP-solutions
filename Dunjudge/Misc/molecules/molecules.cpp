#include "molecules.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
#define mp make_pair
#define pb push_back
#define SZ(x) (int)x.size();
#define ALL(x) x.begin(), x.end()
#define f first
#define s second

int N,C;
vpi V;
bool A[200100];
vi res;
int L,U;
ll t;
int B[200100];

void answer(){
  for (int i=0;i<N;++i)if (A[i]) res.pb(i);
  ll T = 0;
  for (int i=0;i<N;++i) if (A[i]) T += B[i];
  if (t==T)res.clear();
}

vector<int> find_subset(int l, int u, vector<int> w) {
  N = SZ(w);
  for (int i=0;i<N;++i)B[i] = w[i];
  L = l; U = u;
  for (int i=0;i<N;++i){
    V.pb(mp(w[i], i));
  }
  sort(ALL(V));
  // for (auto i : V)cout<<i.f<<' ';cout<<'\n';
  for (auto i : V){
    if (t + i.f > u)break;
    t += i.f;
    A[i.s] = 1;
    ++C;
  }
  if (t >= l){
    answer();
    return res;
  }
  // for (int i=0;i<N;++i)cout<<A[i]<<' ';cout<<'\n';
  for (int it = 0; it < C; ++it){
    t -= V[it].f;
    A[V[it].s] = 0;
    int x = N - 1 - it;
    t += V[x].f;
    A[V[x].s] = 1;
    if (t >= l){
      assert(t <= u);
      answer();
      return res;
    }
  }
  return res;
}
