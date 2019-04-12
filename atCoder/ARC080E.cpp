#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<int,pi> pii;
typedef vector<pi> vpi;
typedef set<int> si;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define f first
#define s second
int INF = 1e9;
ll MOD = 1e9;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()

int N,a;
int P[200100];
set<int> done;
int A[200100];
int ind[200100];

struct node{
  int s,e,m,v;
  node *l, *r;
  node(int _s, int _e){
    s=_s;e=_e;m=(s+e)/2;
    if (s == e){
      v = A[s];
    }
    else{
      l = new node(s,m);
      r = new node(m+1, e);
      v = min(l->v, r->v);
    }
  }
  void up(int x, int val){
    if (s == e){
      v = val;
      return;
    }
    if (x <= m)l->up(x,val);
    else r->up(x,val);
    v = min(l->v, r->v);
  }
  int query(int a, int b){
    if (a == s && b == e)return v;
    if (b <= m)return l->query(a,b);
    if (a > m)return r->query(a,b);
    return min(l->query(a,m), r->query(m+1, b));
  }
} *odd, *even, *all;

struct newnode{
  int s,e,m,odd, even,lazy;
  newnode *l, *r;

  newnode(int _s, int _e){
    s=_s; e=_e; m=(s+e)/2;
    odd = even = INF; lazy=0;
    if (s == e){
      if (s%2 == 1)odd = A[s];
      else even = A[s];
    }
    else{
      l = new newnode(s, m);
      r = new newnode(m+1, e);
      odd = min(l->odd,r->odd);
      even = min(l->even,r->even);
    }
  }

  void prop(){
    // cout<<"Prop " << s << ' ' << e << '\n';
    if (s == e){
      if (!lazy)return;
      swap(odd, even);
      lazy = 0;
      return;
    }
    if (!lazy)return;
    swap(odd, even);
    r->lazy = 1 - r->lazy;
    l->lazy = 1 - l->lazy;
    lazy = 0;
    return;
  }

  void combine(){
    int le = (m-s+1);
    l->prop(); r->prop();
    odd = even = INF;
    odd = min(l->odd,r->odd);
    even = min(l->even,r->even);
  }

  void erase(int x){
    // if (s == 0 && e == N-1)cout<<"Removing call "<<x<<'\n';
    if (s == e){
      odd = even = INF;
      return;
    }
    prop();
    if (x <= m)l->erase(x);
    else r->erase(x);
    combine();
  }

  void flip(int a, int b){
    // if (s == 0 && e == N-1)cout<<"Starting call " << a<<' '<<b<<'\n';
    if (s == a && b == e){
      lazy = 1-lazy;
      return;
    }
    prop();
    if (a > m)r->flip(a,b);
    else if (b <= m)l->flip (a,b);
    else {
      l->flip(a,m);
      r->flip(m+1,b);
    }
    combine();
  }

  void ask(){
    prop();
  }

}*root;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // freopen("in.txt","r",stdin);
  // freopen("out.txt","w",stdout);
  cin >> N;
  done.insert(N);
  for (int i=0;i<N;++i){
    cin>>P[i];
    ind[P[i]] = i;
    if (i%2==0)A[i] = P[i];
    else A[i] = INF;
  }
  even = new node(0,N-1);
  for (int i=0;i<N;++i){
    if (i%2)A[i] = P[i];
    else A[i] = INF;
  }
  odd = new node(0,N-1);
  int cnt = 1, nxt = INF;
  for (int i=0;i<N;++i)A[i] = P[i];
  root = new newnode(0, N-1);

  for (int i=0;i<N/2;++i){
    // cout<<"Asking\n";
    root->ask();
    // cout<<"Asked\n";
    int curval = root->even;
    int curind = ind[curval];
    // cerr<<curval<<' '<<curind<<'\n';
    if (done.find(curind) != done.end())continue; // Already taken
    int abv = (*done.ub(curind)) - 1;
    int minval;
    if (curind%2==0){
      minval = odd->query(curind, abv);
    }else{
      minval = even->query(curind, abv);
    }
    // cerr<<"Pair " << curval<<' '<<minval<<'\n';
    int mindex = ind[minval];
    if (curind%2==0){
      odd->up(mindex, INF);
      even->up(curind, INF);
    }else{
      even->up(mindex, INF);
      odd ->up(curind,INF);
    }
    cout<<curval<<' '<<minval<<' ';
    done.insert(curind);
    done.insert(mindex);
    root->erase(curind);
    root->erase(mindex);
    root->flip(curind, mindex);
  }
}
