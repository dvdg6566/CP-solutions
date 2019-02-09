#include "squarerect.h"
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
#define mp make_pair
int grid[201][201];
int lx, ly, ux, uy, cnt;
map<pi, int> M;

bool query(int a, int b){
  if (a <= 0 || b <= 0)return 0;
  if (a > 100 || b >100)return 0;
  ++cnt;
  if (M[mp(a,b)] == 0){
    int t = inside_shape(a,b);
    M[mp(a,b)] = 1+t;
  }
  return M[mp(a,b)] - 1;
}

bool am_i_square(int N, int Q) {
  memset(grid,0,sizeof(grid));
  M.clear();
  // cout<<cnt<<'\n';
  lx = ly = ux = uy = 0;
  cnt = 0;
	assert(N==100);
	for (int i=20; i <= 80; i += 20){
		for (int j=20; j<= 80; j += 20){
			grid[i][j] = query(i,j);
      // cout<<grid[i][j]<<' ';
		}
    // cout<<'\n';
	}
	for (int i=20; i <= 80; i += 20){
		for (int j=20; j<= 80; j += 20){
      if (grid[i][j] == 1 && grid[i+20][j+20] == 0 && grid[i+20][j] == 0 && grid[i][j+20] == 0){
        lx = i;
        ly = j;
      }
    }
  }
  // cout<<lx<<' '<<ly<<'\n';
  if (lx == 0 && ly == 0){
    for (int i=20; i <= 100; i += 20){
		  for (int j=20; j<= 100; j += 20){
			grid[i][j] = query(i,j);
		  }
	  }
    for (int i=20; i <= 100; i += 20){
		for (int j=20; j<= 100; j += 20){
      if (grid[i][j] == 1 && grid[i+20][j+20] == 0 && grid[i+20][j] == 0 && grid[i][j+20] == 0){
        lx = i;
        ly = j;
      }
    }
    }
    if (lx == 0 && ly ==0)return 0;
     ux = lx+21;
    uy = ly + 21;
    int temp = lx;
   while (ux > lx + 1){
    int mid = (ux + lx)/2;
    int t = query(mid, ly);
    if (t == 0)ux = mid;
    else lx = mid;
   }
    while (uy > ly + 1){
      int mid = (uy + ly)/2;
      int t = query(temp, mid);
      if (t == 0)uy = mid;
      else ly = mid;
    }
    lx -= 19;
    ly -= 19;
    if (query(lx, ly) && query(lx-1, ly) == 0 && query(lx, ly-1) == 0)return 1;
    return 0;
  }
  ux = lx+21;
  uy = ly + 21;
  int temp = lx;
  while (ux > lx + 1){
    int mid = (ux + lx)/2;
    int t = query(mid, ly);
    if (t == 0)ux = mid;
    else lx = mid;
  }
  while (uy > ly + 1){
    int mid = (uy + ly)/2;
    int t = query(temp, mid);
    if (t == 0)uy = mid;
    else ly = mid;
  }
  int x = lx;
  int y = ly;
  // cout<<"NEW\n";
  for (int i=20; i <= 80; i += 20){
		for (int j=20; j<= 80; j += 20){
      if (grid[i][j] == 1 && grid[i-20][j-20] == 0 && grid[i-20][j] == 0 && grid[i][j-20] == 0){
        ux = i;
        uy = j;
      }
    }
  }
  lx = ux - 20;
  ly = uy - 20;
  int dif = y-x;
  if ((lx + dif < ly || lx + dif > uy) && (ux + dif < ly || ux + dif > uy))return 0;
  // cout<<lx<<' '<<ux<<'\n';
  // cout<<ly<<' '<<uy<<'\n';
  while (lx+1 < ux){
    int mid = (lx + ux) / 2;
    int oth = mid + dif;
    int t = query(mid,oth);
    if (t == 1)ux = mid;
    else lx = mid;
  }
  int cy = lx + dif;
  if (cy < ly || cy > uy)return 0;
  ly = cy;
  if (lx < 0||ly < 0)return 0;
  if (query(lx+1, ly) == 0 && query(lx, ly+1) == 0 && query(lx+1, ly+1) == 1)return 1;
	return 0;
}
// 26 94 32 100
