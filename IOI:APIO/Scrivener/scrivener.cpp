#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<int, pi> pii;
typedef set<int> si;
typedef vector<pi> vpi;
typedef double dl;
#define mp make_pair
#define pb push_back
#define f first
#define s second
ll MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
#define INF 1000000000
#define ALL(x) x.begin(),x.end()

char C[1000100];
int p[1000100][20];
int depth[1000100], ind[1000100]; // Index array is the index in the tree after operation i
int N,cur,cmd;

int fp(int c, int d){
  for (int i = 0; i < 20; i++) {
    if (((1 << i) & d) > 0) {
      if (c==-1) return -1;
      c = p[c][i];
    }
  }
  return c;
}

void Init() {
  memset(p,-1,sizeof(p));
  memset(depth,-1,sizeof(depth));
  memset(ind,-1,sizeof(ind));
  N = cmd = 1;
  depth[0] = 0;
  ind[0] = 0;
}

void TypeLetter(char L) {
  C[N] = L;
  p[N][0] = ind[cmd - 1];
  // cout<< "Edge from " << N << " to " << ind[cmd-1] << '\n';
  depth[N] = depth[ind[cmd - 1]] + 1;
  ind[cmd] = N;
  for (int i=0;i<20;++i){
    if (depth[N] < (1<<i))continue;
    if (p[N][i-1] == -1)continue;
    p[N][i] = p[p[N][i-1]][i-1];
    // cout<< "Parent " << i << " of " << N << " is " << p[N][i]<<'\n';
  }
  ++N;
//   cout<<cmd<<' '<<ind[cmd]<<'\n';
  ++cmd;
}

void UndoCommands(int U) {
  ind[cmd] = ind [cmd-U-1];
//   cout<<cmd<<' '<<ind[cmd] <<'\n';
  ++cmd;
}

char GetLetter(int P) {
  // cout<<ind[cmd-1]<<' '<<depth[ind[cmd-1]] <<' '<<P<< '\n';
  // assert(P <= depth[ind[cmd-1]]);
  return C[ fp (ind[cmd-1] , depth[ind[cmd - 1]] - P-1   )];
}
