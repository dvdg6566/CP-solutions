#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<int, pi> pii;
typedef set<int> si;
typedef vector<pi> vpi;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define f first
#define s second
ll MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
ll INF = 1000000000000000000;
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()

struct node{
	int s,e,m;
	ll tt,st,ts,ss;
	node *l, *r;
	node (int _s, int _e){
		s=_s;e=_e;
		m=(s+e)/2;
		tt=st=ss=ts=0;
		if (s != e){
			l = new node(s,m);
			r = new node(m+1, e);
		}
	}
	
	void update(int x, int y){
		if (s == e){
			tt = y;
			return;
		}
		if (x <= m)l -> update(x,y);
		else r-> update(x,y);
		tt = max(l->ts + r->tt, l->tt + r->st);
		ts = max(l->ts + r->ts, l->tt + r->ss);
		st = max(l->st + r->st, l-> ss + r-> tt);
		ss = max(l->ss + r->ts, l->st + r->ss);
		ts = max(ts,ss);
		st = max(st,ss);
		tt = max({tt,ts,st});
		//cout<<s<<' '<<e<<' '<<tt<<' '<<ts<<' '<<st<<' '<<ss<<'\n';
	}
}*root;

int N,Q;
int a,b;
ll ans;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin>>N>>Q;
	root = new node(0,N-1);
	for (int i=0;i<N;++i){
		cin>>a;
		root->update(i,a);
		//cout<<"\n\n";
	}
	//return 0;
	for (int i=0;i<Q;++i){
		cin>>a>>b;
		--a;
		root->update(a,b);
		ans+=root->tt;
	}
	cout<<ans;
}