#include "ricehub.h"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<int, pi> pii;
typedef set<int> si;
typedef vector<pi> vpi;
typedef double dl;
#define mp make_pair
#define pb push_back
#define f first
#define s second
ll MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
#define INF 1000000000
#define SZ(x) x.size()
#define ALL(x) x.begin(),x.end()

map<ll,ll> M;
ll currightindex, medianindex, leftsize, rightsize, cur, ans;
vi X;

int besthub(int R, int L, int _X[], long long B)
{
  ++leftsize;
  for (int i=0;i<R;++i){
    X.pb(_X[i]);
    M[X[i]]++;
  }
  X.pb(INF); 
  for (int i=0;i<R;++i){
    if (i){
    leftsize--;
    cur -= (X[medianindex] - X[i-1]);
    // cout<<"Decreasing current by " << (X[medianindex] - X[i-1]) << '\n'; 
     if(leftsize <=rightsize){
        // if (currightindex < 20)cout<<leftsize<<' '<<rightsize<<' '<<medianindex<<'\n';
        medianindex += (M[X[medianindex]] - 1);
        ++medianindex;
        assert(X[medianindex] != X[medianindex-1]);
        cur += (leftsize - rightsize)*(X[medianindex] - X[medianindex-1]);
        // cout << "Decreasing current by " << rightsize - leftsize << '\n';
          // cout<<"Incrementing median to " << X[medianindex+1]<<'\n';
        leftsize += M[X[medianindex]];
        rightsize -= M[X[medianindex]];
      }
    ans = max(ans, currightindex - i);
    // cout<<i<<' '<<currightindex<<' '<<cur<<' '<<X[medianindex]<<'\n';
    }
    while(++currightindex){
      if (cur > B){currightindex--;break;}
    // cout<<currightindex<<'\n';
      if (currightindex > R){--currightindex;break;}
      cur += (X[currightindex] - X[medianindex]);
      // cout<< "Increase current by " << currightindex<<' '<<X[currightindex] - X[medianindex] << " to " << cur<<'\n'; 
      if (X[currightindex] != X[medianindex])++rightsize;
      else ++leftsize;
      // cout<<leftsize<<' '<<rightsize<<' '<<medianindex<<' '<<currightindex<<'\n';
      if(leftsize <= rightsize && X[currightindex + 1] != X[currightindex]){
        // if (currightindex < 20)cout<<leftsize<<' '<<rightsize<<' '<<medianindex<<'\n';
        medianindex += (M[X[medianindex]] - 1);
        ++medianindex;
        assert(X[medianindex] != X[medianindex-1]);
        cur += (leftsize - rightsize)*(X[medianindex] - X[medianindex-1]);
        // cout << "Decreasing current by " << rightsize - leftsize << '\n';
          // cout<<"Incrementing median to " << X[medianindex+1]<<'\n';
        leftsize += M[X[medianindex]];
        rightsize -= M[X[medianindex]];
      }
      ans = max(ans, currightindex - i);
      // cout<<i<<' '<<currightindex<<' '<<cur<<' '<<X[medianindex]<<'\n';
      if (cur > B)break;
    }
    // cout << i << ' ' << currightindex<< ' '<<cur<<' '<<medianindex<<' '<<leftsize<<' '<<rightsize<<'\n';
    // cout << "Median " << medianindex << '\n';
    // cout << "Left size " << leftsize << '\n';
    // cout << "Right size " << rightsize << '\n';
  }
  return ans;
}
