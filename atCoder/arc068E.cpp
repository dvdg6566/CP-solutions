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

vpi V[100100];
int N,M,a,b,offset;
int fw[200100];

void up(int x, int v){
  for (;x<=M*2;x += x&(-x))fw[x] += v;
}

int sum(int x){
  int res = 0;
  for (;x;x-=x&(-x))res += fw[x];
  return res;
}

int main(){
  // freopen("in.txt","r",stdin);
  cin >> N >> M;
  for (int i=0;i<N;++i){
    cin >> a >> b;
    V[b-a+1].pb(mp(a,b));
  }
  offset = N;
  for (int k=1;k<=M;++k){
    // cout<<"add stuff distance " << k-1<<'\n';
    for (auto v : V[k-1]){
      up(v.f, 1);
      up(v.s+1, -1);
      --offset;
    }
    vector<int> v;
    v.clear();
    for (int i=0;i<M;i = i+k){
      v.pb(sum(i+k) - sum(i));
    }
    // for (auto i : v)cout<<i<<' ';cout<<'\n';
    int ans = 0, cur = 0;
    for (auto i : v){
      cur += i;
      ans += cur;
      assert(cur >= 0);
    }
    cout<<offset+ans<<'\n';
  }
}
