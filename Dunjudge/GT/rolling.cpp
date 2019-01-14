#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
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

vi aList[100100];
vpi adjList[100100];
int p[100100][18];
int N,Q,a,b,root;
int dst[100100],cnt=1;
int low[100100];
int preorder[100100], ind[100100];
bool empty[100100];
set<int> MS;

void dfs2(int x){
    for (auto i : adjList[x]){
      dst[i.s] = dst[x] + 1;
      dfs2(i.s);
    }
    preorder[cnt] = x;
    ind[x] = cnt;
    cnt++;
}

void dfs(int x){
  int l = x;
  for (auto i : aList[x]){
    dfs(i);
    l = min(x, low[i]); 
  } 
  low[x] = l;
}

int find_empty(int x){
  for (int i=17;i>=0;--i){
    if (p[x][i] != -1 && !empty[p[x][i]]){
      x = p[x][i];
    }
  }
  return x;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin>>N>>Q;
  memset(p,-1,sizeof(p));
  for (int i=1;i<=N;++i){
    MS.insert(i);
    cin>>a;
    if (a == 0)root=i;
    else {
      p[i][0] = a; 
      aList[a].pb(i);
    }
  }
  for (int i=1;i<=N;++i){
    for (auto j : aList[i]){
      adjList[i].pb(mp(low[j], j));
    }
  }
  dfs(root);
  for (int i=1;i<=N;++i)sort(ALL(adjList[i]));
  dfs2(root);
  for (int i=1;i<=N;++i)empty[i] = 1;
  // for (int i=1;i<=N;++i)cout<<i<<' '<<ind[i]<<'\n';
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
         for (int j=0;j<b;++j){
           x = preorder[*MS.begin()];
           MS.erase(MS.begin());
           empty[x] = 0;
           // cout << "Fill " << x << '\n';
         } 
         cout << x << '\n';
      }else{
        int x = find_empty(b);
        cout << dst[b] - dst[x] <<'\n';
        // assert(empty[x] == 0);
        empty[x] = 1;
        // cout << "Emptying " << x << '\n';
        MS.insert(ind[x]);
        // assert(preorder[ind[x]] == x);
      }
    }
}
