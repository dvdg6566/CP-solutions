#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef pair<ll, pi> pii;
typedef set<ll> si;
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

vector<pi> dq;
ll ans,N,x;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin>>N;
  dq.pb(mp(-1,INF));
  for (int i=0;i<N;++i){
    cin >> x;
    if (x <= dq.back().f){
      while (x <= dq.back().f)dq.pop_back();
    }
    dq.back().s++;
    if (dq.back().s < INF)ans = max(ans, dq.back().s);
    while(SZ(dq) > 1 && dq[SZ(dq) - 1].s == dq[SZ(dq) - 2].s ){
      dq.pop_back();
    }
    dq.pb(mp(x,0));
  }
  cout<<ans;
}

