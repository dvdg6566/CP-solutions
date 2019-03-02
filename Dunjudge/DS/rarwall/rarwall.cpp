#include "rarwall.h"
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
ll INF = 1e18;
ll MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (ll)x.size()
#define ALL(x) x.begin(),x.end()

vector<pair<pi,pi> > V;
vi des;
map<ll,ll> M;
ll N;

struct node{
  ll s,e,m,v,lazy;
  node *l, *r;
  node(ll _s, ll _e, ll a, ll b, ll c, node *previous) { // Up refers to the index to update. Sometimes may need to add entry val 
    s = _s; e = _e; m = (s+e)/2; 
    if (a == -1){ // Means that this is the original segment tree
      lazy=0; v=0;
      if (s != e){
        l = new node(s,m,a,b,c,previous);
        r = new node(m+1,e,a,b,c,previous);
      }
      return;
    }
    v = previous->v; lazy = previous->lazy;
    if (s == e){
      lazy += c;
      return;
    }
    if (s == a && e == b){
      lazy += c;
      l = previous->l;
      r = previous->r;
    }
    else if (a > m){
      r = new node(m+1,e,a,b,c,previous->r);
      l = previous -> l;
    }
    else if (b <= m){
      l = new node(s,m,a,b,c,previous->l);
      r = previous -> r;
    }
    else{ 
      l = new node(s,m,a,m,c,previous->l);
      r = new node(m+1,e,m+1,b,c,previous->r);
    }
    v = max(l->value(), r->value());
  }

  ll rmq(ll x, ll y){
    // cout<<x<<' '<<y<<' '<<s<<' '<<e<<' '<<lazy<<' '<<v<<'\n';
    if (s == x && e == y)return value();
    if (x > m)return lazy+r->rmq(x,y);
    if (y<=m)return lazy+l->rmq(x,y);
    return lazy+max(l->rmq(x,m), r->rmq(m+1,y));
  }

  ll value(){
    return v+lazy;
  }

}*A[100100];

void init(int L, int M, int Q) {
  // cout<<"RUN\n";
}

void proposal(int N, int K, int A, int B,int C) {
  V.pb(mp(mp(K,A), mp(B,C)));
  des.pb(A);
  des.pb(A+1);
  // des.pb(A-1);
  des.pb(B);
  des.pb(B+1);
  // des.pb(B-1);
}

long long max_height(int P, int X, int Y) {
    if (SZ(V)){
      des.pb(INF);
      sort(ALL(des));
      des.resize(unique(ALL(des)) - des.begin());
      for (ll i=0;i<SZ(des); ++i){
        M[des[i]] = i+1;
        // cout<<des[i] <<' ' <<M[des[i]]<<'\n';
      }
      for (ll i=0;i<SZ(V);++i){
        V[i].s.f = M[V[i].s.f];
        V[i].f.s = M[V[i].f.s];
      }
      N = SZ(des);
      A[0] = new node(0, N, -1, -1, -1, A[10]);
      // cout<<N<<'n';
      for (ll i=0;i<SZ(V);++i){
        // cerr<<i+1<<' '<<V[i].f.f<<' '<<V[i].f.s<<' '<<V[i].s.f<<' '<<V[i].s.s<<'\n';
        A[i+1] = new node(0, N, V[i].f.s, V[i].s.f, V[i].s.s, A[V[i].f.f]);
        // cout<<"Success\n";
      }
      V.clear();
    }
    X = M[*(--ub(ALL(des), X))];
    Y = M[*(lb(ALL(des), Y))];
    // cout<<"Query " << P << ' ' <<X << ' ' <<Y << '\n';
    return A[P]->rmq(X,Y);
}
