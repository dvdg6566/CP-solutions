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
#define ALL(X) (X).begin(), (X).end()
ll INF = 1000000000000000000;
ll N,M,Q;
ll adjMat[110][110][16];
ll A[4];
ll a,b,w;
string st;
map<string,int>Mp;

int main(){
  Mp["ground"] = 0;
  Mp["water"] = 1;
  Mp["grass"] = 2;
  Mp["forest"] = 3;
  cin>>N>>M>>Q;
  cin>>A[0]>>A[1]>>A[2]>>A[3];
  memset(adjMat,-1,sizeof(adjMat));
  for (int i=1;i<=N;++i)for (int t=0;t<16;++t)adjMat[a][a][t] = 0;

  for (int i=0;i<M;++i){
    cin>>a>>b>>w>>st;
    for (int t=0;t<16;++t){
      if ((1<<(Mp[st])) & t){
        if(adjMat[a][b][t] == -1 || adjMat[a][b][t] > w)
        adjMat[a][b][t] = adjMat[b][a][t] = w;
      }
    }
  }
  for (int t=0;t<16;++t){
    for (int k=1;k<=N;++k){
      for (int i=1;i<=N;++i){
        for (int j=1;j<=N;++j){
          if(adjMat[i][k][t] == -1||adjMat[k][j][t]==-1)continue;
          if (adjMat[i][j][t]==-1||adjMat[i][j][t] > adjMat[i][k][t] + adjMat[k][j][t]) adjMat[i][j][t] = adjMat[i][k][t] + adjMat[k][j][t];
        }
      }
    }
  }
  for (int t=1;t<16;++t){
    ll r = 0;
    for (int it=0;it<4;++it){
      if ((1<<it) & t)r += A[it];
    }
    for (int i=1;i<=N;++i)for (int j=1;j<=N;++j)if (adjMat[i][j][t] > -1)adjMat[i][j][t] += r;
  }
  for (int i=0;i<Q;++i){
    ll ans=INF;
    cin>>a>>b;
    if(a==b){cout<<0<<'\n';continue;}
    for (int t=0;t<16;++t)if(adjMat[a][b][t]!=-1)ans=min(ans,adjMat[a][b][t]);
    if(ans!=INF)cout<<ans<<'\n';
    else cout<<-1<<'\n';
  }
}