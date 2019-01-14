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


int N,P,A[100200],a,b,c;

struct node {
  int s, e, m;
  vi V;
  node *l, *r;
  node(int _s, int _e) {
    s = _s; e = _e; m = (s+e)/2;
    if (s == e){
		V.pb(A[s]);
	}
    if (s!=e) {
      l = new node(s, m);
      r = new node(m+1, e);
      vi left = l->V;
      vi right = r->V;
      while (left.size() && right.size()){
		if (left.back() > right.back()){
		  V.pb(left.back());
		  left.pop_back();
		}else{
		  V.pb(right.back());
		  right.pop_back();
		}
	  }
	  while(left.size()){V.pb(left.back());left.pop_back();}
	  while(right.size()){V.pb(right.back());right.pop_back();}
	  reverse(V.begin(),V.end());
    }
  }

  int smaller(int x, int y, int i) {
    if (s==x && e==y) return V.end() - lb(V.begin(),V.end(),i);
    if (x>m) return r->smaller(x, y, i);
    if (y<=m) return l->smaller(x, y, i);
    return l->smaller(x, m, i)+r->smaller(m+1, y, i);
  }
}*root;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> N >> P;
	for (int i = 1; i <= N; ++i){
		cin >> A[i];
	}
	root = new node(1,N);
	sort(A+1,A+N+1);
	for (int i = 0; i < P; ++i){
		cin >> a >> b >> c;
		int low = 0, upp = N;
		while(upp - 1 > low){
			int mid = (upp+low)/2;
			int r = root->smaller(a,b,A[mid]);
			 if (r >= c) low = mid;
			 else upp = mid;
		}
		int r = root->smaller(a,b,A[upp]);
		if (r == c)cout << A[upp] << '\n';
		else cout << A[low] << '\n';
	}
}
