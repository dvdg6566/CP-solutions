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
ll MOD = 1e9;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (ll)x.size()
#define ALL(x) x.begin(),x.end()

ll l, r, ans, N, T, a, leftb, rightb, lend, rightend;
ll A[1000100];
multiset<ll> slide;

int main(){
  // freopen("input.txt","r",stdin);
  cin>>N;
  for (int i=1;i<=N;++i){cin>>A[i];A[i] += A[i-1];}
  for (int i=1;i<=N;++i)A[i+N] = A[i] + A[N];
  T = (N+1)/2;
  for (int i=1;i<=T;++i){
    slide.insert(A[i] + A[N] - A[(N + i - T)]);
  }
  ans = max(ans, *slide.begin());
  for (int i=2;i<=N;++i){
    slide.insert(A[i+T-1] - A[i-1]);
    // cout<<"Insert " << A[i+T-1]-A[i-1]<<'\n';
    slide.erase(slide.find(A[i-1] + A[N] - A[N+(i-1) - T]));
    // cout<<"Erase " << A[i-1] + A[N] - A[N+(i-1) - T] <<'\n';
    ans = max(ans, *slide.begin());
  }
  cout<<ans;
}
