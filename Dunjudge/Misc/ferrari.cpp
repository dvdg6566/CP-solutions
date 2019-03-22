#include<bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
ll m = 1e9+7;

int A[100100],N,a;
set<int> extra;
int ss = 100000;
bitset<100100> bs;
vector<int> primes;

void seive(){
  bs.set(); bs[0] = bs[1] = 0;
  for (ll i=2;i<ss;++i){
    if (bs[i]){
      for (ll j=i*i;j<ss;j+=i){
        bs[j] = 0;
      }
      primes.pb(i);
    }
  }
}

ll exp(ll e, ll b){
  if (b == 0)return 1;
  ll memo = exp(e,b/2);
  if (b%2 ==0)return (memo*memo)%m;
  return ((memo*memo)%m*e)%m;
}

int main(){
  seive();
  cin >> N;
  for (int i=0;i<N;++i){
    cin >> a;
    ++a;
    for (int j=0;j<primes.size(); ++j){
      int c = 0;
      while (a % primes[j] == 0){
        a /= primes[j];
        ++c;
      }
      A[j] = max(A[j], c);
      if (a == 1)break;
    }
    if (a != 1)extra.insert(a);
  }
  ll res = 1;
  for (int i = 0;i<primes.size();++i){
    res = res * exp(primes[i], A[i]);
    res = res % m;
  }
  for (auto it : extra){
    res = (res * it)%m;
  }
  cout<<res-1;
}