#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<int,pi> pii;
typedef vector<pi> vpi;
typedef set<int> si;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define f first
#define s second
ll INF = 1e15;
ll MOD = 1e9;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()

ll ans,N,a,b;
vpi V;
bool D[2010][2010];

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin>>N;
  for (int i=0;i<N;++i){
    cin>>a>>b;
    a += 1000; b += 1000;
    V.pb(mp(a,b));
    D[a][b] = 1;
  }
  for (auto i : V){
    for (auto j : V){
      if (i.f == j.f || i.s == j.s)continue;
      if (D[i.f][j.s] && D[j.f][i.s]){
       ++ans; 
       // cout<<i.f<<' '<<i.s<<' '<<j.f<<' '<<j.s<<'\n';
      }
    }
  }
  cout<<ans/4;
}
