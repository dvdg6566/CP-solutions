#include "majority.h"
#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
int MOD = 1e9+7;
int INF = 1e9;
int shift = 2000000;

vi V[2001000];
int M, ans;
stack<int> st;

struct node{
  int s,e,m,v,lp,rp;
  node *l, *r;
  node(int _s, int _e){
    s=_s;e=_e;m=(s+e)/2;v = INF;
    lp = 0;rp= 0;
  }

  void up(int x, int val){
    // cout<<s<<' '<<x<<' '<<e<<'\n';
    if (s == e){
      if (val != INF)v = min(v, val);
      else v = INF;
      return;
    }
    if (x <= m){
      if (!lp){
        l = new node(s,m);
        lp = 1;
      }
      l->up(x,val);
    }
    else {
      if (!rp){
        r = new node(m+1, e);
        rp = 1;
      }
      r->up(x, val);
    }
    v = INF;
    if (lp)v = min(v,l->v);
    if (rp)v = min(v, r->v);
  }

  int query(int x, int y){
    // cout<<x<<' '<<y<<'\n';
    // if (s == 0 && e == 4001000)cout<<y<<' ';
    if (s == x && y == e)return v;
    if (x > m){
      if (!rp)return INF;
      return r->query(x,y);
    }
    if (y <= m){
      if (!lp)return INF;
      return l->query(x,y);
    }
    int ans = INF;
    if (lp)ans = min(l->query(x,m), ans);
    if (rp)ans = min(r->query(m+1,y), ans);
    // cout<<x<<' '<<y<<' '<<ans<<'\n';
    return ans;
  }

}*root;

vi use;

bool cmp(int a, int b){
    return SZ(V[a]) > SZ(V[b]);
}
int majority(int N, int A[]) {
  for (int i=1;i<=N;++i){
    if (!SZ(V[A[i-1]])) use.pb(A[i-1]);
    V[A[i-1]].pb(i); 
  }
  sort(ALL(use), cmp);
  root = new node(0, 4001000);
  for (auto i : use){
    if (SZ(V[i]) == 0)continue;
    if (SZ(V[i]) > (N+1)/2){
        return N;
    }
    if (SZ(V[i]) * 2 -1 < ans)return ans;
    // cout<<root->v<<'\n';
    while(SZ(st)){root ->up(st.top(), INF);st.pop();}
    int cnt = 0;
    for (auto it : V[i]){
      int t = it - 1;
      int w = 2 * cnt;
      root -> up(w - t + shift, w);
      // cout<<"Up " << w-t+shift<<' '<<w<<'\n';
      // cerr<<"done\n";
      st.push(w-t+shift);
      ++cnt;
      w = 2*cnt - 1;
      // cerr<<"Run\n";
      t = root->query(0, shift + w - it);
      // cout<<t<<'\n';
      ans = max(min(w - t, it), ans);
    }
    int w = 2 * cnt-1;
    ans = max(min(w - root->query(0, shift + w - N), N), ans);
  }
  return ans;
}
