#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef pair<ll,pi> pii;
typedef vector<pi> vpi;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MOD 1e9+7
ll INF = 1e15;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (ll)x.size()
#define ALL(x) x.begin(),x.end()

int p[10011][1100];
int ans[300100];
int N,M,K,a,b,c,d;
vector<pair<pi,pi>> V;

int par(int l, int x){return (p[l][x] == x ? x : p[l][x] = par(l,p[l][x]));}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin>>N>>M>>K;
  for (int i=0;i<M;++i){
    cin>>a>>b>>c;
    V.pb(mp(mp(c,i), mp(a,b)));
  }
  sort(ALL(V));
  reverse(ALL(V));
  for (int i=0;i<=K+1;++i)for (int j=0;j<=N;++j)p[i][j] = j;
  for (auto it : V){
    int lower  = 1;
    int upper = K+1;
    while(upper - lower > 1){
      int mid = (upper + lower) / 2;
      // cout<<"Query parents " << mid<<' '<<it.s.f << ' '<<it.s.s << ' ' <<  par(mid, it.s.f) <<' '<<  par(mid, it.s.s) <<'\n';
      if(! (par(mid, it.s.f) == par(mid, it.s.s)) )upper = mid;
      else lower = mid;
    }
    if (par(lower,it.s.f) == par(lower, it.s.s))lower++;
    if (lower == K+1)continue;
    ans[it.f.s] = lower;
    // cout<<"Answer " << it.f.s<<'\n';
    p[lower][par(lower, it.s.f)] = par(lower, it.s.s);
    // cout<<"Merge " << it.s.f << ' ' << it.s.s << " at " << lower <<'\n';
    // for (auto it : p[lower])cout<<it.f<<' '<<it.s<<'\n';
  }
  for (int i=0;i<M;++i){
    cout<<ans[i]<<'\n';
  }
}
