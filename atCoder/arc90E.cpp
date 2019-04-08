#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef pair<int,pi> pii;
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
priority_queue<pi, vector<pi>, greater<pi> > pq;
ll dist[100100], d[100100];
ll rep[100100], r[100100],a,b,w,N,M,S,T;
vpi adjList[100100];
vector<pii> edgeList;

void dijkstra(int start){
	memset(dist, -1, sizeof(dist));
	dist[start] = 0;
  rep[start] =1;
	pq.push(mp(0, start));
  while (!pq.empty()) {
    pi cur = pq.top();
    pq.pop();
    ll x = cur.s, d = cur.f;
    if (d > dist[x]) continue;
    for (auto it : adjList[x]) {
      ll nx = it.f, nd = d+it.s;
      if (dist[nx] != -1 && dist[nx] < nd) continue;
      if (dist[nx] != -1 && dist[nx] == nd){
        rep[nx] += rep[x];
        rep[nx] %= MOD;
        continue;
      }
      dist[nx] = nd;
      rep[nx] = rep[x];
      pq.push(mp(nd, nx));
    }
  }
}

int main(){
  // freopen("input.txt","r",stdin);
  cin>>N>>M>>S>>T;
  for (int i=0;i<M;++i){
    cin>>a>>b>>w;
    adjList[a].pb(mp(b,w));
    adjList[b].pb(mp(a,w));
    edgeList.pb(mp(w,mp(a,b)));
  }
  dijkstra(S);
  swap(dist,d);
  swap(rep,r);
  dijkstra(T);
  // for (int i=1;i<=N;++i)cout<<d[i] << ' '<<dist[i]<<' '<<r[i] << ' '<<rep[i]<<'\n';
  ll res = rep[S]*r[T]%MOD;
  ll op  = dist[S];
  assert(op == d[T]);
  // cout<<op<<'\n';
  // cout<<res<<'n';
  for (auto i : edgeList){ // Intersect on a edge
    a = i.s.f;
    b = i.s.s;
    if (d[a] > d[b]) swap(a,b);
    if (d[b] - d[a] != i.f)continue;
    if (dist[a] - dist[b] != i.f)continue;
    if (dist[a] + d[b] - i.f != op)continue;
    if (abs (dist[b] - d[a]) >= i.f)continue;
    // cout<<a<<' '<<b<<'\n';
    ll t = (r[a] * rep[b]) % MOD;
    t = (t * t) % MOD;
    res -= t;
    // cout<<a<<' '<<b<<' '<<t<<'\n';
    if(res<0)res += MOD;
  }
  // cout<<res<<'n';
  for (int i=1;i<=N;++i){ // Intersect on a node
    if (dist[i] == d[i] && 2*d[i] == op){
      ll t = (r[i] * rep[i]) %MOD;
      t = (t * t) %MOD;
      res -= t;
      // cout<<i<<' '<<t<<'\n';
      if(res<0)res += MOD;
    }
  }
  cout<<res%MOD;
}