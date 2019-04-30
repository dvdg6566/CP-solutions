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
ll INF = 1e9;
ll MOD = 1e9;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (ll)x.size()
#define ALL(x) x.begin(),x.end()

int N,a,L,b,Q;
vi V;
int dst[100100][18];

int query(int x, int y){
  int ans = 0;
  for (int i=17;i>=0;--i){
    if (dst[x][i] == -1 || dst[x][i] > y)continue;
    x = dst[x][i];
    ans += (1<<i);
    if (x == y)return ans;
  } 
  return ans + 1;
}

int main(){
  // freopen("in.txt","r",stdin);
  cin >> N;
  for (int i=0;i<N;++i){
    cin >>a ;
    V.pb(a);
  }
  V.pb(INF);
  cin >> L;
  memset(dst, -1, sizeof(dst));
  for (int i=0;i<N;++i){
    int t = V[i]+L;
    int x = ub(ALL(V), t)  - V.begin() - 1;
    if (i != x)dst[i][0] = x;
  }
  // for (int i=0;i<N;++i)cout<<dst[i][0]<<' ';cout<<'\n';
  for (int i=1;i<18;++i){
    for (int j=0;j<N;++j){
      if (dst[j][i-1] != -1)dst[j][i] = dst[ dst[j][i-1] ][i-1];
    }
  }
  // for (int i=0;i<4;++i){
    // for (int j=0;j<=N;++j)cout<<dst[j][i]<<' ';cout<<'\n';
  // }
  cin >> Q;
  while (Q--){
    cin >>a >> b;
    --a;--b;
    if (a > b)swap(a,b);
    cout<<query(a,b)<<'\n';
  }
}
