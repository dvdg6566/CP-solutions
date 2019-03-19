#include "xylophone.h"
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
ll MOD = 1e9;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (ll)x.size()
#define ALL(x) x.begin(),x.end()

bool options[5010];
int ans[5010];
int mem[5010];

int qwrap(int x, int y){
  if (y - x != 1)return query(x,y);
  if (mem[x] == 0)return mem[x] = query(x,y);
  return mem[x];
}

void solve(int N) {

	int value = query(1, N);
  int l=1, u=N;
  while(u-l>1){
    int m=(l+u)/2;
    if (query(1,m) == N-1)u=m;
    else l = m;
  }
  if (query(1,l) == N-1)u = l;
  int p = qwrap(u-1, u);
  ans[u] = N;
  ans[u-1] = N - p;
  options[N] = options[N-p] = 1;
  if (u != N){
    p = qwrap(u,u+1);
    ans[u+1] = N - p;
    options[N-p] = 1;
  }

  for (int i=u-2; i >= 1; --i){
    int a = qwrap(i, i+1);
    int b = ans[i+1] - a;
    int t = ans[i+1] + a;
    if (b <= 0 || options[b] == 1){
      ans[i] = t;
    }
    else if (t > N || options[t] == 1){
      ans[i] = b;
    }
    else{
      int l = qwrap(i, i+2);
      if (l == a){
        if (ans[i+2] > ans[i+1])ans[i] = t;
        else ans[i] = b;
      }
      else{
        if (ans[i+2] > ans[i+1]){
          if (qwrap(i+1, i+2) == l){
            ans[i] = t;
          }else ans[i] = b;
        }
        else{
          if (qwrap(i+1,i+2) == l)ans[i] = b;
          else ans[i] = t;
        }
      }
    }
    options[ans[i]] = 1;
  }

  for (int i=u+2; i <= N; ++i){
    int a = query(i-1,i);
    int b = ans[i-1] - a;
    int t = ans[i-1] + a;
    if (b <= 0 || options[b] == 1){
      ans[i] = t;
    }
    else if (t > N || options[t] == 1){
      ans[i] = b;
    }
    else{
     int l = query(i-2, i);
      if (l == a){
        if (ans[i-2] > ans[i-1])ans[i] = t;
        else ans[i] = b;
      }
      else{
        if (ans[i-2] > ans[i-1]){
          if (qwrap(i-2, i-1) == l){
            ans[i] = t;
          }else ans[i] = b;
        }
        else{
          if (qwrap(i-2, i-1) == l)ans[i] = b;
          else ans[i] = t;
        }
      }
    }
    options[ans[i]] = 1;
  }

  for(int i = 1; i <= N; i++) {
		answer(i, ans[i]);
	}

}
