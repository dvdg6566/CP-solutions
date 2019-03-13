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

int A[100100];
vpi B,C;
int N;


int main(){
  cin >> N;
  for (int i=0;i<N;++i)cin>>A[i];
  B.resize(100100); C.resize(100100);
  for (int i=0;i<100100; ++i)B[i] = C[i] = mp(N/2,i);
  for (int i=0;i<N;i = i+2){
    B[A[i]].f --;
    //cout<<"Change " << i << " to " << B[i].f << '\n';
  }
  for (int i=1;i<N;i = i+2){
    C[A[i]].f--;
    //cout<<"Change " << i << " to " << B[i].f << '\n';
  }
  sort(ALL(B));
  sort(ALL(C));
  if (B[0].s == C[0].s)cout<<min(B[0].f+C[1].f, B[1].f+C[0].f);
  else cout<<B[0].f+C[0].f;
}