#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<int,int> pi;
typedef pair<int,pi> pii;
typedef vector<pi> vpi;
typedef set<int> si;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define f first
#define s second
ll INF = 1e15;
ll MOD = 1e9;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()

int vals[100100];

struct node{
  int s,e,m,v;
  node *l, *r;
  node(int _s, int _e, int up, node *previous) { // Up refers to the index to update. Sometimes may need to add entry val 
    s = _s; e = _e; m = (s+e)/2;
    if (up == -2){ // Means that this is the original segment tree
      if (s == e){
        // cout<<s<<' '<<vals[s]<<'\n';
        v = vals[s];
        return;
      }
      l = new node(s,m,up,previous);
      r =new node(m+1, e, up, previous);
      v = l->v + r->v;
      return;
    }
    if (up == -1){
      l = previous->l;
      r = previous->r;
      v = previous->v;
      return;
    }
    if (s == e){
      v = 1;
      return;
    }
    if (up <= m){
      l = new node(s, m, up, previous->l);
      r = previous->r;
      v = l->v + r->v;
    }else{
      l = previous->l;
      r = new node(m+1,e, up, previous->r);
      v = l->v + r->v;
    }
 }
  int rsq(int x, int y){
    if (x == s && y == e)return v;
    if (y <= m)return l->rsq(x,y);
    if (x > m)return r->rsq(x,y);
    return l->rsq(x,m) + r->rsq(m+1,y);
  }

}*A[100100];

int p[1001000], V[100100],N, nxt[100100],Q,a,b;

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin>>N;
  for (int i=1;i<=N;++i)cin>>V[i];
  memset(p,-1,sizeof(p));
  memset(nxt,-1,sizeof(nxt));
  for (int i=1;i<=N;++i){
     if (p[V[i]] != -1){
        nxt[p[V[i]] ] = i;
     }else  ++vals[i]; 
     p[V[i]] = i;
  }
  A[0] = new node (1, N, -2, A[10]);
  for (int i=1;i<=N;++i){
    A[i] = new node(1, N, nxt[i-1], A[i-1]);
    // cout<<i<<' '<<nxt[i-1]<<'\n';
  }
  cin>>Q;
  for (int i=0;i<Q;++i){
    cin>>a>>b;
    cout<<A[a]->rsq(a,b)<<'\n';
  }
}
