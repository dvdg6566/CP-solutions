#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef double dl;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MOD 1e9+7
#define lb lower_bound
#define ub upper_bound
#define INF 1000000000

string a;
int N;
int dp[3000100];
int cur[10];

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  memset(cur,-1,sizeof(cur));
  // freopen("input.txt","r",stdin);
  cin >> N;
  for (int i = 0; i < N; ++i){
    dp[i] = 1;
    cin >> a;
    for (auto it : a){
      int x = it - '0';
      if(cur[x] == -1)cur[x] = i;
      if (cur[x] == i)continue;
      dp[i] = max(dp[i], dp[cur[x]] + 1);
      cur[x] = i;
    }
  }
  cout << N - *max_element(dp,dp+N);
}
