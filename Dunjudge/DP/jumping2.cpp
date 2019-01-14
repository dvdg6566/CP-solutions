#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MOD 1e9+7
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (int)x.size()
ll INF = 1e18;

struct ConvexHull{
  deque<pi> dq;
  ConvexHull(){}
  ld intersect(pi a, pi b){
    return (ld) ((b.s - a.s)/(a.f-b.f));
  }
  void insert(pi cur){
    while (dq.size() > 1){
      if (intersect(dq[dq.size()-1],cur) <= intersect(dq[dq.size() -2],cur)){
        dq.pop_back();
      }
      else break;
    }
    dq.pb(cur);
  }
  ll query(ll xc){
    if (dq.size() == 0)return -INF;
    while (dq.size() > 1){
      if (dq[0].f * xc + dq[0].s >= dq[1].f * xc + dq[1].s)dq.pop_front();
      else break;
    }
    return dq[0].f*xc+dq[0].s;
  }
}* Hull;

struct ConvexHullB{
  deque<pi> dq;
  ConvexHullB(){}
  ld intersect(pi a, pi b){
    return (ld) ((b.s - a.s)/(a.f-b.f));
  }
  void insert(pi cur){
    while (dq.size() > 1){
      if (intersect(dq[dq.size()-1],cur) >= intersect(dq[dq.size() -2],cur)){
        dq.pop_back();
      }
      else break;
    }
    dq.pb(cur);
  }
  ll query(ll xc){
    if (dq.size() == 0)return -INF;
    while (dq.size() > 1){
      if (dq[0].f * xc + dq[0].s >= dq[1].f * xc + dq[1].s)dq.pop_front();
      else break;
    }
    return dq[0].f*xc+dq[0].s;
  }
}* HullB;

bool grid[5010][5010];
int H,W;
string st;
ll dp[5010], p[5010];

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin >> H >> W;
  for (int i=0;i<H;++i){
    cin>>st;
    for (int j =0;j<W;++j){
      grid[i][j] = (st[j] == '1');
    }
  }
  Hull = new ConvexHull();
  HullB = new ConvexHullB();
  for (int i = 1; i < W; ++i){
    for (int j=0;j<H;++j)dp[j] = INF;
    // for (int j=0;j<H;++j)cout<<grid[j][i]<<' ';cout<<'\n';
    Hull->dq.clear();
    for (int j = 0; j < H; ++j){
      if (grid[j][i-1]){
        // cout << "Inserting index " << -2*j << ' ' << j*j+p[j] << '\n';
        Hull->insert(mp(-2*j,j*j+p[j]));
      }
      if (grid[j][i]){
        ll t = Hull->query(j);
        if(t == -INF)continue;
        // cout << "Query " << j << ' ' << t << '\n';
        dp[j] = min(dp[j] , j*j+t);
      }
    }
    // for(int j=0;j<W;++j)cout<<dp[j] <<' ';cout<<'\n';
    HullB->dq.clear();
    for (int j = H-1; j >= 0; --j){
      if (grid[j][i-1]){
        HullB->insert(mp(-2*j, j*j+p[j]));
      }
      if (grid[j][i]){
        ll t = HullB->query(j);
        if (t == -INF)continue;
        dp[j] = min(dp[j], j*j+t);
        // assert(dp[j] >=p[j-1]);
      }
    }
    for (int j =0;j<H;++j){
      // cout << dp[j] << ' ';
      p[j] = dp[j];
      dp[j] = INF;
    }
    // cout<<'\n';
  }
  cout << *min_element(p,p+H);
}
