#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define f first
#define s second
ll MOD = 998244353;
ll INF = 1e15;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (ll)x.size()
#define ALL(x) x.begin(),x.end()

ll mod(ll a, ll m){
  return (a+m)%m;
}

ll inverse(ll a, ll m){
  a = mod(a, m);
  if (a <= 1)return a;
  return mod((1 - inverse(m, a) * m) / a,m);
}

ll N,K,tmp,l;
ll memo[2020][2020][2];
stack<ll> st;

ll ask(ll a, ll b, ll c){
  // cout<<"Ask " << a << ' ' << b << '\n';
  if (memo[a][b][c] != -1)return memo[a][b][c];
  return memo[a][b][c] = (MOD + 2*ask(a-1,b-1,c) - ask(a-2,b-1,c)) % MOD;
}

int main(){
  // freopen("input.txt","r",stdin);
  cin>>K>>N;
  memset(memo,-1,sizeof(memo));
  tmp = 1;
  memo[0][0][0] = 0;
  memo[1][0][0] = 1;
  for (int i=2;i<=K;++i){
    tmp = (tmp * (i+N-1)) % MOD;
    tmp = (tmp * inverse(i-1, MOD)) % MOD;
    memo[i][0][0] = tmp;
    // cout<<i<<' '<<tmp<<'\n';
  }
  tmp = 1;
  memo[0][0][1] = 0;
  memo[1][0][1] = 1;
  for (int i=2;i<=K;++i){
    tmp = (tmp * (i+N-2)) % MOD;
    tmp = (tmp * inverse(i-1, MOD)) % MOD;
    memo[i][0][1] = tmp;
    // cout<<i<<' '<<tmp<<'\n';
  }

  for (int i=2;i<=K+1;++i){
    if (i % 2 == 0){
      l = ask(K-1,(i-1)/2,0) + ask(K-1,(i-1)/2,1);
      l %= MOD;
    }
    else l = ask(K,i/2,0);
    cout<<l<<'\n';
    st.push(l);
  }
  st.pop();
  while(SZ(st)){cout<<st.top()<<'\n';st.pop();}
}
