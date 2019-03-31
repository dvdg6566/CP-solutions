#include"tile.h"
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
typedef pair<pi,pi> pii;
#define mp make_pair
#define f first
#define s second

int memo[256][256];
int cur = 1;

bool inside(pii bound, int x, int y){
  if (x <= bound.s.f && x >= bound.f.f && y <= bound.s.s && y >= bound.f.s)return 1;
  return 0;
}

void run(pii bound, int x, int y){
  int a = bound.f.f, b = bound.f.s, c = bound.s.f, d = bound.s.s;
  if (a == c && b == d)return;
  if (memo[x][y] == 0)return;
  int len = (c-a+1)/2-1;
  pi midsq = mp(a + len, b + len);
  pii lefttop = mp(mp(a,b), midsq);
  pii leftbtm = mp(mp(a, midsq.s + 1), mp(midsq.f, d));
  pii righttop = mp(mp(midsq.f + 1, b), mp(c, midsq.s));
  pii rightbtm = mp(mp(midsq.f + 1, midsq.s + 1), mp(c,d));
  if (inside(lefttop, x,y)){
    memo[midsq.f][midsq.s+1] = memo[midsq.f+1][midsq.s] = memo[midsq.f+1][midsq.s+1] = cur++;
    run (lefttop, x, y);
    run (leftbtm, midsq.f, midsq.s+1);
    run (righttop, midsq.f + 1, midsq.s);
    run (rightbtm, midsq.f+1, midsq.s+1);
  }
  if (inside(leftbtm, x, y)){
    memo[midsq.f][midsq.s] = memo[midsq.f+1][midsq.s] = memo[midsq.f+1][midsq.s+1] = cur++;
    run(leftbtm, x, y);
    run (lefttop, midsq.f, midsq.s);
    run (righttop, midsq.f + 1, midsq.s);
    run (rightbtm, midsq.f+1, midsq.s+1);
  }
  if (inside(righttop, x, y)){
    memo[midsq.f][midsq.s] = memo[midsq.f][midsq.s+1] = memo[midsq.f+1][midsq.s+1] = cur++;
    run(righttop, x, y);
    run (lefttop, midsq.f, midsq.s);
    run (leftbtm, midsq.f, midsq.s+1);
    run (rightbtm, midsq.f+1, midsq.s+1);
  }
  if (inside(rightbtm, x, y)){
    memo[midsq.f][midsq.s] = memo[midsq.f+1][midsq.s] = memo[midsq.f][midsq.s+1] = cur++;
    run(rightbtm, x, y);
    run (lefttop, midsq.f, midsq.s);
    run (leftbtm, midsq.f, midsq.s+1);
    run (righttop, midsq.f + 1, midsq.s);
  }
  

  // for (int i=0;i<4;++i){
  //   for (int j=0;j<4;++j)cout<<memo[i][j]<<' ';cout<<'\n';
  // }

}

#define pb push_back
vector<int> res[22000];

void placeTile(int n, int x, int y, int pos[][6])
{
  memo[x][y] = -1;
  n = (1<<n);
  run (mp(mp(0,0), mp(n-1,n-1)), x, y);
  for (int i=0;i<n;++i){
    for (int j=0;j<n;++j)memo[i][j]--;
  }
  for (int i=0;i<n;++i){
    for (int j=0;j<n;++j){
      // cout<<memo[i][j]<<' ';
      if (memo[i][j]<0)continue;
      res[memo[i][j]].pb(i);
      res[memo[i][j]].pb(j);
    }
    // cout<<'\n';
  }
  int r = (n*n)/3;
  for (int i=0;i<r;++i){
    for (int j=0;j<6;++j)pos[i][j] = res[i][j];
  }
}
