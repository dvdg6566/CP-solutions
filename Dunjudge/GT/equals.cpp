#include<bits/stdc++.h>
using namespace std;
#define pb push_back

int p[100100];
int par(int x){return x == p[x] ? x : p[x] = par(p[x]) ;}
int N,M,a,b;
int A[100100];
vector<int> V[100100];

int main(){
  cin>>N>>M;
  for (int i=1;i<=N;++i)cin>>A[i];
  for (int i=1;i<=N;++i)p[i] = i;
  for (int i=0;i<M;++i){
    cin>>a>>b;
    p[par(a)] = par(b);
  }
  for (int i=1;i<=N;++i){
    V[par(i)].pb(i);
  }
  map<int,int> M;
  int ans = 0;
  for (int i=1;i<=N;++i){
    for (auto it : V[i])M[it] = 1;
    for (auto it : V[i]) ans += M[A[it]];
    M.clear();
  }
  cout<<ans;
}