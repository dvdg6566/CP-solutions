#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<int,pi> pii;
typedef vector<pi> vpi;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define f first
#define s second
ll INF = 1e9;
ll MOD = 1e9;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (ll)x.size()
#define ALL(x) x.begin(),x.end()

int N, tar, a, cur, T;
vi V;
int dp[111000][2];

int sixes[] = {1, 6, 36, 216, 1296, 7776};

int nines[] = {9, 81, 729, 6561};

int main(){
  for (int i=0;i<=100000;++i)dp[i][0] = dp[i][1] = INF;
  dp[0][1] = dp[0][0] = 0;
  dp[59049][0] = dp[59049][1] = 1;
  dp[46656][0] = dp[46656][1] = 1;
  dp[93312][0] = dp[93312][1] = 2;
  for (int i=0;i<6;++i){
    for(int k=0;k<=100000;++k)dp[k][i%2] = dp[k][1-i%2];
    for (int j=1;j<6;++j){
      int v = sixes[i] * j;
      // cout<<v<<' '<<j<<'\n';
      for (int k=v; k<=100000;++k){
        dp[k][i%2] = min(dp[k][i%2], dp[k-v][1-i%2] + j);
      }
    }
  }
  for (int i=0;i<4;++i){
    for(int k=0;k<=100000;++k)dp[k][i%2] = dp[k][1-i%2];
    for (int j=1;j<9;++j){
      int v = nines[i] * j;
      // cout<<v<<' '<<j<<'\n';
      for (int k=v; k<=100000;++k){
        dp[k][i%2] = min(dp[k][i%2], dp[k-v][1-i%2] + j);
      }
    }
  }

  // for (int i=1;i<100;++i)cout<<min(dp[i][0], dp[i][1])<<' ';
  cin >> N;
  cout<<min(dp[N][0], dp[N][1]);
}
