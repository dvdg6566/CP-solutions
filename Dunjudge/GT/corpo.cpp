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
#define INF 10000000
#define SZ(x) x.size()
#define ALL(x) x.begin(),x.end()

vi adj[200100];
int p[200100][18], depth[200100];
int N,a,b;
si dp[200100];
int res[200100];

int lca(int a, int b){
  if (a == b)return a;
  if (depth[a] < depth[b])swap(a,b);
  int h = depth[a] - depth[b];
  for (int i=0;i<18;++i){
    if ((1<<i)&h){
      a = p[a][i];
    }
  }
  if (a == b)return a;
  for (int i=17;i>=0;--i){
    if (p[a][i] == p[b][i])continue;
    a = p[a][i]; b = p[b][i];
  }
  return p[a][0];
}

void dfs(int x){
  stack<int> st;
  int curmax = -1, curnode = -1;
  for (auto i : adj[x]){
    int t = lca(x,i);
    cout << x << ' ' << i << ' ' << t<<'\n';
    dfs(i);
    if (t == i || x == t){
      // Case 1 is where its a superset
      st.push(i);
      if (res[x] > curmax){
        curmax = res[x];
        curnode = i;
      }
    }
    // Case 2, where it is a disjoint set, can be ignored
  }
  if (curnode != -1)swap(dp[x], dp[curnode]);
  while(st.size()){
    int t = st.top();st.pop();
    cout << x << ' ' << t << '\n';
    dp[x].insert(t);
    if (t == curnode)continue;
    for (auto i : dp[t])dp[x].insert(i);
  }
  res[x] = SZ(dp[x]);
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  freopen("input.txt","r",stdin);
  cin>>N;
  memset(p,-1,sizeof(p));
  for (int i=2;i<=N;++i){
    cin>>a;
    p[i][0] = a;
    depth[i]= depth[a] + 1;
  }
  for (int i = 1; i < 18;++i){
    for (int j = 2; j <= N; ++j){
      if (p[j][i-1] != -1)p[j][i] = p[p[j][i-1]][i-1];
    }
  }
  for (int i=2;i<=N;++i){
    cin>>a;
    adj[a].pb(i);
    // cout<<i<<' '<<a<<'\n';
  }
  dfs(1);
  for (int i=1;i<=N;++i)cout<<res[i]<<' ';
}
