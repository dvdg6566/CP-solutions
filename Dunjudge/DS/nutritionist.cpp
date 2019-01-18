#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll,ll> pi;
typedef pair<int,pi> pii;
typedef vector<pi> vpi;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()

multiset<ll> big, small;
ll N,K,L,a,b,start,ans,sum;
vpi V;

void remove(ll x){
  // if(big.lb(x) == big.ub(x) && small.lb(x) == small.ub(x))while(1)cout<<"G";
  // if (small.size() && *(big.begin()) < *(--small.end()))while(1)cout<<"GG";
  // if (!big.size()){while(1)cout<<"0";}
  // assert(big.size());
  // cout << "REMOVE " << x << '\n';
  if (x >= *(big.begin())){
    big.erase(big.find(x));
    sum -= x;
    if (small.size()){
      big.insert(*(--small.end()));
      sum += *(--small.end());
      small.erase(--small.end());
    }
  }
  else{
    // if (small.lb(x) == small.ub(x))while(1)cout<<"GG";
    small.erase(small.find(x));
  }
}

void add(ll x){
  // assert(big.size());
  // cout << "ADD " << x << '\n';
  big.insert(x);
  sum += x;
  if (big.size() > K){
    sum -= *big.begin();
    small.insert(*big.begin());
    big.erase(big.begin());
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin>>N>>K>>L;
  for (int i=0;i<N;++i){
    cin>>a>>b;
    V.pb(mp(a,b));
  }
  sort(ALL(V));
  big.insert(V[0].s);
  sum = V[0].s;
  ans = V[0].s;
  for (int i=1;i<N;++i){
    // if (small.size()+big.size() != i-start)while(1)cout<<"GG\n";
    while(V[start].f + L < V[i].f){
      assert(start < i);
      remove(V[start].s);
      ++start;
    }
    add(V[i].s);
    ans = max(ans,sum);
  }
  cout<<ans;
}
