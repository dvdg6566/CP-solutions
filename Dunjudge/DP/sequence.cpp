#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef pair<ll,pi> pii;
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

struct ConvexHull{
  deque<pii> dq;
  ConvexHull(){}
  double intersect(pii a, pii b){
    return (double) (b.s.s - a.s.s)/(a.s.f-b.s.f);
  }
  void insert(pii cur){
    while (dq.size() > 1){
      if (intersect(dq[dq.size()-1],cur) <= intersect(dq[dq.size() -2],cur))dq.pop_back();
      else break;
    }
    dq.pb(cur);
  }
  pi query(ll xc){
    while (dq.size() > 1){
      if (dq[0].s.f * xc + dq[0].s.s <= dq[1].s.f * xc + dq[1].s.s)dq.pop_front();
      else break;
    }
    return mp(dq[0].s.f*xc+dq[0].s.s, dq[0].f);
  }
}* Hull;

ll pre[100100], cur[100100];
int P[100100][210];
int N,K;
ll S[100100];
stack<int> stk;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin >> N >> K;
  ++K;
  for(int i=1;i<=N;++i){cin>>S[i];S[i] += S[i-1];}
  Hull = new ConvexHull();
  for (int k = 1; k <= K; ++k){
    if(k>1)Hull->dq.clear();
    Hull->insert(mp(0,mp(0,0)));
    for (int i = 1; i <= N; ++i){
      pi c = Hull->query(S[i]);
      cur[i] = c.f + S[N] * S[i] - S[i] * S[i];
      P[i][k] = c.s;
      Hull->insert(mp(i,mp( S[i] , pre[i] -S[N] * S[i] )));
    }
    swap(pre,cur);
  }
  cout << pre[N] << '\n';
  while (K){
    N = P[N][K];
    --K;
    stk.push(N);
  }
  stk.pop();
  while(stk.size()){cout << stk.top() << ' ';stk.pop();}
  // for (int k=1;k<=K;++k){for (int i=1;i<=N;++i)cout << P[i][k] << ' '; cout << '\n';}
}
