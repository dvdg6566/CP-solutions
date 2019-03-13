#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef pair<ll,pi> pii;
typedef vector<pi> vpi;
typedef set<ll> si;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define f first
#define s second
ll INF = 1e18;
ll MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (ll)x.size()
#define ALL(x) x.begin(),x.end()
vi V;
vpi A;
ll N,a,b;
char res[40];

int main(){
  cin >> N;
  for (int i=0;i<N;++i){
    cin>>a>>b;
    A.pb(mp(a,b));
  }
  int p = abs(A[0].f + A[0].s)%2;
  for (auto i : A){
    if (abs(i.f + i.s)%2 != p){
      cout<<-1;
      return 0;
    }
  }
  if (!p)V.pb(1);
  V.pb(1);
  for (int i=1;i<=30;++i)V.pb((1LL)<<i);
  cout<<SZ(V)<<'\n';
  for (auto i : V)cout<<i<<' ';cout<<'\n';
  for (auto it : A){
    for (int i=0;i<SZ(V);++i)res[i] = 'X';
    ll a = it.f, b = it.s;
    for (int i=30; i >= 0; --i){
      if (abs(a) > abs(b)){
        if (abs(a) >= (1<<i)){
          if (a > 0){
            res[i+1] = 'R';
            a -= (1<<i);
          }else {
            res[i+1] = 'L';
            a += (1<<i);
          }
        }else{
          if (a > 0){
            res[i+1] = 'R';
            a  = a - (1<<i);
          }else{
            res[i+1] = 'L';
            a = a + (1<<i);
          }
        }
      }else{
        if (abs(b) >= (1<<i)){
          if (b > 0){
            res[i+1] = 'U';
            b -= (1<<i);
          }else {
            res[i+1] = 'D';
            b += (1<<i);
          }
        }else{
          if (b > 0){
            res[i+1] = 'U';
            b  = b - (1<<i);
          }else{
            res[i+1] = 'D';
            b = b + (1<<i);
          }
        }
      }
    }
    if(!p){
      int u = 0, r = 0;
      for (int i=0;i<31;++i){
        if (res[i+1] == 'L')r -= (1<<i);
        if (res[i+1]=='R')r+=(1<<i);
        if (res[i+1] == 'U')u += (1<<i);
        if (res[i+1] == 'D')u -= (1<<i);
      }
      //cout<<r<<' '<<u<<'\n';
      if (r + 1 == it.f)cout<<'R';
      else if (r - 1 == it.f)cout<<'L';
      else if (u + 1 == it.s)cout<<'U';
      else cout<<'D';
    }
    for (int i=1;i<=31;++i)cout<<res[i];cout<<'\n';
  }
}