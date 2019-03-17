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
ll MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (ll)x.size()
#define ALL(x) x.begin(),x.end()
int l,r,A[200100], B[200100], N;

int main(){
  cin>>N;
  for (int i=0;i<N;++i){cin>>A[i];B[i] = A[i];}
  sort(A,A+N);
  l = A[N/2-1];
  r = A[N/2];
  for (int i=0;i<N;++i){
    if (B[i] <= l)cout<<r<<'\n';
    else cout<<l<<'\n';
  }
}