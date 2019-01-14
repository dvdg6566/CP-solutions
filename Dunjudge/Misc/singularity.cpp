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

bitset<10000> B;
vector<int> primes;
int N,start,ans;
set<int> S,tmp;
vector<int> V,T[1001000];

void factor (int x){
  int t = V[x];
  for (auto i : primes){
    if (t%i == 0){
      t /= i;
      T[x].pb(i);
      while(t%i == 0)t /= i;
    }
  }
  if (t != 1)T[x].pb(t);
}

int main(){
  B.reset(); //Set everything to 1, reset sets to 0  
  B[0] = B[1] = 1;
  for (int i = 2; i < 10000; ++i){
    if(B[i])continue;
    primes.pb(i);
    for (int j = i*i; j < 10000; j += i)B[j] = 1;
  }
  // for (auto i : primes)cout << i << '\n';
  freopen("input.txt","r",stdin);
  cin>>N;
  V.resize(N);
  for(int i=0;i<N;++i)cin>>V[i];
  for (int i =0;i<N;++i){
    factor(i);
  };
  for (int i =0;i<N;++i){
    for (auto it : T[i]){
      // cout << it << ' ';
      if (S.lb(it) != S.ub(it))tmp.insert(it);
    }
      while (start != i&& tmp.size()){
        for (auto j : T[start]){
          S.erase(j);
          tmp.erase(j);
        }
        ++start;
      }
       cout << (i-start) << '\n';
      for (auto it : T[i])S.insert(it);
      ans += (i-start);
  }
  cout << ans;
}
