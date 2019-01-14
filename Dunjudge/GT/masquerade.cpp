#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int>pi;
typedef pair<int,pi> pii;
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
#define SZ(x) x.size()
#define ALL(x) x.begin(),x.end()

vi adjList[100100];
vpi aList[100100];
int N,E,a,b,cnt;
int dst[100100],root[100100];

int ind[100100], currstack[100100], lowlink[100100];
set<int> S;
stack<pi> edgeList;

int gcd(int a, int b){
  if(b==0)return a;
  return gcd(b, a%b);
}

void dfs(int x){
  // cout <<x  << ' '<< root[x]<<'\n';
	if(ind[x] != -1)return;
	ind[x] = a;
	a++;
	for (auto it : adjList[x]){
    if (root[it] == root[x]){
      if (abs(dst[x] - dst[it] + 1) == 0)continue;
      if (abs(dst[x] - dst[it] + 1) <= 2){
        cout << "-1 -1";
        exit(0);
      }
      S.insert(abs(dst[x] - dst[it] + 1)); 
		}
    else{
      if (ind[it] != -1)continue;
      dst[it] = dst[x] + 1;
      root[it] = root[x];
      cnt=max(cnt, dst[it]+1);
      dfs(it);
    }
	}
}
int llb,upb;
void dfs2(int x){
  for (auto i : aList[x]){
    if (dst[i.f] != -INF)continue;
    dst[i.f] = dst[x] + i.s;
    llb = min(llb, dst[i.f]); 
    upb = max(upb, dst[i.f]);
    dfs2(i.f);
  } 
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin >> N >> E;
  for (int i=0;i<E;++i){
    cin>>a>>b;
    adjList[a].pb(b);
  }
  memset(dst,-1,sizeof(dst));
  memset(ind,-1,sizeof(ind));
  a = 0;
  for (int i=1;i<=N;++i){
    if (dst[i] == -1){
      dst[i] = 0;
      root[i] = i;
      dfs(i);
    }
  }
  if (S.size() == 0){
    for (int i = 1;i<=N;++i){
        for (auto j : adjList[i]){
          aList[i].pb(mp(j,1));
          aList[j].pb(mp(i,-1));
        }
      } 
      for (int i=1;i<=N;++i)dst[i] = -INF;
      int t=0,l=0;
      for (int i=1;i<=N;++i){
        if (dst[i] == -INF){
          dst[i] = 0;
          dfs2(i);
          t += (upb - llb + 1);
          l = max(l, upb-llb+1);
          llb = upb = 0;
        }
      }
      if (t < 3){
          cout << "-1 -1";
          return 0;
      }
      cout<<t<<' '<<3;
      return 0;
  }
  int ans = -1;
  for (auto i : S){
    // cout<<i<<' ';
    if (ans == -1){ans = i;continue;}
    ans = gcd(max(ans,i), min(ans,i));
  }
  if (ans < 3){
    cout << "-1 -1";
    return 0;
  }
  for (int i=3; i <= ans;++i){
    if (ans % i == 0){
      cout << ans<<' '<<i;
      return 0;
    }
  }
  cout << ans << ' ' << ans;
}
