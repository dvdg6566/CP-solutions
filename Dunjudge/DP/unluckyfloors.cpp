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
#define MOD 1e9+7
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()

int T,a;
ll b;
string S;
ll DP[20][11];


ll query(int a, int b){
  if (DP[a][b] != -1)return DP[a][b];
  if (a == 0)return DP[a][b] = 1;
  ll res = 0;
  for (int i=1;i<=9;++i){
    if (i == 4)continue;
    if (i == 3 && b == 1)continue;
    res += query(a-1, i);
 }
  if (b == 10){
    res += query(a-1, 10);
  }
  else res += query(a-1, 0);
  return DP[a][b] = res;
}

ll ind (string x){
  ll T = SZ(x);
  for (auto i : x)if (i == '4')return -1;
  for (int i=0;i<T-1;++i)if (x[i] == '1' && x[i+1] == '3')return -1;
  ll res = 0;
  for (int i=0;i<T;++i){
    for (int j=1;j<S[i] - '0';++j){
      if (j == 4)continue;
      if (j == 3 && i && x[i-1] == '1')continue;
      res += query(T-1-i, j);
    }
    if (S[i] != '0' && i == 0)res += query(T-1-i, 10);
    if (S[i] != '0' && i)res += query(T-i-1, 0);
  }
  // for (int i=1;i<S[0]-'0'; ++i)if (i != 4) res += query(T-1, i, 0); 
  return res;
}

ll ord (ll x){
  ll cur = 0;
  for (int len = 19; len >= 0; -- len){
    ll tmp = 0;
    for (int j=0;j<=9;++j){
      if (j == 4)continue;
      if (cur % 10 == 1 && j == 3)continue;
      ll t = query(len, j);
      if (tmp <= x && tmp + t > x){
        x -= tmp;
        cur *= 10;
        cur += j;
        break;
      }
      tmp += t;
    }
  }
  return cur;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin>>T;
  for (int i=0;i<T;++i){
    cin>>a;
    if (a == 1){
      cin>>S;
      memset(DP,-1,sizeof(DP));
      cout<<ind(S)<<'\n';
      continue;
    }
    else {
      memset(DP,-1,sizeof(DP));
      cin>>b;
      cout<<ord(b)<<'\n';
    }
  }
}
