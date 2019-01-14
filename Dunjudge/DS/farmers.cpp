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
#define lb lower_bound
#define ub upper_bound
#define dst distance
#define INF 1000000000

ll MOD;
ll N,Q,a,b,c;

ll qmult(ll a, ll b){
   if(b == 0) return 0;
   ll H = qmult(a, b/2);
   H %= MOD;
   H += H;
   H %= MOD;
   if(b % 2 == 1) H += a;
   H %= MOD;
   return H;
}

struct node {
  int s, e, m;
  ll v;
  node l,r;
  node(int _s, int _e) {
    s = _s; e = _e; m = (s+e)/2;
    v = 0;
    if (s!=e) {
      l = node(s, m);
      r = node(m+1, e);
    }
  }
  void up(int x, ll nv) {
    if (s==e) { v=nv; return; }
    if (x>m) r.up(x, nv);
    if (x<=m) l.up(x, nv);
    v = qmult(l.v,r.v);
  }
  ll rmq(int x, int y) {
    if (s==x && e==y) return v;
    if (x>m) return r.rmq(x, y);
    if (y<=m) return l.rmq(x, y);
    return qmult(l.rmq(x,m),r.rmq(m+1,y));
  }
}*root;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("input.txt","r",stdin);
	cin >> N >> Q >> MOD;
	root = new node(0,N-1);
	for (int i = 0; i < N; ++i){
		cin >> a;
		root->up(i,a%MOD);
	}
	for (int i = 0; i < Q; ++i){
		cin >> a;
		if (a){
			cin >> b >> c;
			root->up(b,c%MOD);
		}else{
			cin >> b >> c;
			cout << root->rmq(b,c) << '\n';
		}
	}
}
