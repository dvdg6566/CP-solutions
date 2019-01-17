#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end

vector<vi> V;
int N,M,T,req;
string s;
queue<pi> q,tq;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin>>T;
  for (int tc=0;tc<T;++tc){
    cin>>N>>M;
    short V[N][M];
    bool visited[N][M];
    memset(visited,0,sizeof(visited));
    for (int i=0;i<N;++i){
      cin>>s;
      for (int j=0;j<M;++j)V[i][j] = s[j] - 'a';
    }
    req = (N-1) * (M-1);
    for (int i=0;i<N-1;++i){
      for (int j=0;j<M-1;++j){
        if (V[i][j] != V[i+1][j])continue;
        if (V[i][j] != V[i][j+1])continue;
        if (V[i][j] != V[i+1][j+1])continue;
        req--;
      }
    }
    for (int i=1;i<M;++i){
      // cout << 1 << ' ' << i << '\n';
      // cout << M-1 << ' ' << i << '\n';
      if (V[0][i] != V[0][i-1])tq.push(mp(1,i));
      if (V[N-1][i] != V[N-1][i-1])tq.push(mp(N-1,i));
    }
    for (int i=1;i<N;++i){
      // cout << i << ' ' << 1 << '\n';
      // cout << i << ' ' << N-1 << '\n';
      if (V[i][0] != V[i-1][0])tq.push(mp(i,1));
      if (V[i][M-1] != V[i-1][M-1])tq.push(mp(i,M-1));
    }
    while(tq.size()){
      pi c = tq.front();
      tq.pop();
      if (c.f >= N || c.s >= M)continue;
      if (visited[c.f][c.s])continue;
      visited[c.f][c.s] = 1;
      q.push(c);
    }
    int cnt = 0;
    while(q.size()){
      int x = q.front().f;
      int y = q.front().s;
      ++cnt;
      // cout << "Visiting " << x << ' ' << y << '\n';
      q.pop();
      for (int k=0;k<4;++k){
        int cx = x+dx[k];
        int cy = y+dy[k];
        if (cx<=0||cy<=0||cx>=N||cy>=M)continue;
        if (visited[cx][cy])continue;
        int a = min(y,cy);
        int b = min(x,cx);
        // cout << "Check " << cx << ' ' << cy << '\n';
        if (y != cy && V[x-1][a] == V[x][a])continue;
        if (x != cx && V[b][y-1] == V[b][y])continue;
        // cout << x << ' ' << y << " leads to " << cx << ' ' << cy << '\n';
        visited[cx][cy] = 1;
        q.push(mp(cx,cy));
      }
    }
    // cout << req <<' ' << cnt<< '\n';
    if (req <= cnt)cout << "YES\n";
    else cout << "NO\n";
  }
}
