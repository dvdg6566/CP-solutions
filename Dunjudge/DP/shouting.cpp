#include<bits/stdc++.h>
using namespace std;

int out[500100], A[500100];
int N,K, cur=0;

int main(){
  cin>>N>>K;
  for (int i=1;i<=N;++i){
    cin>>A[i];
    A[i] = i - A[i] + 1;
  }
  for (int i=N;i>=1;--i){
    if (i < cur)cur = 0;
    if (A[i] != cur){
      out[A[i]] = out[cur] + 1;
      cur = A[i];
    }
  }
  for (int i=1;i<=N;++i)cout<<out[i]<<' ';
}