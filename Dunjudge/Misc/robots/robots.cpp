#include "robots.h"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<int, pi> pii;
typedef set<int> si;
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

vpi V;
ll A,B,T;
vi X,Y;
map<int,int> mA, mB;

bool query(ll t){
  if ((A+B)*t < T)return 0;
  mA.clear();
  mB.clear();
  // cout<<t<<'\n';
  for (int i=0;i<A;++i){
    mA[X[i]] += t;
  }
  for (int i=0;i<B;++i){
    mB[Y[i]] += t;
  }
  // for (auto i : mA)cout<<i.f<<'\n';
  // cout<<'\n';
  for (auto i : V){
    // cout<<i.f<<' '<<i.s<<'\n';
    if (mA.size() == 0){
      if (i.s >= (--mB.end())->f)return 0;
      auto x = mB.ub(i.s);
      mB[x->f]--;
      if (mB[x->f] == 0)mB.erase(x->f);
      continue;
    }
    if (mB.size() == 0){
        if (i.f >= (--mA.end()) -> f)return 0;
        auto y = mA.ub(i.f);
       mA[y->f]--;
     if (mA[y->f] == 0)mA.erase(y->f);
     continue;
    }
    if (i.s >= (--mB.end())->f && i.f >= (--mA.end())->f){
      return 0;
    }
    if (i.s >= (--mB.end()) -> f){
      auto y = mA.ub(i.f);
      mA[y->f]--;
      if (mA[y->f] == 0)mA.erase(y->f);
      continue;
    }
    auto x = mB.ub(i.s);
    mB[x->f]--;
    if (mB[x->f] == 0)mB.erase(x->f);
  }
  return 1;
}

int putaway(int _A, int _B, int _T, int _X[], int _Y[], int _W[], int _S[]) {
  A = _A; B = _B; T = _T;
  for (int i=0;i<A;++i)X.pb(_X[i]);
  for (int i=0;i<B;++i)Y.pb(_Y[i]);
  sort(ALL(X));
  sort(ALL(Y));
  if (!A)X.pb(-1);
  if (!B)Y.pb(-1);
  for (int i=0;i<T;++i){
    V.pb(mp(_W[i], _S[i]));
    if (_W[i] >= X[A-1] && _S[i] >= Y[B-1]){
      return -1;
    }
  }
  if (!A)X.pop_back();
  if(!B)Y.pop_back();
  sort(ALL(V));
  reverse(ALL(V));
  // cout<<query(1) <<'\n';
  // cout<<query(3) <<'\n';
  // cout<<query(4)<<'\n';
  // return 0;
  ll llb = 0;
  ll upb = T;
  while (upb > llb + 1){
    ll mid = (upb + llb)/2;
    if (query(mid))upb = mid;
    else llb = mid;
  }
  if (query(llb))return llb;
  return upb;

}
