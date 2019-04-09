#include<bits/stdc++.h>
using namespace std;

string st;
int p = -1, ind,N,ans=1e9;

int main(){
  cin >> st;
  st += '2';
  N = st.size();
  ans = N-1;
  for (int i=0;i<N;++i){
    int x = st[i] - '0';
    if (x == p)continue;
    if(i != 0 && p){
      int t = max({ind , N-i-1, i-ind, min(i, N - ind-1)});
      ans = min(ans, t);
    }
    ind = i; p = st[i] - '0';
  }
  cout<<ans<<'\n';
}