#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end

int N,M,odeg,T;
string s;

    
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin>>T;
  for (int x=0;x<T;++x){
    cin>>N>>M;
    short A[N][M];
    for (int i=0;i<N;++i){
      cin>>s;
      for (int j=0;j<M;++j){
        A[i][j] = s[j] - 'a';
      }
    }
    odeg = 0;
    for (int i=0;i<N;++i){
      for (int j=0;j<M;++j){
        int deg = 0;
        if (j+1 < M){
          if (i+1 < N){
            deg += (A[i][j+1] != A[i+1][j+1]);
            deg += (A[i+1][j] != A[i+1][j+1]);
          }
          deg += (A[i][j] != A[i][j+1]);
        }
        if (i+1 < N){
          deg += (A[i][j] != A[i+1][j]);
        }
        if (deg%2 == 1)odeg++;
        // cout<<i<<' '<<j<<' '<<deg<<'\n';
      }
    } 
    for (int i=1;i<M;++i){
      odeg += (A[0][i] != A[0][i-1]);
    }
    for (int i=1;i<N;++i){
      odeg += (A[i][0] != A[i-1][0]);
    }
    cout << (odeg+1)/2 << '\n';
  }
}
