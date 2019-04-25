#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<int,pi> pii;
typedef vector<pi> vpi;
typedef set<int> si;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define f first
#define s second
int INF = 1e9;
int MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()

int N,L,a,b;
pi start, stop;
vpi floors[510];
vi dp[510];

int find_dist(pi a, pi b){
  int hori = abs(b.f - a.f);
  int vert = abs(b.s - a.s);
  if (L == 2)return hori + vert;
  int T = INF;
  // Case one go direct
  int p = 0;
  p += hori%L + vert%L;
  if (hori%L && vert/L == 0)p+=2;
  if (vert%L && hori/L == 0)p+=2;
  T = min(T, p);

  // Case 2 go through top corner
  p = 4 + (2*L - hori%L - vert%L);
  
  T = min(T, p);

  // Case 3 go from btm right
  p = 2 + L - hori%L + vert%L;
  if (hori%L && vert/L == 0)p += 2;
  T = min(T, p);

  // Case 4 go from top left
  p = 2 + L - vert%L + hori%L;
  if (vert%L && hori/L == 0)p += 2;
  T = min(T,p);

  return T + ((hori/L)+vert/L)*2;
}

int r;
int main(){
  // freopen("in.txt","r",stdin);
  cin >> N >> L;
  ++L; 
  // cout<<find_dist(mp(0,0), mp(5,3))<<'\n';
  // return 0;
  // for (int i=0;i<=4;++i){
  //   for(int j=0;j<=4;++j)cout<<find_dist(mp(0,0), mp(i,j))<<' ';
  //   cout<<'\n';
  // }
  // return 0;
  cin >> start.f >> start.s >> stop.f >> stop.s;
  floors[0].pb(start);
  for (int i=1;i<N;++i){
    cin >> r;
    while(r--){
      cin >> a >> b;
      floors[i].pb(mp(a,b));
    }
  }
  floors[N].pb(stop);
  for (int i=0;i<=N;++i)dp[i].resize(SZ(floors[i]), -1);
  dp[0][0] = 0;
  for (int i=1;i<=N;++i){
    for (int j = 0; j < SZ(floors[i]); ++j){
      dp[i][j] = INF;
      for (int k=0;k<SZ(floors[i-1]); ++k){
        if (dp[i-1][k] == -1)continue;
        int d = dp[i-1][k] + find_dist(floors[i][j], floors[i-1][k]);
        dp[i][j] = min(dp[i][j], d);
      }
    }
  }
  // for (int i=1;i<=N;++i){
    // for (auto t : dp[i])cout<<t<<' ';cout<<'\n';
  // }
  cout<<dp[N][0];
}
