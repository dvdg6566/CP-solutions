#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef pair<ll,pi> pii;
typedef vector<pi> vpi;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MOD 1e9+7
ll INF = 1e15;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (ll)x.size()
#define ALL(x) x.begin(),x.end()

ll N,M,R;
string S;
ll memo[5][11][60000];
vi V;
map<char,int> conv;

ll DP(int a, int b, int c){
  if (memo[a][b][c] != -1)return memo[a][b][c]; 
  int x = V[N-c-1];
  if (x && x != a)return memo[a][b][c] = 0;
  if (b == 0)return memo[a][b][c] = 0;
  if (c == 0)return memo[a][b][c] = 1;
  ll ans = 0;
  for (int i=a; i <= 4; ++i){
    ans += DP(i,b,c-1);
  }
  for (int i=1;i<a;++i){
    ans += DP(i, b-1, c-1);
  }
  return memo[a][b][c] = ans;
}
vi res;
int main(){
  // freopen("input.txt","r",stdin);
  conv['A'] = 1;
  conv['C'] = 2;
  conv['G'] = 3;
  conv['T'] = 4;
  conv['N'] = 0;
  char rev[] = {'N','A','C','G','T'};
  cin>>N>>R>>M>>S;
  --M;
  memset(memo,-1,sizeof(memo));
  for (auto i : S)V.pb(conv[i]);
  int prev = 0;
  for (int i=0;i<N;++i){
   int left = N-i;
   ll tmp = 0;
   for (int j=1;j<=4;++j){
     int r = R;
     if (prev > j)r--;
     ll t = DP(j,r,left-1);
     // cout<< "Query "<< j<<' '<<r<<' '<<left-1<<"  :" <<t<<'\n';
     if (tmp <= M && tmp + t > M){
       M -= tmp;
       // cout<<"Remaining " << M << '\n';
       res.pb(j);
       R = r;
       prev = j;
       break;
     }
     tmp += t;
   }
  }
  for (auto i : res)cout<<rev[i];
}
