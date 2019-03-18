#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 1e6;


ll N,T,a,b;
ll p[6],memo[1000100], mem2[1000100];

int main(){
  // freopen("input.txt","r",stdin);
  cin>>T;
  memo[1] = 10;
  for (int i=0;i<=4;++i)p[i] = 1;
  for (ll it=2;it<=1e6;++it){
    a = it*(it-1) %MOD;
    if (it != 2)for (int i=2;i<=4;++i)p[i] = (p[i] * i)%MOD;
    b = (p[4] + 2*p[3] + 3*p[2] + 4) %MOD;
    memo[it] = (memo[it-1] + a*b )%MOD;
    // if (it > 999997)cout<<it<<' '<<memo[it]<<'\n';
  }
  // return 0;
  for (ll it = 1; it <= MOD; ++it){
    a = it*(it-1) %MOD;
    for (int i=2;i<=4;++i)p[i] = (p[i] * i)%MOD;
    b = (p[4] + 2*p[3] + 3*p[2] + 4) %MOD;
    mem2[it] = (mem2[it-1] + a*b )%MOD;
  }
  cout<<'\n';
  while(T--){
    cin>>N;
    if (N < 1e6)cout<<memo[N]<<'\n';
    else {
      cout<<(mem2[N%MOD] + 812510 + (ll)(N%MOD-1)*mem2[MOD] )%MOD<<'\n';
    }
  }
}