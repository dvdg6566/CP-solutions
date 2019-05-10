#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef pair<ll,ll> pii;
typedef vector<pi> vpi;
typedef set<ll> si;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define f first
#define s second
ll INF = 1e9;
ll MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (ll)x.size()
#define ALL(x) x.begin(),x.end()

vpi V;
int N,a,b;
vi des;
vi add[400100];
int d[400100][20];
multiset<int> slide;
set<pi> windows;

int find_match(int a, int b){
  int ans = 0;
  for (int i=19;i>=0;--i){
    if (d[a][i] != -1 && d[a][i] <= b){
      a = d[a][i];
      ans += (1<<i);
    }
    if(a==b)return ans;
  }
  return ans;
}

int main(){
  freopen("in.txt","r",stdin);
  cin >> N;
  for (int i=0;i<N;++i){
    cin>>a>>b;
    V.pb(mp(a,b));
    des.pb(a);
    des.pb(b);
  }
  sort(ALL(des));
  des.resize(unique(ALL(des)) - des.begin());

  for (int i=0;i<N;++i){
    V[i].f = lb(ALL(des),V[i].f) - des.begin();
    V[i].s = lb(ALL(des), V[i].s) - des.begin();
  }

  for (auto i : V){
    add[i.f].pb(i.s);
  }
  int D = SZ(des);
  int end = -1;
  memset(d, -1,sizeof(d));

  // for (auto i : des)cout<<i<<' ';cout<<'\n';
  for (int i=0;i<D;++i){
    if (i) for (auto x : add[i-1]){
      // cout<<"Erase " << x << '\n';
      slide.erase(slide.find(x));
    }
    while(!SZ(slide) || end < *slide.begin()){
      ++end;
      if (end >= D)break;
      for (auto x : add[end]){
        slide.insert(x);
        // cout<<"Insert " << x << '\n';
      }
    }
    if (SZ(slide) == 0)d[i][0] = -1;
    else d[i][0] = *slide.begin();
  }

  // for (int i=0;i<D;++i)cout<<d[i][0]<<' ';
  for (int j=1;j<20;++j){
    for (int i=0;i<D;++i){
      int x = d[i][j-1] + 1;
      if (x != 0)d[i][j] = d[x][j-1];
    }
  }
  windows.insert(mp(0, D));
  vi res;
  for (int i=0;i<N;++i){
    // cerr<<"I AM "<<V[i].f<<' '<<V[i].s<<'\n';
    pi x = *(--windows.ub(mp(V[i].f,INF)));
    // cout<<x.f<<' '<<x.s<<'\n';
    if (x.s < V[i].s)continue;
    int p = find_match(x.f, x.s);
    int t = find_match(x.f, V[i].f-1) + find_match(V[i].s+1, x.s) + 1;
    // cout<<"Entire window is "<<x.f<<' '<<x.s<<'\n';
    if (t < p)continue;
    res.pb(i+1);
    windows.erase(x);
    // cout<<"Insert " << x.f<<' '<<V[i].f-1<<'\n';
    // cout<<"Insert " << V[i].s+1<<' '<<x.s<<'\n';
    windows.insert(mp(x.f,V[i].f-1));
    windows.insert(mp(V[i].s+1, x.s));
  }
  cout<<SZ(res)<<'\n';
  for (auto i : res)cout<<i<<' ';


  // cout<<find_match(0,D);
  // for (int j=0;j<3;++j){
  //   for (int i=0;i<D;++i)cout<<d[i][j]<<' ';
  //   cout<<'\n';
  // }
}

