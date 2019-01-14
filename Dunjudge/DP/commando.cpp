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

struct ConvexHull{
  deque<pi> dq;
  ConvexHull(){}
  double intersect(pi a, pi b){
    return (double) (b.s - a.s)/(a.f-b.f);
  }
  void insert(pi cur){
    while (dq.size() > 1){
      if (intersect(dq[dq.size()-1],cur) <= intersect(dq[dq.size() -2],cur))dq.pop_back();
      else break;
    }
    dq.pb(cur);
  }
  ll query(ll xc){
    while (dq.size() > 1){
      if (dq[0].f * xc + dq[0].s <= dq[1].f * xc + dq[1].s)dq.pop_front();
      else break;
    }
    return dq[0].f*xc+dq[0].s;
  }
}* Hull;

ll N,a,b,c;
ll A[1000100];
ll DP[1000100];

int main(){
  cin >> N >> a >> b >> c;
  Hull = new ConvexHull();
  for (int i = 1; i <= N; ++i){
    cin >> A[i];
    A[i] += A[i-1];
  }
  Hull->insert(mp(0LL,0LL));
  for (int i = 1; i <= N; ++i){
    DP[i] = a * A[i] * A[i] + b * A[i] + c + Hull->query(A[i]);
    Hull->insert(mp(-2*a*A[i],DP[i]+A[i]*A[i]*a-b*A[i]));
  }
  cout << DP[N];
}