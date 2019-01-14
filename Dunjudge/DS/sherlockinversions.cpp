#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll>pi;
typedef pair<ll,pi> pii;
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

ll N,Q,A[100100];
ll BLOCK_SIZE;
set<ll> des;
map<ll,ll> M;
vector<pii> V;
ll a,b;
ll fw[100100];

bool cmp(pii a, pii b){
  if (a.s.f / BLOCK_SIZE == b.s.f / BLOCK_SIZE)return a.s.s < b.s.s;
  return a.s.f / BLOCK_SIZE < b.s.f / BLOCK_SIZE;
}

void update(ll x, ll v) {
    for (; x<=N; x+=x&(-x)) fw[x] += v; 
}

ll sum(ll x) {
    ll res = 0;
    for(; x; x-=x&(-x)) res += fw[x];
    return res;
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin>>N>>Q;
  BLOCK_SIZE = sqrt(N);
  for (int i=0;i<N;++i){
    cin>>A[i];
    des.insert(A[i]);
  }
  int ind = 1;
  for (auto i : des){
    M[i] = ind;++ind;
  }
  for (int i=0;i<N;++i)A[i] = M[A[i]];
  for (int i=0;i<Q;++i){
    cin>>a>>b;
    --a;--b;
    V.pb(mp(i,mp(a,b)));
  }
  sort(V.begin(),V.end(), cmp);
  ll res[100100];
  ll l = 0, r = -1, ans = 0;
  for (auto i : V){
    // cout<<i.s.f<<' '<<i.s.s<<'\n';
    while (r < i.s.s){
      // cout << "A " << l << ' ' <<r <<' '<<ans << '\n';
      ++r;
      ans += sum(N) - sum(A[r]);
      update(A[r], 1);
    }
    while (r > i.s.s){
      // cout << "B " << l << ' ' <<r <<' '<<ans << '\n';
      ans -= sum(N) - sum(A[r]);
      update(A[r], -1);
      --r;
    }
    while (l > i.s.f){
      // cout << "C " << l << ' ' <<r  <<' '<<ans<< '\n';
      --l;
      ans += sum(A[l]-1); 
      update(A[l], 1);
    }
    while (l < i.s.f){
      // cout << "D " << l << ' ' <<r  <<' '<<ans<< '\n';
       ans -= sum(A[l]-1);
       update(A[l], -1);
       ++l;
    }
    res[i.f] = ans;
  }
  for (int i=0;i<Q;++i)cout<<res[i] <<'\n';
}
