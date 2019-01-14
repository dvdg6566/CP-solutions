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
#define SZ(x) (int)x.size()
#define INF 1000000000

int fw[300100];
vpi des;
int N,a,K;
bool chk = 0;
bool cmp(pi a, pi b){
  return a.s<b.s;
}

void update(ll x, ll v) {
    for (; x<=N; x+=x&(-x)) fw[x] += v; 
}

ll sum(ll x) {
    ll res = 0;
    for(; x; x-=x&(-x)) res += fw[x];
    return res;
}
ll ans,ways;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin >> N >> K;
  for (int i=0;i<N;++i){
    cin>>a;
    des.pb(mp(i,a));
  }
  sort(des.begin(),des.end(),cmp);
  int cnt = 1,p = des[0].s;

  des[0].s = 1;
  for (int i=1;i<N;++i){
    if(des[i].s == p){
      des[i].s = cnt;
    }else{
      p = des[i].s;
      ++cnt;
      des[i].s = cnt;
    }
  }
  // for(auto i:des)cout<<i.s<<' ';cout<<'\n';
  sort(des.begin(),des.end());
  // for(auto i:des)cout<<i.s<<' ';cout<<'\n';
  int right=-1;
  for(int left=0;left<N-1;++left){
    while(ways < K && right < N-1){
      ++right;
      update(des[right].s,1);
      if(chk)cout << "Incrementing fenwick index " << des[right].s << '\n';
      int add = sum(des[right].s-1);
      ways += add;
      if(chk)cout << "Increasing ways by " << add<< " to " << ways << '\n';
    }
    if (ways < K)break;
    ans += (N-right); 
    if(chk)cout << "Incrementing answer by " << N-right<< '\n';
    update(des[left].s,-1);
    if(chk)cout << "Decementing fenwick index " << des[left].s << '\n';
    int t = sum(N) - sum(des[left].s);
    ways -= t;
    if(chk)cout << "Decreasing ways by " << t << " to " << ways << '\n';
  }
  cout << ans;
}
