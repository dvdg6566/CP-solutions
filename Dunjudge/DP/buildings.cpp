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

int H,W,A,B,ans=INF;
bool ch;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin>>H>>W>>A>>B;
  if (H>W){
    swap(H,W);
    swap(A,B);
    ch = 1;
  }
  int G[H][W];
  if (!ch){
    for(int i=0;i<H;++i){
      for(int j=0;j<W;++j){
        cin>>G[i][j];
      }
    }
  }else{
    for (int i=0;i<W;++i){
      for (int j=0;j<H;++j){
        cin>>G[j][i];
      }
    }
  }
  deque<pi> dq[H+1];
  for (int j=0;j<W;++j){
    dq[H].clear();
    for(int i=0;i<H;++i){
      if(SZ(dq[i]) && dq[i][0].s + B == j)dq[i].pop_front();
      while(SZ(dq[i]) && dq[i].back().f < G[i][j])dq[i].pop_back();
      dq[i].pb(mp(G[i][j],j));
      if (j + 1 >= B){
        if(SZ(dq[H]) && dq[H][0].s + A == i)dq[H].pop_front();
        while(SZ(dq[H]) && dq[H].back().f < dq[i][0].f)dq[H].pop_back();
        dq[H].push_back(mp(dq[i][0].f,i));
        if (i + 1 >= A)ans = min(ans, dq[H][0].f);
      }
    }
  }
  cout<<ans;
}
