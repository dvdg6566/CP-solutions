#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<int, pi> pii;
typedef set<int> si;
typedef vector<pi> vpi;
typedef double dl;
#define mp make_pair
#define pb push_back
#define f first
#define s second
ll MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
#define INF 1000000000
#define SZ(x) x.size()
#define ALL(x) x.begin(),x.end()

int N,Q,C,a,b,c;
vpi V;
int dp[25], p[25];

int main(){
  freopen("input.txt","r",stdin);
  cin >> N >> C;
  for (int i=0;i<N;++i){
    cin>>a>>b;
    V.pb(mp(a,b));
  }
  p[0] = V[0].s;
  p[1] = V[0].f;
  for (int i=1;i<N;++i){
    dp[0] = p[0]*V[i].s;
    for (int j=1;j<=C;++j){
      dp[j] = p[j-1] * V[i].f + p[j] * V[i].s;
    }
    swap(dp,p);
  }
  cin>>Q;
  for (int i=0;i<Q;++i){
    int j;
    cin >> j >> a >> b;
    --j;
    // Undo from p
    memset(dp,0,sizeof(dp));
    dp[0] = p[0] / V[j].s;
    for (int i=1;i<=C;++i){
      dp[i] = (p[i] - (V[j].f * dp[i-1]) ) / V[j].s;
    }
    V[j] = mp(a,b);
    p[0] = dp[0] * V[j].s;
    for (int i=1;i<=C;++i){
      p[i] = dp[i-1] * V[j].f + dp[i] * V[j].s;
    }
    for (int i=0;i<=C;++i)cout<<p[i]<<' ';cout<<'\n';
    cout<<p[C]<<'\n';
  }
}
