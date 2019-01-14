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
#define MOD 1000000007LL
#define lb lower_bound
#define ub upper_bound
#define dst distance
#define ALL(X) (X).begin(), (X).end()
#define INF 1000000000

int N,P,Q,a;
vi A;
pi p[2010];
int memo[2010][2010];

bool query(int w){
  memset(memo,0,sizeof(memo));
  for (int i=1;i<N;++i){
    p[i].f = ub(ALL(A), A[i] - w)-A.begin()-1;
    p[i].s = ub(ALL(A), A[i] - w*2)-A.begin()-1;
  }
  // for (int i=0;i<N;++i)cout<<p[i].f<<' '<<p[i].s<<'\n';
  memo[0][0] = 1;
  for (int i=1;i<N;++i){
    for (int j=0;j<=P;++j){
      memo[i][j] = INF;
      if (j>0)memo[i][j] = min(memo[i][j],memo[p[i].f][j-1]);
      memo[i][j] = min( memo[i][j], memo[p[i].s][j] + 1 );
    }
  }
  return (memo[N-1][P] <= Q);
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin>>N>>P>>Q;
  if (P+Q>=N){
    cout<<1;
    return 0;
  }
  for (int i=0;i<N;++i){cin>>a;A.pb(a);}
  sort(ALL(A));
  int llb = 0;
  int upb = A[N-1];
  // cout<<query(4);
  // return 0;
  while(upb > llb + 1){
    cout<<upb<<' '<<llb<<'\n';
    int mid = (llb+upb)/2;
    if(query(mid))upb = mid;
    else llb = mid;
  }
  if (query(llb))cout<<llb;
  else cout << upb;
}
