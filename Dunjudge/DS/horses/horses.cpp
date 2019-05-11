#include "horses.h"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef pair<ll,ll> pii;
typedef vector<pi> vpi;
typedef set<ll> si;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define f first
#define s second
ll INF = 1e9;
ll MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (ll)x.size()
#define ALL(x) x.begin(),x.end()

ll mod(ll a, ll m){
	return (a+m)%m;
}

ll inverse(ll a, ll m){
	a = mod(a,m);
	if(a<=1)return a;
	return mod((1-inverse(m,a)*m)/a, m);
}

ll prod, cur;
ll X[500100], Y[500100];
set<ll> nonones;
ll p = -1,N;

struct node{
	int s,e,m,v;
	node *l, *r;
	node(int _s, int _e):s(_s), e(_e){
		m = (s+e)/2;
		if (s != e){
			l = new node(s,m);
			r = new node(m+1,e);
			v = max(l->v,r->v);
		}else{
			v = Y[s];
		}
	}

	void update(int p, int val){
		if (s == e){v = val;return;}
		else if (p <= m)l->update(p,val);
		else r->update(p,val);
		v = max(l->v, r->v);
	}

	ll query(int a, int b){
		if (a == s && b == e)return v;
		if (a > m)return r->query(a,b);
		if (b <= m)return l->query(a,b);
		return max(l->query(a,m), r->query(m+1,b));
	}
}*root;

ll res(){
	if (SZ(nonones) == 0){
		return root->query(0,N);
	}
	ll mult = 1;
	ll ans = 0;
	auto start = (--nonones.end());
	// cerr<<*start<<'\n';
	bool full = 1;


	for (; start != nonones.begin();--start){
		// cerr <<"Visiting " << *start<<'\n';
		int t = *start;
		if (mult*X[t] >= 1e9){
			ans = max(ans, root->query(t, N));
			++start;
			full = 0;
			break;
		}
		mult *= X[t];
	}
	// cout<<*start<<'\n';
	if (full){
		ll t = *start;
		if (mult < 1e9 && mult*X[t] < 1e9){
			mult *= X[t];
		}
		else {
			ans = max(ans, root->query(t, N));
			++start;
		}
	}


	// cout<<"Start " <<*start<<'\n';
	// cout<<"MULT " << mult<<'\n';
	cur = (prod * inverse(mult,MOD))%MOD;
	if (cur == 1){
		ans = max(ans, root->query(0,N));
	}
	// cout<<"Current Multiplier " << cur << '\n';
	mult = 1;

	for (;start!=nonones.end();++start){
		int i = *start;
		mult *= X[i];
		// assert(mult<1e9);
		// cout <<i<<' '<< mult << ' '<<root->query(i,N) <<'\n';
		ans = max(ans, mult * root->query(i, N));
	}
	return (ans%MOD * cur)%MOD;
}

int init(int _N, int _X[], int _Y[]) {
	N = _N;
	prod = 1;
	for (int i=0;i<N;++i){
		X[i] = _X[i];
		Y[i] = _Y[i];
		prod = (prod * X[i])%MOD;
	}

	for (int i=0;i<N;++i)if (X[i] != 1)nonones.insert(i);

	root = new node(0, N);
	return res();
}

int updateX(int pos, int val) {
	if (val == 1 && X[pos] != 1){
		nonones.erase(pos);
	}
	else if (val != 1 && X[pos] == 1){
		nonones.insert(pos);
	}
	prod = (prod * inverse(X[pos], MOD)) % MOD;
	prod = (prod * val)%MOD;
	X[pos] = val;
	return res();
}

int updateY(int pos, int val) {
	root->update(pos,val);
	Y[pos] = val;
	return res();
}
