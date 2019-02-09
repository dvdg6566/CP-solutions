#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef pair<ll,pi> pii;
typedef vector<ll> vi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define ALL(X) X.begin(),X.end()
#define SZ(X) (int)X.size()
#define lb lower_bound
#define ub upper_bound
ll MOD = 1e9+7;
ll INF = 1e15;

vpi adjList[100100];
int dist[100100];
int p[100100];
int par(int x){return (x == p[x]) ? x:p[x] = par(p[x]);}
int N,E,a,b;
char c;
vector<pair<char, pi> > query;

void dfs(int x){
  for (auto i : adjList[x]){
    if (dist[i.f] != -1)continue;
    int t = (dist[x] + i.s) % 2;
    dist[i.f] = t;
    dfs(i.f);
  }
}

int main(){
  // freopen("in.txt","r",stdin);
  cin>>N>>E;
  for (int i=0;i<E;++i){
    cin>>c>>a>>b;
    query.pb(mp(c, mp(a,b)));
    if (c == 'A'){
      adjList[a].pb(mp(b, 1));
      adjList[b].pb(mp(a, 1));
    }
    if (c == 'R'){
      adjList[a].pb(mp(b,0));
      adjList[b].pb(mp(a,0));
    }
  }
  memset(dist,-1,sizeof(dist));
  for (int i =1;i<=N;++i){
    if (dist[i] != -1)continue;
    dist[i] = 1;
    dfs(i);
  }
  // for (int i=1;i<=N;++i)cout<<dist[i]<<' ';cout<<'\n';
  for (int i=1;i<=N;++i)p[i] = i;
  for (auto i :query){
    if (i.f != 'Q'){
      p[par(i.s.f)] = par(i.s.s);
      continue;
    }
    if (par(i.s.f) != par(i.s.s)){
      cout<< "?\n";
      continue;
    }
    if (dist[i.s.f] == dist[i.s.s])cout<<"R\n";
    else cout << "A\n";
  }
}
