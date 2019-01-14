#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<int, pi> pii;
typedef set<int> si;
typedef vector<pi> vpi;
typedef double dl;
#define mp make_pair
#define pb push_back
#define f first
#define s second
ll MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
#define INF 1000000000
#define ALL(x) x.begin(),x.end()

map<pi,int> M;
map<int,int> C, colind;
map<pii,bool> visited;
int N,a,b,c,counter;
vi adjList[5010];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
vector<pii> V;

int dist[5010];
queue<int> q;
int bfs(int start){
  for (int i=1;i<counter;++i)dist[i] = -1;
  q.push(start);
  dist[start] = 0;
  int x;
  while(q.size()){
    x = q.front();q.pop();
    for (auto i : adjList[x]){
      if(dist[i]!=-1)continue;
      dist[i] = dist[x] + 1;
      q.push(i);
    }
  }
  return dist[x];
}


int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin>>N;
  V.pb(mp(-1,mp(-1,-1)));
  for (int i=1;i<=N;++i){
    cin>>a>>b>>c;
    ++c;
    V.pb(mp(c,mp(a,b)));
    C[c]++;
    M[mp(a,b)] = i;
  }
  counter = N+1;
  for (auto i : C){
    if (i.s == 1)continue;
    colind[i.f] = counter;
    ++counter;
  }
  for (int i=1;i<=N;++i){
    if (C[V[i].f] == 1)continue; // Only 1 of that colour
    int x = colind [V[i].f];
    // cout<<"HELLO\n";
    adjList[i].pb(x);
    adjList[x].pb(i);
  }
  for (int i=1;i<=N;++i){
    for (int k=0;k<2;++k){
      if (visited[mp(k, V[i].s)])continue; // Already built
      bool oth = 0;
       for (int t=k*2; t <k*2+2; ++t){
         int cx = V[i].s.f;
         int cy = V[i].s.s;
         visited[mp(k,mp(cx,cy))] = 1;
         while(1){
           cx += dx[t];
           cy += dy[t];
           int ind = M[ mp(cx,cy )];
           if (ind == 0)break;
           visited[mp(k, mp(cx,cy))] = 1;
           adjList[ind].pb(counter);
           adjList[counter].pb(ind);
         } 
          if (cx-dx[t] == V[i].s.f && cy-dy[t] == V[i].s.s)continue;
          oth = 1;
       }
       if(!oth)continue;
          adjList[i].pb(counter);
          adjList[counter].pb(i);
          ++counter;
    }
  }
  assert(counter<5005);
  for (int i=1;i<=100;++i){
    if(adjList[i].size() == 0)break;
    // cout<<i<<": ";
    // for (auto it:adjList[i])cout<<it<<' ';cout<<'\n';
  }
  int ans = 0;
  for (int i=1;i<=N;++i){
    ans = max(ans,bfs(i));
  }
  cout<<ans/2;
}
