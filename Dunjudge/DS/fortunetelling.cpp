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

ll A[600100];
struct SparseTable {
  vector<vector<ll> > ST;
  int N,K;
  SparseTable(ll _N): N(_N){
    K = MSB(N);
    ST.resize(K);
    ST[0] = vi(A,A+N);
    // for (auto i : ST[0])cout<<i<<' ';cout<<'\n';
    for (ll k=1;k<K;++k){
      for(ll i=0;i+(1<<k)<=N;++i){
        ST[k].pb(max(ST[k-1][i], ST[k-1][i+(1<<(k-1))]));
      }
    }
  }

  inline int MSB(unsigned int x){return 32-__builtin_clz(x);}

  ll query(int x, int y){
    // --x;--y;
    ll k=MSB(y-x+1) - 1;
    return max(ST[k][x], ST[k][y-(1<<k) + 1]);
  }
}*S;

map<ll,ll> M;
vpi V;
vector<pii> nem;
vi des;
ll original[200100];
ll N,Q,a,b;
vi queries;

bool cmp(pii a, pii b){
  if (a.f == b.f)return a.s.s < b.s.s;
  return a.f > b.f;
}

ll fw[600100];
void update(ll x, ll y){
  --x;
  for (;y;y-=(y&(-y)))fw[y]++;
  for (;x;x-=(x&(-x)))fw[x]--;
}

ll query(ll x){
  ll res = 0;
  for (; x <= S->N+5; x += (x&(-x)))res += fw[x];
  return res;
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  memset(A,-1,sizeof(A));
  // freopen("input.txt","r",stdin);
  cin>>N>>Q;
  queries.pb(-1);
  for (ll i=0;i<N;++i){
    cin>>a>>b;
    if (a > b){
      original[i] = 1;
      swap(a,b);
    }
    V.pb(mp(a,b));
    des.pb(a);des.pb(b);
  }
  for (ll i=1;i<=Q;++i){
    cin>>a;
    des.pb(a);
    queries.pb(a);
  }
  // for (ll i=0;i<N;++i)cout<<original[i]<<' ';cout<<'\n';
  sort(ALL(des));
  des.resize(unique(ALL(des)) - des.begin());
  for (ll i=0;i<des.size(); ++i){
    M[des[i]] = i+1; // Descretise is 1-index
  }
  for (ll i=0;i<N;++i){
    V[i].f = M[V[i].f];
    V[i].s = M[V[i].s];
  }
  for (ll i=1;i<=Q;++i){
    queries[i] = M[queries[i]];
  }
  for (ll i=1;i<=Q;++i){
    A[queries[i]] = i;
  }
  // cout<<"\n\n";
  // for (ll i=0;i<10;++i)cout<<A[i]<<' ';cout<<'\n';
  // for (auto i : des)cout<<i<<' ';cout<<'\n';
  S = new SparseTable(SZ(des));
  // cout<<S->N<<'\n';
  // for (ll i=0;i<S->N;++i)cout<<A[i]<<' ';cout<<'\n';
  for (ll i=0;i<N;++i){
    ll x = S->query(V[i].f, V[i].s-1);
    if (x == -1){
      nem.pb(mp(0, mp(i,V[i].s)));
      continue;
    }
    original[i] = 1;
    nem.pb(mp(x, mp(i, V[i].s)));
  }
  // assert(S->N<=600100);
  // for (ll i=0;i<N;++i)cout<<original[i]<<' ';cout<<'\n';
  for (ll i=1;i<=Q;++i){
    nem.pb(mp(i, mp(queries[i], -1)));
  }
  sort(ALL(nem), cmp);
  // for (auto i : nem)cout<<i.f<<' '<<i.s.f<<' '<<i.s.s<<'\n';
  for (auto i : nem){
    if (i.s.s == -1){
      // cout<<"Updating " << 1 << " to " << i.s.f << '\n';
      update(1,i.s.f);
    }else{
      ll x = query(i.s.s);
      // cout<< "Query " << i.s.s << " to be " << x << '\n';
      original[i.s.f] += x;
      original[i.s.f] = original[i.s.f] % 2;
    }
  }
  // for (ll i=0;i<N;++i)cout<<original[i]<<' ';cout<<'\n';
  ll res = 0;
  for (ll i=0;i<N;++i){
    if (original[i]){
      res += (ll)des[V[i].s-1];
      // cout<<res<<'\n';
    }
    else{
      res += (ll)des[V[i].f-1];
      // cout<<res<<'\n';
    }
  }
  cout<<res;
}
