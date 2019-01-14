#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MOD 1e9+7
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()

vi adjList[300100];
ll dst[300100];
ll N,M,a,b;
pi range[300100];
ll opt[300100];

void dfs(int x){
  if (adjList[x].size() == 0){
    assert(x > N);
    range[x] = mp(dst[x], dst[x]);
    return;
  } 
  for (auto i : adjList[x])dfs(i);
  vector<int> V;
  for (auto i : adjList[x]){
    V.pb(range[i].f);
    V.pb(range[i].s);
  }
  sort(ALL(V));
  int l = V[adjList[x].size() - 1];
  int r = V[adjList[x].size()];
  ll ans = 0;
  for (auto i : adjList[x]){
    ans += opt[i];
    if (l >= range[i].f && l <= range[i].s)continue;
    else if (l < range[i].f)ans += range[i].f - l;
    else ans += l - range[i].s;
  }
  range[x] = mp(l,r);
  opt[x] = ans;
  for (auto i : adjList[x]){
    // if (x == 2)cout << range[i].f << ' ' << range[i].s<<'\n';
    ans -= opt[i];
    if (r >= range[i].f && r <= range[i].s)continue;
    else if (r < range[i].f)ans -= (range[i].f - r);
    else ans -= (r - range[i].s);
  }
  assert(ans == 0);
  cout << "Node " << x << '\n';
  cout << "Optimal " << opt[x] << '\n';
  cout << "Range " << range[x].f << ' ' << range[x].s<<'\n';
  return;
}
int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  freopen("input.txt","r",stdin);
  cin>>N>>M;
  for (int i=2;i<=N+M;++i){
    cin >> a >> b;
    adjList[a].pb(i);
    dst[i] = dst[a] + b;
  }
  dfs(1); 
  cout << opt[1];
}
