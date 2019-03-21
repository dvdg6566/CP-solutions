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
ll INF = 1e9;
ll MOD = 1e9;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()


int two[1010][1010], twop[1010][1010], five[1010][1010], fivep[1010][1010], A[1010][1010];
int N;
string S;
pi stop;
bool over;

void d2(int a, int b){
  if (a+b == 0)return;
  if (twop[a][b] == 1){
    S += 'D';
    d2(a-1, b);
  }else{
    S += 'R';
    d2(a, b-1);
  }
}

void d5(int a, int b){
  if (a+b == 0)return;
  if (fivep[a][b] == 1){
    S += 'D';
    d5(a-1, b);
  }else{
    S += 'R';
    d5(a, b-1);
  }
}


int main(){
  //freopen("input.txt","r",stdin);
  cin>>N;
  for (int i=0;i<N;++i)for (int j=0;j<N;++j)two[i][j] = five[i][j] = INF;
  for (int i=0;i<N;++i)for (int j=0;j<N;++j){
	  cin>>A[i][j];
	  if (A[i][j] == 0){
		over = 1;
		stop = mp(i,j);
	  }
  }
  two[0][0] = 0; five[0][0] = 0;
  for (int i=0;i<N;++i){
    for (int j=0;j<N;++j){
	  if (j == 0)twop[i][j] = 1;
      else if (i == 0)twop[i][j] = 2;
      else if (two[i][j] == two[i-1][j]) twop[i][j] = 1; // Go up
      else if (two[i][j] == two[i][j-1])twop[i][j] = 2;
      int p=0;
      while(A[i][j] && A[i][j] % 2 == 0){
        ++p; A[i][j] /= 2;
      }
      two[i][j] += p;
      two[i+1][j] = min(two[i+1][j], two[i][j]);
      two[i][j+1] = min(two[i][j+1], two[i][j]);
    }
  }
  for (int i=0;i<N;++i){
    for (int j=0;j<N;++j){
      if (j == 0)fivep[i][j] = 1;
      else if (i == 0)fivep[i][j] = 2;
      else if (five[i][j] == five[i-1][j]) fivep[i][j] = 1; // Go up
      else if (five[i][j] == five[i][j-1])fivep[i][j] = 2;
      int p=0;
      while(A[i][j] && A[i][j] % 5 == 0){
        ++p; A[i][j] /= 5;
      }
      five[i][j] += p;
      five[i+1][j] = min(five[i+1][j], five[i][j]);
      five[i][j+1] = min(five[i][j+1], five[i][j]);
    }
  }
  if (over && min(two[N-1][N-1], five[N-1][N-1]) != 0){
	  cout<<1<<'\n';
	 for (int it=0;it<stop.f;++it)cout<<'D';
	 for (int it=0;it<stop.s;++it)cout<<'R';
	 for (int it=stop.f+1;it<N;++it)cout<<'D';
	 for (int it=stop.s+1;it<N;++it)cout<<'R';
	 return 0;
  }
  cout<<min(two[N-1][N-1], five[N-1][N-1])<<'\n';
  if (two[N-1][N-1] <= five[N-1][N-1])d2(N-1, N-1);
  else d5(N-1, N-1);
  reverse(ALL(S));
  cout<<S;
}
