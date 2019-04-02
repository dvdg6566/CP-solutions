#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<int,int> pi;
typedef pair<int,pi> pii;
typedef vector<pi> vpi;
typedef set<int> si;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define f first
#define s second
ll INF = 1e8;
ll MOD = 1e9;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()

pi A[22000];

// int dist(pi a, pi b){
  // return abs(a.f - b.f) + abs(a.s - b.s);
// }

map<int,int> hori, vert;
int N, hoffset, voffset;
int hmin, vmin;

int findhori(int x){
  auto above = hori.lb(x);
  int ans = INF;
  ans = above->s + (above->f - x);
  --above;
  ans = min(ans, above->s + x - above->f);
  // cout<< "Horizontal at " << x << ": " << ans+hoffset << '\n';
  return ans + hoffset;
}

int findvert(int x){
  auto above = vert.lb(x);
  int ans = INF;
  ans = above->s + (above->f - x);
  --above;
  ans = min(ans, above->s + x - above->f);
  // cout<< "Vertical at " << x << ": " << ans+voffset << '\n';
  return ans + voffset;
}

void hinsert(int x, int y){
  // cout<<"Horizontal insert " << x << ' ' << y << '\n';
  y -= hoffset;
  hmin = min(y, hmin);
  hori[x] = y;
  while(1){
    auto above = hori.ub(x);
    if (above->f == INF)break;
    if (above->s > y + above->f - x)hori.erase(above);
    else break;
  }
  while(1){
    auto below = --(hori.lb(x));
    if (below->f == -INF)break;
    if (below->s > y + x - below ->f)hori.erase(below);
    else break;
  }
}

void vinsert(int x, int y){
  // cout<<"Vertical insert " << x << ' ' << y << '\n';
  y -= voffset;
  vmin = min(y, vmin);
  vert[x] = y;
  while(1){
    auto above = vert.ub(x);
    if (above->f == INF)break;
    if (above->s > y + above->f - x)vert.erase(above);
    else break;
  }
  while(1){
    auto below = --(vert.lb(x));
    if (below->f == -INF)break;
    if (below->s > y + x - below ->f)vert.erase(below);
    else break;
  }
}


int h,q;

int main(){
    // freopen("input.txt","r",stdin);
    cin >> N;
    for (int i=1;i<=N;++i)cin>>A[i].f>> A[i].s;
    hori[-INF] = 2*INF;
    vert[-INF] = 2*INF;
    hori[0] = 0;
    vert[0] = 0;
    hori[INF] = 2*INF;
    vert[INF] = 2*INF;

    for (int i=1;i<=N;++i){
      int hcost = findhori(A[i].s);
      int vcost = findvert(A[i].f);
      hoffset = hoffset + abs(A[i].f - A[i-1].f);
      voffset = voffset + abs(A[i].s - A[i-1].s);
      if (hcost < findvert(A[i-1].f)){
        vinsert(A[i-1].f, hcost);
      }
      if (vcost < findhori(A[i-1].s)){
        hinsert(A[i-1].s, vcost);
      }
      h = findhori(A[i].s);
      q = findvert(A[i].f);
      // cout<<hoffset<<' '<<voffset<<'\n';
    }
    cout<<min(vmin+voffset, hmin+hoffset)<<'\n';
}
