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
ll INF = 1e8;
ll MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()

set<int> breaks;
int N,Q,a,b;
int A[300001], done[300001], ind[300001];

void rmv(int x){
  breaks.erase(x);
}

void add(int x){
  breaks.insert(x);
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  // freopen("in.txt","r", stdin);
  cin >> N >> Q;
  for (int i=1;i<=N;++i)cin>>A[i];
  for (int i=1;i<=N;++i){
    ind[A[i]] = i;
    done[A[i]] = 1;
    if (!done[A[i]-1]){
      breaks.insert(A[i]);
    }
  }
  cout<< *(--breaks.end()) - 1<< '\n';
  for (int i=0;i<Q;++i){
    cin >> a >> b;
    swap(A[a], A[b]);
    a = A[a];
    b = A[b];
    swap(ind[a], ind[b]);
    if (a > 1){
      if (ind[a-1] < ind[a])rmv(a);
      else add(a);
    }   
    
    if (a < N){
      if (ind[a] < ind[a+1])rmv(a+1);
      else add(a+1);
    }

    if (b > 1){
      if (ind[b-1] < ind[b])rmv(b);
      else add(b);
    }   
    
    if (b < N){
      if (ind[b] < ind[b+1])rmv(b+1);
      else add(b+1);
    }
    cout<< *(--breaks.end()) - 1 <<'\n';
  }
}
