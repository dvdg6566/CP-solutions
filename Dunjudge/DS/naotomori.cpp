#include<bits/stdc++.h>
using namespace std;

int fw[1000001];
int N,Q,a;

void update(int x, int y, int v) { // incluse
  x--;
  for(; y; y-=y&(-y)){
    // cout<<"Update " << y << " Pos\n";
    fw[y] += v;
  }
  for(; x; x-=x&(-x)) {
    // cout<<"Update " << x << " Neg\n";
    fw[x] -= v;
  }
}
int query(int x) {
  // cout<<x<<'\n';
  int res = 0, cur = 0;
  for (int i=19;i>=0;--i){
    if (res + (1<<i) > N)continue;
    // cout<<"Query "<<i<<'\n';
    if (fw[res+(1<<i)] + cur > x){
    cur += fw[res+(1<<i)];
      continue;
    }
    res += (1<<i);
  }
  return res;
}

inline int RI() {
    int x = 0;
    char ch = getchar_unlocked();
    while (ch < '0' || ch > '9') ch = getchar_unlocked();
    while (ch >= '0' && ch <= '9'){
		x = (x << 3) + (x << 1) + ch - '0';
		ch = getchar_unlocked();
	}
    return x;
}
int p[1000010],clear[1000100];
int par(int x) { return (x==p[x])?x:p[x]=par(p[x]);}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  N = RI();
  Q = RI();
  memset(fw,-1,sizeof(fw));
  for (int i=2;i<=N;i*=2){
    for(int j=i;j<=N;j+=i)fw[j] *= 2;
  }
  for (int y=N;y;y-=(y&(-y)))fw[y] = y;
  for (int i=1;i<=N;++i){
    p[i] = i;
  }
  for (int i=0;i<Q;++i){
    a= RI();
    a = a % (N-i);
    if (a == 0)a = N-i;
    int x = query(a) - 1;
    int t = par(x);
    clear[t] = 1;
    p[t] = par(t-1);
    update(t+1, N, -1);
  }
  for (int i=1;i<=N;++i)if(!clear[i-1])cout<<i-1<<' ';
}