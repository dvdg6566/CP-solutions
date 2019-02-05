#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MOD 1e9+7
ll INF = 1e15;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (ll)x.size()
#define ALL(x) x.begin(),x.end()

int N,A[1001000], wind[1001000];
int U, curuni;
int ans=1e9;
map<int,int> M;


int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input.txt","r",stdin);
  U = 1;
  cin>>N;
  for (int i=0;i<N;++i){
    cin>>A[i];
    if (M[A[i]] == 0){
      M[A[i]] = U++;
    }
    A[i] = M[A[i]];
    // cout<<A[i]<<' ';
  }
  --U;
  // cout<<'\n';
  int ub = -1;
  for (int lb = 0; lb < N; ++lb){
    if (lb){
      // cout<< "Reducing " << A[lb]<<'\n';
      if (wind[A[lb-1]] == 1)--curuni;
      --wind[A[lb-1]];
    }
    while (curuni < U){
      if (ub == N-1){
        cout<<ans;
        return 0;
      }
      ub++;
      if (wind[A[ub]] == 0) ++ curuni;
      wind[A[ub]] ++;
      // cout<<ub<<' '<<curuni<<'\n';
    }
    // cout<<"R " <<lb<<' '<<ub<<'\n';
    ans = min(ans, ub-lb+1);
  }
  cout<<ans;
}
