#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef double dl;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MOD 1e9+7
#define lb lower_bound
#define ub upper_bound
#define INF 1000000000

int A[300100];
multiset<int> want, dw;
int N,C,K;
ll sum,ans;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin >> N >> C >> K;
  ++K;
  for (int i =0;i<N;++i)cin>>A[i];
  for (int i=0;i<N;++i){
    if (i >= K){
    if (dw.lb(A[i-K]) != dw.ub(A[i-K]))dw.erase(dw.find(A[i-K]));
    else {want.erase(want.find(A[i-K]));sum -= A[i-K];}
    }
    want.insert(A[i]);
    sum += A[i];
    if (want.size() > C){
      sum -= *want.begin();
      dw.insert(*want.begin());
      want.erase(want.begin());
    }
    if (want.size() && dw.size()){
      if (*want.begin() < *(--(dw.end()))){
      int t = *want.begin();
      want.erase(want.begin());
      want.insert(*(--dw.end()));
      dw.erase(--dw.end());
      dw.insert(t);
    }}
    if (i>= K)assert(want.size() + dw.size() == K);
    // assert(want.size() <= C);
    ans = max(ans,sum);
  }
  cout << ans;
  
}
