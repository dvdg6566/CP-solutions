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
#define dst distance
#define INF 1000000000

vpi V,V2;
ll N,a,b;
ll dp[300100];
   
struct ConvexHull{
  deque<pi> dq;
  ConvexHull(){}
  long double intersect(pi a, pi b){
    return (long double) (b.s - a.s)/(a.f-b.f);
  }
  void insert(pi cur){
    while (dq.size() > 1){
      if (intersect(dq[dq.size()-1],cur) <= intersect(dq[dq.size() -2],cur))dq.pop_back(); 
      else break;
    }
    dq.pb(cur);
  }
  ll query(ll xc){
    while (dq.size() > 1){
      if (dq[0].f * xc + dq[0].s >= dq[1].f * xc + dq[1].s)dq.pop_front();
      else break;
    }
    // cout << dq[0].f << ' ' << xc << ' ' << dq[0].s << '\n';
    return dq[0].f*xc+dq[0].s;
  }
}* Hull;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin >> N;
  for (int i = 0; i < N; ++i){cin >> a >> b;V.pb(mp(a,b));}
  sort(V.begin(),V.end());
  reverse(V.begin(),V.end());
  ll curmax = 0;
  for (auto i : V){
    if (i.s <= curmax)continue;
    curmax = i.s;
    V2.pb(i);
  }
  N = V2.size();
  // reverse(V2.begin(),V2.end());
  // for (auto i : V2)cout << i.f << ' ' << i.s << '\n';
  // cout << N << '\n';
  Hull = new ConvexHull();
  Hull->insert(mp(V[0].f,0));
  dp[0] = V2[0].f * V2[0].s;
  // cout << dp[0] << '\n';
  for (int i=1;i<N;++i){
    Hull ->insert(mp(V2[i].f, dp[i-1]));
    // cout << "Insert " << V2[i].f << ' ' << dp[i-1] << '\n';
    dp[i] = Hull -> query(V2[i].s);
  }
  // for (int i=0;i<N;++i)cout<<dp[i]<<' ';cout<<'\n';
  cout << dp[N-1];
}
