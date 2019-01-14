#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef double dl;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MOD 1e9+7
#define lb lower_bound
#define ub upper_bound
#define dst distance
#define INF 1000000000

struct node {
  int s, e, m, v;
  node *l, *r;
  node(int _s, int _e) {
    s = _s; e = _e; m = (s+e)/2;
    v = 0;
    if (s!=e) {
      l = new node(s, m);
      r = new node(m+1, e);
    }
  }
  void up(int x, int nv) {
    if (s==e) { v=nv; return; }
    if (x>m) r->up(x, nv);
    if (x<=m) l->up(x, nv);
    v = min(l->v, r->v); //Modify the value of v after updating children
  }
  int rmq(int x, int y) {
    if (s==x && e==y) return v;
    if (x>m) return r->rmq(x, y);
    if (y<=m) return l->rmq(x, y);
    return min(l->rmq(x, m), r->rmq(m+1, y));
  }
}*root;
