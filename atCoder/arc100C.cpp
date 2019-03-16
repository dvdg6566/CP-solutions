#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll A[200100], N, ans, M;

int main(){
  cin>>N;
  for (int i=1;i<=N;++i)cin>>A[i];
  for (int i=1;i<=N;++i)A[i] -= i;
  sort(A+1, A+N+1);
  M = A[(N+1)/2];
  for (int i=1;i<=N;++i)ans += abs(A[i] - M);
  cout<<ans;
}