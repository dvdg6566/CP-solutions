#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef double dl;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MOD 1e9+7
#define lb lower_bound
#define ub upper_bound
#define dst distance
#define INF 1000000000

ll grid[2010][2010];
ll TL[2010][2010];
ll TR[2010][2010];
ll BR[2010][2010];
ll BL[2010][2010];
ll H,W,ans;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin >> H >> W;
  for (int i = 1; i <= H; ++i)for (int j = 1; j <= W; ++j)cin >> grid[i][j];
  for (int i = 1; i <= H; ++i)for (int j = 1; j <= W; ++j)TL[i][j] = max(TL[i-1][j],TL[i][j-1]) + grid[i][j];
  for (int i = H; i > 0; --i)for (int j = W; j > 0; --j)BR[i][j] = max(BR[i+1][j], BR[i][j+1]) + grid[i][j];
  for (int i = H; i > 0; --i)for (int j = 1; j <= W; ++j)BL[i][j] = max(BL[i+1][j],BL[i][j-1]) + grid[i][j];
  for (int i = 1; i <= H; ++i)for (int j = W; j > 0; --j)TR[i][j] = max(TR[i][j+1],TR[i-1][j]) + grid[i][j];
  for (int i = 1; i <= H; ++i){
    for (int j = 1; j <= W; ++j){
      ans = max(ans, grid[i][j] + TL[i-1][j] + TR[i][j+1] + BR[i+1][j] + BL[i][j-1] );
      ans = max(ans,grid[i][j] + TL[i][j-1] + TR[i-1][j] + BR[i][j+1] + BL[i+1][j]);
    }
  }
  cout << ans;
  return 0;
  for (int i = 1; i <= H; ++i){
    for (int j = 1; j <= W; ++j){
      cout << TL[i][j] << ' ';
    }
    cout << '\n';
  }
  for (int i = 1; i <= H; ++i){
    for (int j = 1; j <= W; ++j){
      cout << TR[i][j] << ' ';
    }
    cout << '\n';
  }
  for (int i = 1; i <= H; ++i){
    for (int j = 1; j <= W; ++j){
      cout << BR[i][j] << ' ';
    }
    cout << '\n';
  }
  for (int i = 1; i <= H; ++i){
    for (int j = 1; j <= W; ++j){
      cout << BL[i][j] << ' ';
    }
    cout << '\n';
  }
  cout << ans;
}
