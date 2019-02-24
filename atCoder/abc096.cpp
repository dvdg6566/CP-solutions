#include<bits/stdc++.h>
using namespace std;
#define pb push_back

bitset<10000> bs;
vector<int> V;
int N;

int main(){
  bs.set();
  bs[0] = bs[1] = 0;
  for (int i=2;i<1500;++i){
    if (bs[i] == 0)continue;
    if (i%5 == 1)V.pb(i);
    for (int j=i*i; j < 10000; j += i)bs[j] = 0;
  }
  cin>>N;
  for (int i=0;i<N;++i)cout<<V[i]<<' ';  
}