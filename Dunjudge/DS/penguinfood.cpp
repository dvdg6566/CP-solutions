#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MOD 1e9+7
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()

int A[1001000];
int N,Q,a,b;

struct node{
  ll maxpref, sum, maxsuff, maxsum;
  node *l, *r;
  node(int _s, int _e){
    int m = (_s+_e)/2;
    if (_s != _e){
      l = new node(_s,m);
      r = new node(m+1,_e);
      maxsum = max({l->maxsum, r->maxsum, l->maxsuff + r-> maxpref});
      sum = l->sum + r->sum;
      maxsuff = max(l->maxsuff + r->sum, r->maxsuff);
      maxpref = max(r->maxpref + l->sum, l->maxpref);
      // cout << s << ' ' << e << ' ' << maxsum << '\n';
    }else{
      sum = A[_s];
      maxsum = maxpref = maxsuff = max(0,A[_s]);
      // cout << s << ' ' << maxsum << '\n';
    }
  }
  void up(int s, int e, int x){
    int m = (s+e)/2;
    if (s == e){
      assert(s==x);
      sum = A[s];
      maxsum = maxpref = maxsuff = max(0,A[s]);
      // cout << s << ' ' << maxsum << '\n';
      return;
    } 
    if (x > m)r ->up(m+1,e,x);
    if (x <= m)l -> up(s,m,x);
      maxsum = max({l->maxsum, r->maxsum, l->maxsuff + r-> maxpref});
      sum = l->sum + r->sum;
      maxsuff = max(l->maxsuff + r->sum, r->maxsuff);
      maxpref = max(r->maxpref + l->sum, l->maxpref); 
  }
} *root;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin>>N;
  for (int i=0;i<N;++i)cin>>A[i];
  root = new node(0, N-1);
  cout << root->maxsum << '\n';
  cin>>Q;
  for (int i=0;i<Q;++i){
    cin>>a>>b;
    A[a] = b;
    root->up(0,N-1,a);
    cout << root->maxsum << '\n';
  }
}
