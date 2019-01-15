#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end

vi adjList[100100];
ll p[100100][17];
ll dist[100100], tmp[100100];
ll desc[100100], par[100100], depth[100100];
ll N,a,b,Q;

void dfs(int x){
  if (adjList[x].size() == 1 && x-1){
    desc[x] = 1;
    return;
  }
  desc[x] = 1;
  for (auto i : adjList[x]){
    if (par[i] != -1)continue;
    par[i] = x;
    depth[i] = depth[x] + 1;
    dfs(i);
    desc[x] +=  desc[i];
  }
}

ll choose2(ll a){return a*(a-1)/2;}
ll fd(int a, int b, int l){return dist[a] + dist[b] - 2*dist[l];}

void dfs2(int x){
  for (auto i : adjList[x]){
    if (par[i] != x)continue;
    dist[i] = dist[x] + tmp[i];
    dfs2(i);
  } 
}

int LCA(int a, int b){
	if (a == b)return a;
	if (depth[a] < depth[b])swap(a,b);
	ll h = depth[a]-depth[b];
	for (ll i = 0; i < 17; i++) {
	  if (((1 << i) & h) > 0) { 
		a = p[a][i];
	  }
	}
	if (a == b)return a;
	for (ll i = 16; i >= 0; i--){
		if (p[a][i] != p[b][i]){
			a = p[a][i];
			b = p[b][i];
		}
	}
	return p[a][0];
}

int fp(int c, int d){
  for (int i = 0; i < 17; i++) {
    if (((1 << i) & d) > 0) {
      if (c==-1) return -1;
      c = p[c][i];
    }
  }
  return c;
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin >> N;
  for (int i=0;i<N-1;++i){
    cin>>a>>b;
    adjList[a].pb(b);
    adjList[b].pb(a);
  }
  memset(par,-1,sizeof(par));
  par[1] = 0;
  dfs(1);
  for (int i=2;i<=N;++i){
    p[i][0] = par[i];
    tmp[i] = choose2(desc[par[i]] - desc[i]);
  }
  p[1][0] = -1;
  dfs2(1);
  for (int i = 1; i < 17; i++){
      for (int j = 1; j <= N; j++){
        if (p[j][i-1] == -1) p[j][i] = -1;
        else p[j][i]=p[p[j][i-1]][i-1];
     }
   }
  // for (int i=1;i<=N;++i)cout<<i << ' ' << tmp[i] << ' ' << dist[i] << '\n';
  cin>>Q;
  for (int i=0;i<Q;++i){
    cin>>a>>b;
    int l = LCA(a,b);
    if (a == b){cout<<"0\n";continue;}
    if (l == a || l == b){
      if (depth[a] < depth[b])swap(a,b);
      b = l = fp(a, depth[a] - depth[b] -1);
      // cout << l << '\n';
      ll x = fd(a,l,l);
      // cout << x << '\n';
      // cout << desc[a] << ' ' << N-desc[b]+1 << '\n';
      // cout << a << ' ' << b << ' ' << l << '\n';
      x += choose2(desc[a]);
      x += choose2(N - desc[l]);
      cout << choose2(N)-x << '\n';
    }else{
      ll x = fd(a,b,l);
      // cout << x << '\n';
      int t = depth[a] - depth[l];
      int t2 = fp(a,t-1);
      x -= tmp[t2];
      t = depth[b] - depth[l];
      int t3 = fp(b,t-1);
      x -= tmp[t3];
      // cout << "Erasing " << t2 << ' ' << t3 << '\n';
      // cout << choose2(N) - x << ' ';
      // cout << "Choose2 " << choose2(desc[a]) << ' ' << choose2(desc[b]) << ' ' << choose2(N-desc[l]+1)<< '\n';
      x += choose2(desc[a]);
      x += choose2(desc[b]);
      // cout<<choose2(N)-x<<' ';
      // cout << "Should be 0 " << choose2(desc[l] - desc[t2] - desc[t3]) << '\n';
      x += choose2(N - desc[t2] - desc[t3]);
      cout<<choose2(N)-x<<'\n';
    } 
  }
}
