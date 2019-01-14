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

ll N,Q,a,b,c,d;
ll fw[500100];

void update(ll x, ll v) {
    for (; x<=N; x+=x&(-x)) fw[x] += v; 
}

ll sum(ll x) {
    ll res = 0;
    for(; x; x-=x&(-x)) res += fw[x];
    return res;
}

ll A[500100];
set<ll> S;
stack<ll> stk;
int main(){
  // freopen("input.txt","r",stdin);
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>N>>Q;
  for (int i=0;i<N;++i){
    cin>>A[i];
    update(i+1,A[i]);
    if(A[i]){
      S.insert(i);
    }
  }
  for (int i=0;i<Q;++i){
    cin>>a;
    if (a == 1){
      // Update
      cin >> b >> c;
      update(b+1,c - A[i]);
      if (c != 0)S.insert(b);
      else S.erase(b);
      A[i] = c;
    }
    if (a == 0){
      cin>>b>>c>>d;
      auto stop = S.ub(c);
      for (auto it  = S.lb(b); it != stop; ++it){
        int x = A[*it] / d;
        update(*it+1, x-A[*it]);
        A[*it] = x;
        if (x==0)
        stk.push(*it);
      }
      while(stk.size()){S.erase(stk.top());stk.pop();}
    }
    if (a == 2){
      cin >> b>> c;
      cout<< sum(c+1) - sum(b) <<'\n';
    }
  }
}
