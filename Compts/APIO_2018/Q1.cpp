#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MOD 1e9+7
#define lb lower_bound
#define ub upper_bound
#define dst distance
#define INF 1000000000

set<int> S[300100];
int ans[300100];
int N,T,Q,a,b,c,d;
vector<int> L;

struct data{
  int loc, type, time, query;
  data(int a, int b, int c, int d): loc(a), type(b), time(c), query(d) {};
};
vector<data> V;
bool cmp(data a, data b){
  if (a.time == b.time)return a.query < b.query;
  return a.time < b.time;
}

struct fenwick{
  vector<int> fw;
  int N;
  fenwick(int _N){
    N = _N;
  }
  void update(int x,int v){
    for (;x<=N;x += x&(-x))fw[x] += v;
  }
  int sum(int x){
    int res= 0;
    for(;x;x-=(x&(-x)))res += fw[x];
    return res;
  }
};

bool query(int x, data D){
  return 1; 
}

struct node{
  int s,e,m,v;
  vector<int> V;
  fenwick *FW;
  node *l, *r;
  node (int _s, int_e){
    s = _s;e = _e; m = (s+e)/2;
    v = 0;
    if (s != e){
      l = new node(s,m);
      r = new node(m+1, e);
    }
  }
  
  void add(int x, int y){
    V.pb(y);
    if(s==e)return;
    if (x <= m)s->add(x,y);
    else e->add(x,y);
  }

  void up (){
    if(s==e)return;
    sort(V.begin(), V.end());
    unique(V.begin(),V.end());
    s->up();
    e->up();
  }

} * root;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen("input.txt","r",stdin);
  cin >> N >> T >> Q;
  for (int i= 0; i < N; ++i){
    cin >> a >> b >> c >> d;
    V.pb({a,b,c,-1});
    V.pb({a,b,d,1});
    L.pb(b);
  }
  sort(L.begin(), L.end());
  root = new node (0,N);
  for (int i = 0; i < Q; ++i){
    cin >> a >> b;
    V.pb({a,i,b,0});
  }
  sort(V.begin(), V.end(), cmp);
  for (auto it : V){
    if (it.query == 1){
      auto t = S[it.type].lb(it.loc);
      if (t == S[it.type].end()){
        --t;
        root->add(*t, it.type);
        root->add(it.type,it.type);
      }else if (t == S[it.type].begin()){
        root->add(it.loc,*t);
      }else{
        root->add(it.loc,*t); 
        --t;
        root->add(*t,it.loc);
      }
      S[it.type].insert(S[it.loc]);
    }
    else if (it.query == -1){
      auto t = S[it.type].lb(it.loc);
      if (t != S[it.type].begin() && t != S[it.type].end()){
        int l = *(--t);
        ++t;
        ++t;
        int r = *t;
        root->add(l,r);
      }
    }
  }
  for (auto it : V){
    if (it.query == 0){
      int lb = 0;
      int ub = INF;
      while (ub > lb + 1){
        int mid = (ub + lb) / 2;
        if (query(mid))ub = mid;
        else lb = mid;
      }
      if (ub == INF){
        ans[it.type] = -1; 
        continue;
      }
      if (query(lb))ans[it.type] = lb;
      else ans[it.type] = ub;
    }else if (it.query == -1){
      // Add
    }else {
      // Remove
    }
  }
}
