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
#define SZ(x) (int)x.size()
#define INF 1000000000

vi adjList[100100], rep[100100];
int useless[100100];
int col[100100];
int d[100100];
int p[100100];
int N,a,b,T;
string st;
int furthest;

void dfs(int x){
    if (adjList[x].size() == 1 && x != 1){
      useless[x] = !col[x]; // Returns 1 if it is white
      return;
    }
    bool bad = !col[x];
    for (auto i : adjList[x]){
      if (p[i] != -1)continue;
      p[i] = x;
      dfs(i);
      if (!useless[i])bad = 0;
    }
    useless[x] = bad;
}

void dfs2(int x){
  if (col[x])d[x]++;
  for (auto i : rep[x]){
    if (d[i] != -1)continue;
    d[i] = d[x];
    dfs2(i);
  }  
}

int R,P;
int32_t main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin >> N;
  for (int i =1;i<N;++i){
    cin>>a>>b;
    adjList[a].pb(b);
    adjList[b].pb(a);
  }
  cin>>st;
  for(int i=1;i<=N;++i)col[i] = (st[i-1] == 'W');
  memset(p,-1,sizeof(p));
  p[1] = 0;
  for (int i=1;i<=N;++i)d[i]=-INT_MAX;
  dfs(1);
  d[1] = 0;
  for (int i =1; i <= N; ++i){
    if (!useless[i]){
      ++R;
      for (auto it : adjList[i]){
        if (useless[it])continue;
        rep[i].pb(it);
      }
    }
  }
  int root = 1;
  while (rep[root].size() == 1 && col[root] == 0){
    int p =root;
    root = rep[root][0];
    --R;
    // cout << "FF\n";
    useless[p] = 1;
    rep[root].erase(find(rep[root].begin(),rep[root].end(),p));
  }
  if (R == 0){
    cout << 0;
    return 0;
  }
  --R;R*=2;
  for (int i = 1;i<=N;++i){
    if(useless[i])continue;
      if (!useless[i]){++P;}
    if (rep[i].size()%2)col[i] = 1-col[i];
    // cout << col[i] << ' ';
    if (col[i])++R;
  }
  // for (int i=1;i<=N;++i)cout<<col[i];cout<<'\n';
  // cout <<R  << '\n';
  if (P == 1 && col[root] == 1){
    cout << 1;
    return 0;
  }
  // cout <<'n';
  memset(d,-1,sizeof(d));
  d[1] = 0;
  dfs2(1);
  int ind = max_element(d+1,d+N+1) - d;
  memset(d,-1,sizeof(d));
  d[ind] = 0;
  dfs2(ind);
  // cout << R << '\n';
  cout << R - 2*(*max_element(d+1,d+N+1));
}
