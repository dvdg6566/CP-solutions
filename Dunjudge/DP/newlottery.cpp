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
#define MOD 1000000007LL
#define lb lower_bound
#define ub upper_bound
#define dst distance
#define ALL(X) (X).begin(), (X).end()

int ba[] = {1,1,0,0};
int bb[] = {0,1,0,1};
int bx[] = {1,0,0,1};

int T,A,B,M;
int P[8], C[8];

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  freopen("input.txt","r",stdin);
  cin>>T;
  for (int i=1;i<=T;++i){
    cin>>A>>B>>M;
    int X = log2(max(A,B));
    for (int j=0;j<=X;++j){
      if (A&(1<<j)){
        
      }
    }
  }
}
