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

struct node {
  int s, e, m, v;
  map<int,int> M;
  node *l, *r;
  node(int _s, int _e) {
    s = _s; e = _e; m = (s+e)/2;
    v = 0;
    if (s!=e) {
      l = new node(s, m);
      r = new node(m+1, e);
    }
  }
  void up(int x, int nv, int original) {
    if (s==e) {
		if (original!=-1){
			M[original]--;
		}
		M[nv]++;
		return;
	}
    if (x>m) r->up(x, nv, original);
    if (x<=m) l->up(x, nv, original);
    if (original!=-1){
		M[original]--;
	}
	M[nv]++;
  }
  int rqq(int x, int y, int ind) {
    if (s==x && e==y) return M[ind];
    if (x>m) return r->rqq(x, y, ind);
    if (y<=m) return l->rqq(x, y, ind);
    return l->rqq(x, m, ind)+r->rqq(m+1, y, ind);
  }
}*root;

int N,Q,arr[301000],a,b,c,op;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> N >> Q;
	root = new node(1,N);
	for (int i = 1; i <= N; ++i){
		cin>>arr[i];
		root->up(i,arr[i],-1);
	}
	for (int i = 0;i < Q; ++i){
		cin >> op;
		if (op == 1){
			cin >> a >> b >> c;
			cout << root->rqq(a,b,c) << '\n';
		}else{
			cin >> a >> b;
			root->up(a,b,arr[a]);
			arr[a] = b;
		}
	}
}
