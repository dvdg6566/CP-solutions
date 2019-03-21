#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<int,int> pi;
typedef pair<int,pi> pii;
typedef vector<pi> vpi;
typedef set<int> si;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define f first
#define s second
ll INF = 1e9;
ll MOD = 1e9;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()

vpi des;
int A[100100];
int N,ans;

struct node{
	int s,e,m,v;
	node *l, *r;
	node (int _s, int _e){
		s=_s;e=_e;m=(s+e)/2;v = 0;
		if (s != e){
			l = new node(s,m);
			r = new node(m+1,e);
		}
	}
	
	void update(int x, int val){
		if (s == e){v = val;return;}
		if (x <= m)l->update(x,val);
		if (x > m)r->update(x,val);
		v = max(l->v, r->v);
	}
	
	int query(int a, int b){
		assert( a >= s && e >= b);
		if (a == s && b == e)return v;
		if (a > m)return r->query(a,b);
		if (b <= m)return l->query(a,b);
		return max(l->query(a,m), r->query(m+1,b));
	}
}*root;

int main(){
	//freopen("input.txt","r",stdin);
	cin>>N;
	for (int i=0;i<N;++i){
		cin>>A[i];
		des.pb(mp(A[i], i));
	}
	sort(ALL(des));
	root = new node(0,N);
	for (int i=0;i<N;++i){
		A[des[i].s] = i;
	}
	for (int i=0;i<N;++i){
		int x = root->query(0, A[i]) + 1;
 		ans = max(ans,x);
		root->update(A[i], x);
	}
	cout<<ans;
}
