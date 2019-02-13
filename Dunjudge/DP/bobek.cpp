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

ll N,T,a;
vi V;
map<ll,ll> M;
stack<ll> Q;
vpi D,D2;

int main(){
  // freopen("input.txt","r",stdin);
  cin>>N>>T;
  for (int i=0;i<N;++i){
    cin>>a;
    if (a > T)continue;
    V.pb(a);
  }
  N = SZ(V);
  sort(ALL(V));
  ll hp = (N+1)/2;
  M[0] = 1;
  for (int i=0;i<hp;++i){
    for(auto it : M){
      if (it.f + V[i] > T)continue;
      Q.push(it.f);
    }
    while(Q.size()){
      M[Q.top() + V[i]] += M[Q.top()] ;
      Q.pop();
    }
  }
  for (auto i : M)D.pb(mp(i.f,i.s));
  // for (auto i : D)cout<<i.f<<' '<<i.s<<'\n';
  M.clear();M[0]=1;
  for (int i=hp;i<N;++i){
    for(auto it : M){
      if (it.f + V[i] > T)continue;
      Q.push(it.f);
    }
    while(Q.size()){
      M[Q.top() +V[i]] += M[Q.top()];
      Q.pop();
    }
  }
  ll stop = SZ(D) - 1, curind = 0LL, t = 1, ans = 0;
  for (auto i : M)D2.pb(mp(i.f,i.s));
  reverse(ALL(D2));
  for (auto i : D2){
    // cout<<"Query " << i.f<<' '<<i.s<<'\n';
    while (curind + 1 <= stop && D[curind + 1].f + i.f <= T){
      ++curind;
      t += D[curind].s;
    }
    ans += t*i.s;
    // cout<<curind<<' '<<t<<'\n';
  }
  cout<<ans;
}