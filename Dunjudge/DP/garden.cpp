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

int rsq[260][260];
int H,W,N,K,a,b;
int L[260], R[260],ans=INF;

int query(pi a, pi b){
  if (a.f > b.f)swap(a.f,b.f);
  if(a.s>b.s)swap(a.s,b.s);
  return rsq[b.f][b.s] - rsq[a.f-1][b.s] - rsq[b.f][a.s-1] + rsq[a.f-1][a.s-1];  
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  freopen("input.txt","r",stdin);

  cin>>H>>W>>N>>K;
  for (int i=0;i<N;++i){
    cin>>a>>b;
    rsq[a][b]++;
  }
  for (int i=1;i<=H;++i){
    for(int j=1;j<=W;++j){
      rsq[i][j] = rsq[i][j] + rsq[i-1][j] + rsq[i][j-1] - rsq[i-1][j-1];
    }
  }
  int tL=INF;
  for (int i=1;i<=H;++i){
    for(int j=1;j<=W;++j){
      if (rsq[i][j] < K)continue;
      if (tL == INF && query(mp(1,1), mp(i,j)) >= K){
        // cout <<i <<' '<<j<<'\n';
        tL = i+j-3;
      }
      bool b=1;
      while(b){
        b=0;
        for (int k=1;k<=W;++k){
          if (abs(k-j)>tL)continue;
          int t=i-(tL - abs(k-j));
          if (t<1)continue;
          if (query(mp(t,k), mp(i,j)) >= K){
            // cout<<tL<<' '<<t<<' '<<k<<' '<<i<<' '<<j<<' '<<query(mp(t,k), mp(i,j)) <<'\n';
            --tL;
            b=1;
            break;
          }
        }
      }
    }
    L[i] = tL;
  }
  tL = INF;
  for (int i=H;i>=1;--i){
    for(int j=1;j<=W;++j){
      if (rsq[i][j] < K)continue;
      if (tL == INF && query(mp(H,1), mp(i,j)) >= K){
        // cout <<i <<' '<<j<<'\n';
        tL = (H - i) + (j-1) -1;
      }
      bool b=1;
      while(b){
        b=0;
        for (int k=1;k<=W;++k){
          if (abs(k-j)>tL)continue;
          int t=i+(tL - abs(k-j));
          if (t>H)continue;
          if (query(mp(t,k), mp(i,j)) >= K){
            // cout<<tL<<' '<<t<<' '<<k<<' '<<i<<' '<<j<<' '<<query(mp(t,k), mp(i,j)) <<'\n';
            --tL;
            b=1;
            break;
          }
        }
      }
    }
    R[i] = tL;
  }
  for (int i=1;i<H;++i)ans = min(ans,2*(R[i+1]+3)+2*(L[i]+3));
  
  // for (int i=1;i<=H;++i)cout<<2*(R[i]+3)<<' ';cout<<'\n';

  // for (int i=1;i<=H;++i)cout<<2*(L[i]+3)<<' ';
  // cout<<ans;
  for (int i=1;i<=max(H,W);++i){
    for (int j=1;j<i;++j){
      swap(rsq[i][j],rsq[j][i]);
    }
  }
  swap(H,W);
    tL=INF;
  for (int i=1;i<=H;++i){
    for(int j=1;j<=W;++j){
      if (rsq[i][j] < K)continue;
      if (tL == INF && query(mp(1,1), mp(i,j)) >= K){
        // cout <<i <<' '<<j<<'\n';
        tL = i+j-3;
      }
      bool b=1;
      while(b){
        b=0;
        for (int k=1;k<=W;++k){
          if (abs(k-j)>tL)continue;
          int t=i-(tL - abs(k-j));
          if (t<1)continue;
          if (query(mp(t,k), mp(i,j)) >= K){
            // cout<<tL<<' '<<t<<' '<<k<<' '<<i<<' '<<j<<' '<<query(mp(t,k), mp(i,j)) <<'\n';
            --tL;
            b=1;
            break;
          }
        }
      }
    }
    L[i] = tL;
  }
  tL = INF;
  for (int i=H;i>=1;--i){
    for(int j=1;j<=W;++j){
      if (rsq[i][j] < K)continue;
      if (tL == INF && query(mp(H,1), mp(i,j)) >= K){
        // cout <<i <<' '<<j<<'\n';
        tL = (H - i) + (j-1) -1;
      }
      if (tL==INF)continue;
      bool b=1;
      while(b){
        b=0;
        // cout <<i<<' '<<j<<'\n';
        for (int k=1;k<=W;++k){
          if (abs(k-j)>tL)continue;
          int t=i+(tL - abs(k-j));
          // cout<<t<<' '<<k<<' '<<i<<' '<<j<<' '<<'\n';
          if (t>H)continue;
          if (query(mp(t,k), mp(i,j)) >= K){
            // cout<<tL<<' '<<t<<' '<<k<<' '<<i<<' '<<j<<' '<<query(mp(t,k), mp(i,j)) <<'\n';
            --tL;
            b=1;
            break;
          }
        }
      }
    }
    R[i] = tL;
  }
  // for (int i=1;i<=H;++i)cout<<2*(3+R[i])<<' ';cout<<'\n';
  // for (int i=1;i<=H;++i)cout<<2*(3+L[i])<<' ';cout<<'\n';
  for (int i=1;i<H;++i)ans = min(ans,2*(R[i+1]+3)+2*(L[i]+3));
  cout<<ans;


}
