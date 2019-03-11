#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef vector<ll> vi;
typedef vector<pi> vpi;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define SZ(x) (int)x.size()
#define ALL(x) (x).begin(),(x).end()

ll fw[1001000][2];
vpi des;
ll A[1001000];
map<ll,ll> M;
ll N,T,ans;

void update(ll x, ll v, ll rnk){
	//cout<<"At " << rnk << ", update " << x << " with " << v << '\n';
	for (;x<=T;x += x&(-x))fw[x][rnk] += v;
}

ll sum(ll x, ll rnk){
	ll res = 0;
	for (;x;x -= x&(-x))res += fw[x][rnk];
	return res;
}

ll query(ll x, ll y, ll rnk){
	return sum(y,rnk) - sum(x, rnk);
}

inline int RI() {
    int x = 0;
    char ch = getchar_unlocked();
    while (ch < '0' || ch > '9') ch = getchar_unlocked();
    while (ch >= '0' && ch <= '9'){
		x = (x << 3) + (x << 1) + ch - '0';
		ch = getchar_unlocked();
	}
    return x;
}

int __attribute__((optimise("03"),target("arch=sandybridge"))) main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("in.txt","r",stdin);
	N = RI();
	for (int i=1;i<=N;++i){
		A[i]  = RI();
		des.pb(mp(A[i], i));
	}
	sort(ALL(des));
	T = SZ(des);
	int cur = -10000, ind = 0;
	for (int i=0;i<N;++i){
		if (des[i].f != cur){
			++ind;
			cur = des[i].f;
		}
		A[des[i].s] = ind;
	}
	
	for (int i=1;i<=N;++i){
		ll t = query(A[i],T,0);
		ll t2 = query(A[i],T,1);
		ans += t2;
		update(A[i],t,1);
		update(A[i],1,0);
	}
	cout<<ans<<'\n';
}