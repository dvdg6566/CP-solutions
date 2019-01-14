#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef double dl;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MOD 1e9+7
#define lb lower_bound
#define ub upper_bound
#define dst distance
#define INF 1000000000

int p[100010], c[100010];
int N,T,A[510];

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >>N;for(int i=0;i<N;++i)cin>>A[i];
  memset(p,-1,sizeof(p));memset(c,-1,sizeof(c));
  p[50000] = 0;
  for (int i=0;i<N;++i){
    for (int j = 50000-T; j <= 50000+T && j <= 100000; ++j){
      if(p[j] == -1)continue;
      //cout << "Running\n";
      c[j] = max(c[j],p[j]); // Dont take
      if (100000 >= A[i] + j){
        // Person A takes
        c[j + A[i]] = max(c[j+A[i]], p[j] + A[i]);
      }
      if (0 <= j - A[i]){
        // B takes
        c[j - A[i]] = max(c[j-A[i]], p[j] + A[i]);
      }
    }
    swap(p,c);
    T += A[i];
    memset(c,-1,sizeof(c));
  }
  cout << (T*2-p[50000])/2;
}
		sum += a;
	}
}
