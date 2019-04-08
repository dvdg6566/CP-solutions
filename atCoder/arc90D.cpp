#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
#define f first
#define pb push_back
#define s second
#define mp make_pair

int d[100100];
vector<pi> aList[100100];
int N,M,a,b,c;
int INF = 1e9;

void dfs(int x){
  for (auto i : aList[x]){
    int nxt = d[x] + i.s;
    if (d[i.f] == -INF){
      d[i.f] = nxt;
      dfs(i.f);
    }else{
      if (nxt != d[i.f]){
        cout<<"No";
        exit(0);
      }
    }
  }
}

int main(){
  cin >> N >> M;
  for (int i=0;i<M;++i){
    cin>>a>>b>>c;
    aList[a].pb(mp(b,c));
    aList[b].pb(mp(a,-c));
  }
  for (int i=1;i<=N;++i)d[i] = -INF;
  for (int i=1;i<=N;++i){ 
    if (d[i] != -INF)continue;
    d[i] = d[i-1];
    dfs(i);
  }
  cout<<"Yes";
}