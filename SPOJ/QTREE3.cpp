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

vi aList[100100];
int cur;
int N,Q,a,b;
ll fw[100100];

void update(ll x, ll v) {
    for (; x<=N; x+=x&(-x)) fw[x] += v; 
}

ll sum(ll x) {
    ll res = 0;
    for(; x; x-=x&(-x)) res += fw[x];
    return res;
}

ll query(ll a, ll b){
  if (a > b)swap(a,b);
  return sum(b) - sum(a-1);
}

int p[100100], depth[100100], heavy[100100], head[100100], pos[100100], rev[100100];
int dfs(int x){
  int size = 1;
  int mchild = 0;
  for (auto i : aList[x]){
    if (i == p[x])continue;
    p[i] = x;
    depth[i] = depth[x] + 1;
    int cs = dfs(i);
    size += cs;
    if (cs > mchild){
      mchild = cs;
      heavy[x] = i;
    }
  }
  return size;
}

void decompose(int x, int h){
  head[x] = h; pos[x] = cur++;
  rev[pos[x]] = x;
  if (heavy[x] != -1)decompose(heavy[x], h);
  for (auto i : aList[x]){
    if (i == p[x])continue;
    if (i == heavy[x])continue;
    decompose(i,i);
  }
}

ll ask(ll x){
  vpi V;
  V.clear();
  while (x > 1){
    V.pb(mp(pos[head[x]], pos[x]));
    x = p[head[x]];
  }
  reverse(ALL(V));
  for (auto i : V){
    int cur = query(i.f,i.s);
    if (cur){
      int lower = i.f;
      int upper = i.s;
      // cout<<"Binsch " <<lower<<' '<<upper<<'\n';
      while (lower + 1 < upper){
        int m = (lower+upper)/2;
        int x = query(i.f, m);
        // cout<<"Query " << i.f<<' '<<m<<' '<<x<<'\n';
        if (query(i.f, m))upper = m;
        else lower = m;
      }
      if (query(i.f, lower))return rev[lower];
      return rev[upper];
    }
  }
  return -1;
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin>>N>>Q;
  for (int i=1;i<N;++i){
    cin>>a>>b;
    aList[a].pb(b);
    aList[b].pb(a);
  }
  memset(heavy,-1,sizeof(heavy));
  cur = 1;
  dfs(1);
  decompose(1,1);
  // for (int i=1;i<=N;++i)cout<<i<<' '<<p[i]<<' '<<head[i]<<' '<<pos[i]<<'\n';
  for (int i=0;i<Q;++i){
    cin>>a>>b;
    if (a == 0){
      b = pos[b];
      if (query(b,b)){
        update(b, -1);
        // cout<<"Change to 0 " << b << '\n';
      }
      else{
        update(b, 1 );
        // cout<<"Change to 1 "<<b<<'\n';
      }
    }
    else{
      cout<<ask(b)<<'\n';
    } 
  }
}
