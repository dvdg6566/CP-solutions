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
#define SZ(x) (int)x.size()
#define INF 1000000000
int K;
deque<int> dq;
int res[100100];

int main(){
  // freopen("input.txt","r",stdin);
  cin>>K;
  dq.push_back(1);
  memset(res,-1,sizeof(res));
  res[1] = 0;
  while (dq.size()){
    int cur = dq[0];
    // cout << cur << '\n';
    dq.pop_front();
    // cout << (cur*10)%K << ' ' << res[(cur*10)%K] << ' ' << res[cur] << '\n';
    if (res[(cur * 10) % K] == -1 || res[(cur*10)%K] > res[cur]){
      res[(cur*10)%K] = res[cur];
      // cout << "GG " << res[(cur*10)%K] << '\n';
      dq.push_front((cur*10)%K);
    }
    if (res[(cur+1)%K] == -1){
      res[(cur+1)%K] = res[cur] + 1;
      dq.push_back((cur+1)%K);
    }
  }
  // cout << res[1] << ' ' << res[10%7] << ' ' << res[100%7] << ' ' << res[1000%7] << '\n';
  cout << res[0]+1;
}
