#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef vector<ll> vi;
typedef vector<pi> vpi;

#define pb push_back
#define mp make_pair
#define f first 
#define s second
#define SZ(x) x.size()
#define ALL(X) x.begin(), x.end()
ll H[500100];
ll N,L,x;

struct node{
	ll s,e,lazy, m,v, open;
	node *l, *r;
	node(int _s, int _e){
		s = _s; e = _e; m = (s+e)/2; v = 0;lazy = 0;
	}
	
	void update(int a, int b){
		//cout<<s<<' '<<e<<' '<<a<<' '<<b<<'\n';
		if (lazy)return;
		if (s == a && e == b){
			lazy = 1;
			return;
		}
		if (s != e && !open) {
			l = new node(s,m);
			r = new node(m+1, e);
			open = 1;
		}
		if (a > m)r->update(a,b);
		else if (b <= m)l->update(a,b);
		else {l->update(a,m); r->update(m+1,b);}
		v = l->val() + r->val();
	}
	
	ll val(){
		if (lazy)return e-s+1;
		return v;
	}
}*root;

void up(ll a, ll b){
	if (a > b)return;
	//cout<<"Update " << a << ' ' << b << '\n';
	root->update(a,b);
}

int main(){
	//freopen("in.2.txt","r",stdin);
	cin >> L >> N;
	root = new node(0,L);
	for (int i=0;i<N;++i){
		cin >> x;
		ll l = 1;
		ll r = L;
		for (int it = 0;it < x;++it){
			cin>>H[it];
			r -= H[it];
		}
		for (int it=0;it<x;++it){
			r += H[it];
			up(r - H[it]+1, l+H[it]-1);
			l += H[it];
		}
	}
	cout<<root->val();
}

