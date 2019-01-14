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
#define MOD 1000000007LL
#define lb lower_bound
#define ub upper_bound
#define dst distance
#define INF 1000000000

int N,M,a,b,ans;
stack<int> stk;

int main(){
  cin>>N>>M;
  multiset<int> A[N];
  for (int i=0;i<M;++i){
    cin>>a>>b;
    A[a].insert(b);
    A[b].insert(a);
  }
  for (int i=0;i<N;++i){
    if(A[i].size() == 1){
      stk.push(i);
    }
  }
  while(stk.size()){
    int x = stk.top();stk.pop();
    if(A[x].size() == 0)continue;
    ++ans;
    int t = *(A[x].begin());
    A[t].erase(A[t].find(x));
    A[x].erase(A[x].find(t));
    if (A[t].size() == 1)stk.push(t);
  }
  for (int i=0;i<N;++i){
    assert(A[i].size()!=1);
    if(A[i].size() != 0)++ans;
  }
  cout<<ans;
}