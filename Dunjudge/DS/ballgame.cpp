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

vpi V,O;

struct node {
  ll s, e, m, v, lazyadd;
  node *l, *r;
  node(ll _s, ll _e) {
    s = _s; e = _e; m = (s+e)/2;
    v = 0; lazyadd = 0;
    if (s!=e) {
      l = new node(s, m);
      r = new node(m+1, e);
    }
  }
  ll pq(ll x) {
    value();
    if (s == e)return v;
    if (x>m) return r->pq(x);
    return l->pq(x);
  }
  
  void add(ll x, ll y, ll val, ll ht) {
    if (s == x && e == y) {
		if(s == e){
			if (V[s].s <= ht)return; // If student is shorter ignore
		}
		lazyadd += val; //modifies lazyadd when corresponding
	}
    else {
      if (x > m) r->add(x, y, val, ht);
      else if (y <= m) l->add(x, y, val, ht);
      else l->add(x, m, val, ht), r->add(m+1, y, val, ht);
    }
  }
  
  ll value() { //propagate lazyadd to children, return value
    if (s==e) { 
		v+=lazyadd;
		lazyadd=0;
		return v; 
	}
    v += lazyadd;
    r->lazyadd += lazyadd; l->lazyadd += lazyadd;
    lazyadd = 0;
    return v;
  }
}*root;



int ballgame(int N, int L, int D, int H[], int C[]) {
	--D;
	for (int i = 0; i < N; ++i)V.pb(mp(C[i],H[i]));
	sort(V.begin(),V.end());
	for (int i = 0; i < N; ++i){
		O.pb(mp(V[i].s, i));
	}
	sort(O.begin(),O.end());
	reverse(O.begin(),O.end());
	for (auto i : V)cout << i.f << ' ' << i.s << '\n';
	for (auto i : O){
		cout << "Student with height " << i.f << '\n';
		int l = max(0LL,V[i.s].f - D);
		int u = min((ll)L,V[i.s].f + D);
		cout << "Has a range of " << l << ' ' << u << '\n';
		int btm = 
		cout << dst(V.begin(),lb(V.begin(),V.end(),mp((ll)l,0LL))) << ' ';
		cout << dst(V.begin(),ub(V.begin(),V.end(),mp((ll)u,(ll)L)))-1 << '\n';
	}
	return 0;
}


int main() {
	freopen("input.txt","r",stdin);
	int N, L, D;
	scanf("%d%d%d", &N, &L, &D);
	int H[N], C[N];
	for (int i = 0; i < N; ++i) scanf("%d%d", &H[i], &C[i]);
	printf("%d\n", ballgame(N, L, D, H, C));
}
