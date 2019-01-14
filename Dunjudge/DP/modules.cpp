#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef double dl;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MOD 1e9+7
#define lb lower_bound
#define ub upper_bound
#define dst distance
#define INF 1000000000

int N,K,a,b,w;
struct edge{
  int a,b,w;
  edge(int _a, int _b, int _w): a(_a), b(_b), w(_w) {}
};
vector<edge>V;
vector<ll> speed;
vector<pi> V2;
vector<ll> sMEMO;
ll tiet[1000100];

bool query(int x){
  ll cm = 0;
  int index = 0;
  ll M = 0;
  for (int i = 0; i < N; ++i){
     while (index < N && tiet[index] <= V[i].a - x){
       cm = max(cm,sMEMO[index]);
       ++index;
     }
    sMEMO[speed[i]] = cm+V[i].w;
    M = max(M,sMEMO[speed[i]]);
  } 
  return M >= K;
}

bool cmp(edge a, edge b){return a.a < b.a;}
int M;
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin >> N >> K;
  speed.resize(N);
  sMEMO.resize(N);
  for (int i = 0; i < N; ++i){
    cin >> a >> b >> w;
    M = max(M,w);
    V.pb({a,b,w});
  }
  sort(V.begin(),V.end(), cmp);
  for (int i =0;i<N;++i){
    V2.pb(mp(V[i].b,i));
  }
  sort(V2.begin(),V2.end());
  for (int i = 0; i < N; ++i){
    speed[V2[i].s] = i;
    tiet[i] = V2[i].f;
  }
  int lower = 0, upper = INF;
  if (!query(0)){
    cout << -1;
    return 0;
  }
  if (M >= K){
    cout << INF;
    return 0;
  }
  while (upper > 1+lower){
    int mid = (upper+lower)/2;
    if (query(mid)){
      lower = mid;
    }else upper = mid;
  }

  if (query(lower))cout << lower;
  else cout << upper;
  
}

