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

string S;
int N;
bool B[100100];
vi V;

int main(){
  cin>>S;
  N = SZ(S);
  if (S[N-1] - '0'){cout<<-1;return 0;}
  for (int i=0;i<N-1;++i)B[i+1] = S[i] - '0';
  //for (int i=1;i<=N;++i)cout<<i<<' '<<B[i]<<'\n';
  for (int i=1;i<=N;++i){
    int p = N-i;
    if (B[i] != B[p]){
      cout<<-1;
      return 0;
    }
    if(B[i])V.pb(i);
  }
  if (!SZ(V) || V[0] != 1){
    cout<<-1;
    return 0;
  }
  int cur = 1, cs = 1;
  for (int i=1;i<SZ(V); ++i){
    int add = V[i] - cs;
    for (int x=cur;x<V[i];++x)cout<<x<<' '<<V[i]<<'\n';
    cur = V[i];
    cs = V[i];
  }
  for (int i=cur + 1; i <=N;++i)cout<<cur<<' '<<i<<'\n';
}