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
bool debug = 1;
queue<pi> Q,R;
int H,W,K,a,b;
int G[1000][1000],P[1000][1000];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
string S;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  if(debug)freopen("input.txt","r",stdin);
  cin>>H>>W>>K;
  for (int i=0;i<H;++i){
    cin>>S;
    // cout << S << '\n';
    for(int j=0;j<W;++j){
      if(S[j] == 'S'){
        Q.push(mp(i,j));
        R.push(mp(i,j));
        continue;
      }
      if (S[j]=='#')G[i][j] = P[i][j] = -2;
      else G[i][j] = P[i][j] = -1;
    }
  }
  // First we DFS to the K nearest neighbours
  while(Q.size()){
    pi cur = Q.front();
    if (P[cur.f][cur.s] == K)break;
    Q.pop();
    for (int k=0;k<4;++k){
      int cx = cur.f+dx[k];
      int cy = cur.s+dy[k];
      if (cx < 0 || cy < 0 || cx > H || cy > W){
        cout << 1;
        return 0;
      }
      if (P[cx][cy] != -1)continue;
      P[cx][cy] = P[cur.f][cur.s] + 1;
      G[cx][cy] = 0;
      Q.push(mp(cx,cy));
      R.push(mp(cx,cy));
      // cout << cx << ' ' << cy << '\n';
    }
  }
  while(R.size()){
    // cout << R.front().f << ' ' << R.front().s << '\n';
    pi cur = R.front();
    R.pop();
    for (int k=0;k<4;++k){
      int cx = cur.f+dx[k];
      int cy = cur.s+dy[k];
      if (cx < 0 || cy < 0 || cx >=H || cy >=W){
        // cout << cx << ' ' << cy << '\n';
        if(debug)cout << G[cur.f][cur.s] << '\n';
        cout << (G[cur.f][cur.s] + K - 1)/K + 1;
        return 0;
      }
      if (G[cx][cy] != -1 && G[cx][cy] != -2)continue;
      if (P[cx][cy] >= 0)continue;
      G[cx][cy] = G[cur.f][cur.s] + 1;
      R.push(mp(cx,cy));
    }
  }
  for (int i=0;i<H;++i){
    for (int j=0;j<W;++j)cout<<G[i][j] << ' ';cout<<'\n';
  }
}
