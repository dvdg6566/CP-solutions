#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<int,pi> pii;
typedef vector<pi> vpi;
typedef double dl;
#define mp make_pair
#define pb push_back
#define f first
#define s second
int MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
ll INF = 100000000000000000;
#define SZ(x) x.size()
#define Aint(x) x.begin(),x.end()
const int MAXN = 1001000;

ll DP[20][11][11][2];
string a,b,S;
ll t;

ll query(int a, int b, int c, int d){
  if (DP[a][b][c][d] != -1)return DP[a][b][c][d];
  if (a == 0)return DP[a][b][c][d] = 1;
  ll res = 0;
  if (d == 1){
    int x = S[SZ(S) - a] - '0';
    for (int i=0;i<x;++i){
      if (i == b || i == c)continue;
      res += query(a-1, c, i, 0);
    }
    if (b != x && c != x)res += query(a-1, c, x, 1);
    return res;
  }
  for (int i=1;i<=9;++i){
    if (i==b||i==c)continue;
    res += query(a-1, c, i, 0);
    // if (a == 3)cout<<query(a-1,c,i,0)<<'\n';
  }
  if ((b!=0) && (c!=0)){
    if (c == 10){
      // assert(b==10);
      res += query(a-1, 10, 10, 0);
    }
    else res += query(a-1, c, 0, 0);
  }
  // if (a == 3)cout<<query(a-1, c, 0, 0)<<'\n';

  return DP[a][b][c][d] = res;
}

ll out (string x){
  if (x == "-1")return 0;
  S = x;
  
  ll T = SZ(S);
  ll res = 0;
  for (int i=1;i<S[0]-'0'; ++i){
    res += query(T-1, 10, i, 0);
  }
  if (S[0] != '0')res += query(T-1, 10, 10, 0);
  // cout<<res<<'\n';
  res += query(T-1, 10, S[0] - '0', 1);
  return res;
}

int main(){
  // freopen("input.txt","r",stdin);
  memset(DP,-1,sizeof(DP));
  cin>>t>>b;
  ll x = out(to_string(t-1));
  memset(DP,-1,sizeof(DP));
  ll y = out(b);
  // cout<<y<<' '<<x<<'\n';
  cout<<y-x;
  // cin>>a>>b;
  // cout<< out(b) - out(a-1);
  
  // cout<<query(2,10,10)<<'\n';
  // for (int i=0;i<3;++i){
    // for (int j=0;j<=9;++j){
      // for (int k=0;k<=9;++k)cout<<DP[i][j][k][0]<<' ';
      // cout<<'\n';
    // }
    // cout<<"\n\n";
  // }
}