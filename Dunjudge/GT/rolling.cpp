#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef pair<ll,pi> pii;
typedef vector<pi> vpi;
typedef set<ll> si;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define f first
#define s second
ll INF = 1e18;
ll MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (ll)x.size()
#define ALL(x) x.begin(),x.end()


vi adjList[100100];
int p[100100][18];
int N,Q,a,b,root;
int depth[100100],cnt=1;
int preorder[100100], ind[100100];
bool clear[100100];
set<int> MS;
int low[100100];

void d1(int x){
  low[x] = x;
  for (auto i : adjList[x]){
    d1(i);
    low[x] = min(low[x], low[i]);
  }
}

void dfs(int x, int u){
  // cout<<x<<' '<<u<<'\n';
    for (auto i : adjList[x]){
      depth[i] = depth[x] + 1;
      dfs(i, x);
    }
    preorder[cnt] = x;
    ind[x] = cnt;
    cnt++;
}

void d2(int x){
  for (auto i : adjList[x]){
    p[ind[i]][0] = ind[x];
    d2(i);
  }
}

int find_clear(int x){
  // for (int i=1;i<=N;++i)cout<<clear[i]<<' ';cout<<'\n';
  for (int i=17;i>=0;--i){
    if (!clear[p[x][i]]){
      // cout<<x<<' '<<p[x][i]<<'\n';
      x = p[x][i];
    }
  }
  // cout<<"Top "<<x<<'\n';
  return x;
}

bool cmp(int a, int b){
  return low[a] < low[b];
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin>>N>>Q;
  memset(p,0,sizeof(p));
  for (int i=1;i<=N;++i){
    MS.insert(i);
    cin>>a;
    if (a == 0)root=i;
    else {
      adjList[a].pb(i);
    }
  }
  d1(root);
  // for (int i=1;i<=N;++i)cout<<low[i]<<' ';cout<<'\n';
  for (int i=1;i<=N;++i)sort(ALL(adjList[i]), cmp);
  for (int i=0;i<=N;++i)clear[i] = 1;
  dfs(root, 0);
  d2(root);
  // for (int i=1;i<=N;++i)cout<<i<<' '<<preorder[i]<<' '<<p[i][0]<<'\n';
    for (int i = 1; i <= 17; i++){
      for (int j = 1; j <= N; j++){
        if (p[j][i-1] == -1) p[j][i] = -1;
        else p[j][i]=p[p[j][i-1]][i-1];
     }
   }
    for (int i=0;i<Q;++i){
      cin>>a>>b;
      if (a == 1){
        int x;
         for (int i=0;i<b;++i){
           x = *MS.begin();
           MS.erase(x);
           clear[x] = 0;
           // cout << "Fill " << x << '\n';
         } 
         cout << preorder[x] << '\n';
      }else{
        int x = find_clear(ind[b]);
        cout << depth[b] - depth[preorder[x]] <<'\n';
        clear[x] = 1;
        // cout << "clearing " << x << '\n';
        MS.insert(x);
      }
    }
}
