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

ll A[200100],DP[200100];
map<ll,ll> M;
ll N,K;
    
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin >> N >> K;
  for(int i=0;i<N;++i)cin>>A[i];
  for(int i=1;i<N;++i)A[i] += A[i-1];
  M[0] = -1;
  for (int i=0;i<N;++i){
    ll t = A[i] - K*(i+1);
    DP[i] = max(DP[i], DP[i-1]);
    // cout << "Querying " << t << '\n';
    if (M.lb(t) == M.ub(t)){
      M[t] = i;
    }else{
      ll x = M[t];
      DP[i] = max(DP[i], DP[x] + (i-x));
      M[t] = i;
      // cout << "Updated " << t << ' ' << " with " << i << '\n';
    }
  }
  // for (int i = 0; i < N; ++i)cout << DP[i] << ' ';
  cout << *max_element(DP,DP+N);
}
