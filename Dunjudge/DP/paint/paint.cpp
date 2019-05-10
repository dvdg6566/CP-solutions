#include "paint.h"
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
typedef deque<pair<int,int>> vpi;
typedef deque<int> vi;
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
int INF = 1e9;

pi dp[200100][110],dp2[200100][110];
int p[200100][110];
int avail[200100][110];

int block[200100];
int flee[200100];

int blocksum(int a, int b){
  if (a == 0)return block[b];
  return block[b] - block[a-1];
}

string __attribute__((optimise("03"), target("arch=sandybridge"))) solve_puzzle(string S, vector<int> c) {
  int N = SZ(c);
  int L = SZ(S);
  string res = "";
  for (int i=0;i<L;++i){
    res += '?';
  }
  S = "." +  S;
  for (int i=1;i<=L;++i){
    block[i] = block[i-1] + (S[i] == '_');
  }

  for (int i=0;i<=N;++i){
    for (int j=0;j<=L;++j)dp[j][i] = mp(-1,-1);
  }
  
  dp[0][0] = mp(0,0);
  for (int i=1;i<=L;++i)if (S[i] != 'X')dp[i][0] = dp[i-1][0];
  
  memset(p, -1, sizeof(p));

  for (int j=1;j<=N;++j){
    for (int i=c[j-1];i<=L;++i){
      int t = i - c[j-1] + 1;
      if (blocksum(t, i) == 0){
        if (t == 1){
          if (j == 1){
            dp[i][j] = mp(t,i);
          }
        }else{
          if (dp[t-2][j-1].f != -1 && S[t-1] != 'X'){
            dp[i][j] = mp(t,i);
            p[i][j] = dp[t-2][j-1].s;
          }
        }
      }
      
      if (dp[i][j].f != -1)continue;

      if (i&&S[i] != 'X'){
        if (dp[i-1][j].f != -1){
          dp[i][j] = dp[i-1][j];
          p[i][j] = p[i-1][j];
        }
      }
    }
  }

  for (int i=1;i<=L;++i){
    bool can = 0;
    for (int j=1;j<=N;++j){
      int x = i+c[j-1]-1;
      if (x > L)continue;
      if (dp[x][j].f != -1 && dp[x-1][j].f != dp[x][j].f){
        avail[i][j] = 1;
      }
    }
  }

  for (int i=0;i<=N+1;++i){
    for (int j=0;j<=L+2;++j)dp2[j][i] = mp(-1,-1);
  }
  dp2[L+1][N+1] = mp(0,0);

  for (int i=L;i>=1;--i)if (S[i] != 'X')dp2[i][N+1] = dp2[i+1][N+1];

  memset(p, -1, sizeof(p));
  
  for (int j=N;j>=1;--j){
    for (int i=L-c[j-1]+1;i>=0;--i){
      int t = i + c[j-1] - 1;
      if (blocksum(i,t) == 0){
        if (t == L){
          if (j == N){
            dp2[i][j] = mp(i,t);
          }
        }
        else{
        // cout<<"Can make\n";
          if (dp2[t+2][j+1].f != -1 && S[t+1] != 'X'){
            dp2[i][j] = mp(i,t);
            p[i][j] = dp2[t+2][j+1].f;
          }
        }
      }
      if (S[i] != 'X'){
        if (dp2[i+1][j].f != -1){
          dp2[i][j] = dp2[i+1][j];
          p[i][j] = p[i+1][j];
        }
      }
    }
  }
for (int j=1;j<=N;++j){
  int l = c[j-1];
  int K = 0;
  for (int i=1;i<=L;++i){
      int e = i+c[j-1]-1;
      // cout<<i<<' '<<e<<'\n';
      bool blk = (e == L && j == N);
      if ((S[e+1] == 'X' || dp2[e+2][j+1].f == -1) && (!blk)) avail[i][j] = 0;
      if (avail[i][j])K = l;
      if (K > 0)flee[i] = 1;
      --K;
    }
  }

  for (int i=1;i<=L;++i){
    int cfm = 1;
    for (int j=0;j<=N;++j){
      if ( dp[i-1][j].f != -1 && dp2[i+1][j+1].f != -1)cfm = 0;
    }
    if (cfm)res[i-1] = 'X';
  }

  for (int i=0;i<L;++i){
    if (!flee[i+1]){
      res[i] = '_';
  }
    if (S[i+1] == 'X')res[i] = 'X';
  }

  return res;
}