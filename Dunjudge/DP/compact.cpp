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

int N,K,L;
multiset<int> S;
int lower;
int DP[500100],A[500100];

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin >> N >> L >> K;
  for (int i = 1; i <= N; ++i)cin >> A[i];
  for (int i = 1; i <= N; ++i){
    S.insert(A[i]);
    // cout << "Adding " << A[i] << '\n';
    while (S.size()){
      if (*(--S.end()) > *S.begin() + K){
        // cout << "Erasing " << A[lower+1] << '\n';
        S.erase(S.find(A[lower + 1]));
        ++lower;
      }else break;
    }
    if (DP[lower] != -1 && S.size () >= L)DP[i] = DP[lower] + 1;
    else DP[i] = -1;
  }
  // for(int i=1;i<=N;++i)cout<<DP[i] << ' ';cout<< '\n';
cout << DP[N];
}
