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
#define INF 100000000000000000
#define SZ(x) x.size()
#define ALL(x) x.begin(),x.end()

int N,G;
ll dp[8000][2], opt[8000][2];
ll rsq[8000];

ll cost(ll a, ll b){
  return (b-a+1)*(rsq[b] - rsq[a-1]);
}

void dnc(ll s, ll e, ll x, ll y, ll k){
  ll m=(s+e)/2;
  dp[m][k] = INF;
  for (int i=x;i<=y;++i){
    if (dp[m][k] > dp[i][1-k] + cost(i+1,m)){
      dp[m][k] = dp[i][1-k] + cost(i+1, m);
      opt[m][k] = i;
    }
  }
  if (s < m)dnc(s,m-1,x,opt[m][k], k);
  if (m < e)dnc(m+1,e,opt[m][k],y, k);
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin>>N>>G;
  for (int i=1;i<=N;++i){cin>>rsq[i];rsq[i] += rsq[i-1];}
  for (int i=1;i<=N;++i)dp[i][0] = INF;
  for (int i=1;i<=G;++i){
    dnc(1,N,0,N,i%2);
  }
  cout << dp[N][G%2] << '\n';
  return 0;
  for (int i=1;i<=2;++i){
    for (int j=1;j<=N;++j)cout << dp[j][i] << ' ';cout << '\n';
  } 
}
