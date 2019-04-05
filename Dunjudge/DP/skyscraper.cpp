#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
#define f first
#define s second

int MOD = 1e9+7;
int INF = 1e9;
int N,M,a,b,start,stop;
vi doge[30010];
int dp[30010][200];
queue<pi> pq[200];
int curind = 0, curwgt = 0;
int done[30010];

void init(int x, int w){
  // cout<<"Initialise " << x <<'\n';
  for (auto i : doge[x]){
    if (i <= 170){
      if (dp[x][i] != INF)continue;
      dp[x][i] = w+1;
      pq[curind].push(mp(x,i));
      // cout<<"Pushing A " << x << ' ' <<i <<" onto " << curind<< '\n';
    }else{
      int tmpcur = curind;
      for (int j=0;j<100000;++j){
        int curx = x + i * j;
        if (curx >= N)break;
        dp[curx][0] = min(dp[curx][0], w + j);
        pq[tmpcur].push(mp(curx, 0));
        // cout<<"Pushing B " << curx << ' ' << 0 <<" onto " << tmpcur << '\n';
        tmpcur++;
        if (tmpcur > 180)tmpcur -= 180;
      }
      tmpcur = curind;
      for (int j=0;j<100000;++j){
        int curx = x - i * j;
        if (curx < 0)break;
        dp[curx][0] = min(dp[curx][0], w + j);
        pq[tmpcur].push(mp(curx, 0));
        // cout<<"Pushing C " << curx << ' ' << 0 <<" onto " << tmpcur << '\n';
        tmpcur++;
        if (tmpcur > 180)tmpcur -= 180;
      }
    }
  }
}

int bfs(){
  while (1){
    ++curind; ++curwgt;
    if (curind > 180)curind -= 180;
    if (!SZ(pq[curind]))return 0;
    while (SZ(pq[curind])){
      int t = pq[curind].front().f;
      if (t == stop)return curwgt;
      int d = pq[curind].front().s;
      pq[curind].pop();
      if (!done[t]){
        init(t, curwgt);
        done[t] = 1;
      }
      int nxt = curind + 1;
      if (nxt > 180) nxt-=180;
      if (d != 0){
        int l = t - d;
        if (l >= 0 && dp[l][d] == INF){
          pq[nxt].push(mp(l, d));
          dp[l][d] = curwgt + 1;
          // cout<<"Pushing D " << l << ' ' <<d <<" onto " << nxt << '\n';
        }
        l = t + d;
        if (l < N && dp[l][d] == INF){
          dp[l][d] = curwgt + 1;
          pq[nxt].push(mp(l,d));
          // cout<<"Pushing E " << l << ' ' <<d <<" onto " << nxt << '\n';
        }
      }
    }
  }
}
int main(){
  // freopen("in.txt","r",stdin);
  cin >> N>> M;
  for (int i=0;i<M;++i){
    cin >> a >> b;
    if (i == 1)stop = a;
    if (i == 0)start = a;
    doge[a].pb(b);
  }
  for (int i=0;i<N;++i)for (int j=0;j<200;++j)dp[i][j] = INF;
  pq[1].push(mp(start, 0));
  cout<<bfs()-1;
}
