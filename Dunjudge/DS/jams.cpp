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

int A[100100];
int N,Q,a,b,c,ans;

struct node{
  int times[60]; 
  node *l, *r;
  node(int _s, int _e){
    // cout << "Start " << _s<<' '<<_e<<'\n';
    int m = (_s+_e)/2;
    if (_s != _e){
      l = new node(_s,m);
      r = new node(m+1,_e);
      for (int i=0;i<60;++i){
        int t = l->times[i]+i;
        t += r->times[t%60];
        times[i] = t-i;
      }
    }else{
      // cout << _s<<'\n';
      for (int i=0;i<60;++i){
        if (i%A[_s] == 0)times[i] = 2;
        else times[i] = 1;
      } 
      // for (int i=0;i<=5;++i)cout<<times[i]<<' ';cout<<'\n';
    }
    // cout << _s<<' '<<_e<<'\n';
  }
  void up(int s, int e, int x){
    int m = (s+e)/2;
    if (s == e){
      for (int i=0;i<60;++i){
        if (i%A[s] == 0)times[i] = 2;
        else times[i] = 1;
      }
      return;
    } 
    if (x > m)r ->up(m+1,e,x);
    if (x <= m)l -> up(s,m,x);
    for (int i=0;i<60;++i){
        int t = l->times[i]+i;
        t += r->times[t%60];
        times[i] = t-i;
    }
  }
  void query(int s, int e, int a, int b){
    int m = (s+e)/2;
    if (s == a && e == b){
      ans += times[ans % 60];
      // cout << s << ' ' << e << ' ' << ans << '\n';
      return;
    } 
    if (a > m){r -> query(m+1, e, a,b);return;}
    if (b <= m){l -> query(s,m,a,b);return;}
    l -> query(s,m,a,m);
    r-> query(m+1, e, m+1, b);
  }
} *root;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin >> N >> Q;
  for (int i=0;i<N;++i)cin>>A[i];
  root = new node(0,N-1);
  for (int i=0;i<Q;++i){
    cin>>a>>b>>c;
    if (a == 0){
      ans = 0;
      if (b == c){cout << "0\n";continue;}
      root->query(0,N-1,b,c-1);
      cout<<ans<<'\n';
    }
    else{
      A[b] = c;
      root->up(0,N-1, b);
    }
  }
}

