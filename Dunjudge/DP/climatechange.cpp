#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MOD 1e9+7
ll INF = 1e15;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (ll)x.size()
#define ALL(x) x.begin(),x.end()

int grid[1001][1001];
int original[1001][1001];
int R,C,S,A;

bool query (int x){
  for (int i=0;i<R;++i){
    int cur = 0;
    for (int j=C-1; j>= 0; --j){
      if (original[i][j] <= x){
        cur = -1;
      }
      ++cur;
      grid[i][j] = cur;
    }
  }
  // cout<<"query " << x << '\n';
  // for (int i=0;i<R;++i){
    // for (int j=0;j<C;++j)cout<<grid[i][j]<<' ';cout<<'\n';
  // }
  stack<pi> st;
  while(st.size())st.pop();
  for (int j=0;j<C;++j){
    for (int i=0;i<R;++i){
      int lowest = i;
      while (st.size() && st.top().s > grid[i][j]){
        lowest = st.top().f;
        // cout<< "POP " << st.top().f << ' ' << st.top().s<<'\n';
        if (S <= (i-st.top().f) * st.top().s)return 1;
        st.pop();
      }
      if (st.size() && st.top().s == grid[i][j])continue;
      st.push(mp(lowest, grid[i][j]));
      // cout<<"Push " << i << ' ' << grid[i][j] << '\n';
    }
    int t = R-1;
    while(st.size()){
      int res = (t - st.top().f + 1) * st.top().s;
      // cout<<"Res " << res<<'\n';
      if (res >= S)return 1;
      st.pop();
    }
  }
  return 0;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin>>R>>C>>S;
  for (int i=0;i<R;++i)for (int j=0;j<C;++j){cin>>original[i][j];A = max(A, original[i][j]);}
  int lb = 0;
  while(A-lb>1){
    int mid = (A+lb)/2;
    if (query(mid))lb = mid;
    else A = mid;
  }
  if (query(A))cout<<A;
  else cout<<lb;
}
