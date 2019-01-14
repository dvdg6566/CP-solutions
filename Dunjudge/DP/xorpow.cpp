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

int A[100100];
map<int,int>M;
vector<int> V;
int N,K,ans;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin >> N >> K;
  for (int i = 0; i < N; ++i){
    cin >> A[i];
  }
  V.pb(K);
  while(V.back() <= 128){
    V.pb(V.back() * K);
  }
  V.pop_back();
  for (int i=1;i<N;++i)A[i] = A[i]^A[i-1];
  M[0] = 1;
  for (int i = 0;i<N;++i){
    for (auto j : V){
      int req = j ^ A[i];
      ans += M[req];
    }
    M[A[i]]++;
  }
  cout << ans;
}
