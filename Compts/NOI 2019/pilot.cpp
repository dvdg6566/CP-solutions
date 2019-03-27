#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<ll> vi;
typedef vector<pi> vpi;

#define pb push_back
#define mp make_pair
#define f first 
#define s second
#define SZ(x) x.size()
#define ALL(x) x.begin(), x.end()
#define lb lower_bound
#define ub upper_bound

ll out[1001000];
ll N,Q,a;
ll H[1001000], ans;
ll r[1001000];
vector<pair<int,pi>> sweep;

struct node{
	int s,e,lazy,m;
	node *l, *r;
	node(int _s, int _e){
		s = _s; e = _e; m = (s+e)/2;lazy = N+1;
		if(s != e){
			l = new node(s,m);
			r = new node(m+1, e);
		}
	}
	void update(int a, int b, int v){
		if (b < a)return;
		if (s == a && b == e){lazy = v; return;}
		value();
		if (a > m){r->update(a,b,v); return;}
		if (b <= m){l->update(a,b,v); return;}
		l->update(a,m,v);
		r->update(m+1,b,v);
	}
	int query(int a){
		if (lazy)return lazy;
		if (a <= m)return l->query(a);
		return r->query(a);
	}
	void value(){
		if (!lazy)return;
		l->lazy = r->lazy = lazy;
		lazy = 0;
	}
}*root;


inline ll choose(ll a){
	return (a * (a-1)) / 2;
}
inline int readInt(){
	int x = 0;
	char ch = getchar_unlocked();
	while(ch<'0'||ch>'9')ch = getchar_unlocked();
	while(ch>='0'&&ch<='9'){
		x = (x << 3) + (x<<1) + ch - '0';
		ch = getchar_unlocked();
	}
	return x;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	//freopen("input.txt","r",stdin);
	N = readInt();
	Q = readInt();
	for (int i=1;i<=N;++i){
		H[i] = readInt();
		sweep.pb(mp(H[i], mp(0, i)));
	}
	for (int i=0;i<Q;++i){
		a = readInt();
		sweep.pb(mp(a, mp(1, i)));
	}
	root = new node(1,N);
	sort(ALL(sweep));
	reverse(ALL(sweep));
	ans = choose(N+1);
	r[N+1] = 0;
	if (sweep.back().s.f == 1){
		out[sweep.back().s.s] = 0;
		sweep.pop_back();
	}
	while(SZ(sweep) && sweep.back().s.f == 0)sweep.pop_back();
	for (auto it : sweep){
		if (it.s.f == 1){
			out[it.s.s] = ans;
			continue;
		}else{
			int p = it.s.s;
			int upp = root->query(p);
			int low = r[upp];
			root->update(low+1, p-1, p);
			root->update(p+1, upp-1, upp);
			ans = ans - choose(upp - low);
			ans = ans + choose(upp - p);
			ans = ans + choose(p - low);
			r[upp] = p;
			r[p] = low;
		}
	}
	for (int i=0;i<Q;++i){
		cout<<out[i]<<'\n';
	}
}

