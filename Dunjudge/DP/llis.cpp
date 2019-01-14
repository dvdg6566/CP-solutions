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

int dp[1000100], h[1000100], pre[1000100];
int A[1000100], ind[1000100];
int N,K;
int res=INF;

int LIS(){
  // for (int i=1;i<=N;++i)pre[i] = i;
 int l = 0;
  for (int i = 1; i <= N; ++i){
    int p = lower_bound(h,h+l,A[i])-h;
    h[p] = A[i];
    // cout << "Updating " << p << " to " << A[i] << '\n';
    l = max(l,p+1);
    if (p){
      pre[p+1] = ind[i] = pre[p];
      // cout << "Chekcing " << p << '\n';
      // cout << i << ' ' << ind[p] << ' '<< pre[i] << '\n';
    }else pre[p+1] = ind[i] = i;
    dp[i] = p+1;
  }
  return l;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin>>N>>K;for(int i=1;i<=N;++i)cin>>A[i];
  int ans = LIS();
 for (int i=1;i<=N;++i){
   if(dp[i] == ans)res = min(res,i-ind[i] +1);
   // cout << i << ' '<<dp[i] << ' ' << ind[i] << '\n';
 }
 cout << res;
}

