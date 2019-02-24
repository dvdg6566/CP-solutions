#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
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

int N,M,Q,a,b,d;
vector<pi> V;


int main(){
  // freopen("input.txt","r",stdin);
  cin>>N>>M>>Q;
  for (int i=0;i<Q;++i){
    cin>>a>>b;
    d = (a-b);
    if (d < 0)continue;
    V.pb(mp(a, -d));
  }
  d = 0;a= M+1;
  sort(ALL(V));
  for (auto i : V){
    if (-i.s > d){
      a = min(a, i.f);
      // cout<<i.f<<' '<<i.s<<'\n';
    }
    d = max(d, -i.s+1);
    // cout<<"Change to " << i.f+1<<'\n';
  }
  cout<<a-1;
}
