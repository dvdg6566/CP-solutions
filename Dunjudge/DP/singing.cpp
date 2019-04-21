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
ll INF = 1e8;
ll MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()

vi bars[1000000];
int N,K,B,a,b;
vi sig;
ll dp[1000000][2];

void st(int a, int b){
  for (int i=1;i<=b;++i){
    dp[i][a] = (dp[i][a] + dp[i-1][a]) % MOD;
  }
}

int main(){
  freopen("in.txt","r",stdin);
  cin >> N >> K >> B;
  for (int i=0;i<N;++i){
    cin >> a >> b;
    bars[a].pb(b);
  }


  for (int i=0;i<=B;++i){
    if (!SZ(bars[i]))continue;
    bars[i].pb(-1);
    sort(ALL(bars[i]));
    sig.pb(i);
  }
  int cur = sig[0];
  for (int j=1;j<SZ(bars[cur]);++j){
    dp[j][0] = 1;
  }
  st(0, SZ(bars[cur]));
  // for (int i=1;i<=3;++i)cout<<dp[i][0]<<' ';cout<<'\n';

  for (int i=1;i<SZ(sig); ++i){
    int cur = sig[i];
    for (int j=1;j<SZ(bars[cur]);++j){
      int t = bars[cur][j];
      int lo = max(0, t-K);
      int ma = t+K;
      int x = lb(ALL(bars[cur-1]), lo) - bars[cur-1].begin();
      int y = ub(ALL(bars[cur-1]), ma) - bars[cur-1].begin() - 1;
      int r = (MOD + dp[y][1-i%2] - dp[x-1][1-i%2]) % MOD;
      // if (i == 6)cout<<"Fill " << t<<' '<<lo<<' '<<ma<<' '<<x<<' '<<y<<'\n';
      dp[j][i%2] = r;
    }
    st(i%2, SZ(bars[cur]));
    // for (int x=1;x<SZ(bars[cur]);++x)cout<<dp[x][i%2]<<' ';cout<<'\n';
  }
  cout << dp[SZ(bars[sig.back()])-1][1-SZ(sig) % 2];
}
