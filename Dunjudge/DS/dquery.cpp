#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<int,pi> pii;
typedef vector<pi> vpi;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()

int pre[200100],A[200100], ans[200100];
map<int,int> M;
vector<pii> queries;
int N,a,b,Q;

int fw[200100];
void update(ll x, ll y) { // incluse
	x--;
	for(; y; y-=y&(-y)) fw[y] += 1;
	for(; x; x-=x&(-x)) fw[x] -= 1;
}

ll query(ll x) {
    ll res = 0;
    for (; x<=N; x+=x&(-x)) res += fw[x];
    return res;
}

bool cmp(pii a, pii b){
  if (a.s.s == b.s.s)return a.f < b.f;
  return a.s.s < b.s.s;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin>>N;
  for (int i=1;i<=N;++i)cin>>A[i];
  for (int i=1;i<=N;++i){
    pre[i] = M[A[i]];
    M[A[i]] = i;
    queries.pb(mp(-1,mp(-1,i)));
  }
  // for (int i=1;i<=N;++i)cout<<pre[i]<<' ';
  cin>>Q;
  for (int i=0;i<Q;++i){
    cin>>a>>b;
    queries.pb(mp(i,mp(a,b)));
  }
  sort(ALL(queries), cmp);
  for (auto it : queries){
    if (it.f == -1){
      // cout << "Update " << pre[it.s.s] + 1 << ' ' << it.s.s << '\n';;
      update(pre[it.s.s]+1,it.s.s);
    }
    else {
      ans[it.f] = query(it.s.f) - query(it.s.s);
      // cout << "Answer " << it.s.f << ' ' << it.s.s << ' ' << ans[it.f]<< '\n';
    }
  }
  for (int i=0;i<Q;++i)cout<<ans[i]+1<<'\n';
}
