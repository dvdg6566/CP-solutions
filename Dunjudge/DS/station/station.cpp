#include"station.h"
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
#define ALL(x) x.begin(),x.end()

deque<pi> dq;
int p[500100];

int findMinDays(int n, int k, int lodge[])
{
  p[0] = 0;
  dq.pb(mp(0,0));
  for (int i=1;i<n;++i){
    if (lodge[i] == 0){p[i] = -1;continue;}
    // cout<<"Query "<<i<<'\n';
    while (dq.size() && dq[0].s + k  < i){
      // cout<<"Remove " << dq[0].s << '\n';
      dq.pop_front();
    }
    if (!dq.size())return -1;
    p[i] = dq[0].f + 1;
    while(dq.size() && dq.back().f > p[i]){
      // cout<<dq.back().f<<'\n';
      dq.pop_back();
    }
    dq.pb(mp( p[i],i ));
  }
  // for (int i=0;i<n;++i)cout<<p[i]<<' ';cout<<'\n';
	return p[n-1];
}
