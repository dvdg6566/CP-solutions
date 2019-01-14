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
      if (dq[0].f * xc + dq[0].s >= dq[1].f * xc + dq[1].s)dq.pop_front();
      else break;
    }
    return dq[0].f*xc+dq[0].s;
  }
}* Hull;

ll W[20010], D[20010];
ll S1[20010], S2[20010];
ll DP[20010][4];
ll N;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin >> N;
  for (int i = 1; i <=N;++i)cin>>W[i]>>D[i];
  for (int i=1;i<=N+1;++i){
    D[i] += D[i-1];
    S1[i] = S1[i-1] + W[i]*D[i-1];
    S2[i] = S2[i-1] + W[i];
  }
  /*
  for (int i=1;i<=N;++i)cout << D[i] << ' ';cout << '\n';
  for (int i=1;i<=N;++i)cout << S1[i] << ' ';cout << '\n';
  for (int i=1;i<=N;++i)cout << S2[i] << ' ';cout << '\n';
  */
  Hull = new ConvexHull();
  for (int k=1;k<=3;++k){
   Hull->dq.clear();
   Hull->insert(mp(0,0));
   for (int i=1;i<=N+1;++i){
     DP[i][k] = -S1[i-1] + D[i-1] * S2[i-1] + Hull->query(D[i-1]);
     if(k>1)Hull->insert(mp( -S2[i] ,DP[i][k-1] + S1[i] ));
     // cout << DP[i][k] << ' ';
   }
   // cout << '\n';
  }
  cout<<DP[N+1][3];
}
