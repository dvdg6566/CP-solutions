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


ll V[100100];

struct node{
  ll s,e,m,v,lazy;
  node *l, *r;
  node(ll _s, ll _e, ll a, ll b, ll c, node *previous) { // Up refers to the index to update. Sometimes may need to add entry val 
    s = _s; e = _e; m = (s+e)/2; lazy=0;
    if (a == -1){ // Means that this is the original segment tree
      if (s == e){
        v = V[s];
        return;
      }
      l = new node(s,m,a,b,c,previous);
      r = new node(m+1,e,a,b,c,previous);
      v = l->v+r->v;
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
      return;
    }
    if (a > m){
      r = new node(m+1,e,a,b,c,previous->r);
      l = previous -> l;
      v = l->value()+r->value();
      return;
    }
    if (b <= m){
      l = new node(s,m,a,b,c,previous->l);
      r = previous -> r;
      v = l->value()+ r->value();
      return;
    }
    l = new node(s,m,a,m,c,previous->l);
    r = new node(m+1,e,m+1,b,c,previous->r);
    v = l->value() + r->value();
  }

  ll rsq(ll x, ll y){
    ll t = (y-x+1);
    if (s == x && e == y)return lazy*t+v;
    if (x > m)return lazy*t+r->rsq(x,y);
    if (y<=m)return lazy*t+l->rsq(x,y);
    return lazy*t+l->rsq(x,m)+r->rsq(m+1,y);
  }

  ll value(){
    return v+lazy*(e-s+1);
  }

}*A[100100];

ll N,Q, T;
char ch;
ll a,b,c;

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin>>N>>Q;
  for (ll i=1;i<=N;++i)cin>>V[i];
  A[0] = new node(1, N, -1, -1, -1, A[100]);
  for (ll i=1;i<=Q;++i){
    cin>>ch;
    if (ch == 'Q'){
      cin >> a >> b;
      cout<<A[T]->rsq(a,b)<<'\n';
    }
    else if (ch == 'C'){
      cin>>a>>b>>c;
      A[T+1] = new node(1, N, a, b, c, A[T]);
      ++T;
    }
    else if (ch == 'H'){
      cin>>a>>b>>c;
      cout<<A[c]->rsq(a,b)<<'\n';
    }
    else if (ch == 'B'){
      cin>>a;
      T = a;
    }
  }
}
