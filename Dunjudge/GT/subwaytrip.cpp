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
#define MOD 1e9+7
#define lb lower_bound
#define ub upper_bound
#define INF 1000000000
#define ALL(x) x.begin(),x.end()

vpi adjList[100100];
vi trains[100100];
bool visited[100100];
ll N,M,E,a,b,t;
deque<int> dq;
ll dist[100100];

void bfs(int x){
    dq.pb(x);
    while(dq.size()){
    int t = dq[0];
    dq.pop_front();
    for (auto i : adjList[t]){
      if (lb(ALL(trains[t]), i.f) != ub(ALL(trains[t]),i.f) ){
        if(dist[t] >= dist[i.s])continue;
        dist[i.s] = dist[t];
        trains[i.s].pb(i.f);
        dq.push_front(i.s);
      }else{
        if(dist[t] + 1 >= dist[i.s])continue;
        dist[i.s] = dist[t] + 1;
        trains[i.s].pb(i.f);
        dq.pb(i.s);
      }
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>N>>M;
  for (int i=0;i<M;++i){
    cin>>a>>b>>t;
    adjList[a].pb(mp(t,b));
    adjList[b].pb(mp(t,a));
  }
  for (int i=1;i<=N;++i)sort(adjList[i].begin(), adjList[i].end());
  for (int i=1;i<=N;++i)dist[i]=INF;
  dist[1] = 0;
  bfs(1);
  if(dist[N] != INF)cout << dist[N];
  else cout<<-1;
}
