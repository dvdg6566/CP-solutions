#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;

#define pb push_back
#define mp make_pair
#define f first 
#define s second
#define SZ(x) x.size()
#define ALL(X) x.begin(), x.end()

struct node{
	int s,e,lazy,m,lengthopen;
	node *l, *r;
	node(int _s, int _e){
		s = _s; e = _e; m = (s+e)/2;lazy = 0;lengthopen = e-s+1;
		if(s != e){
			l = new node(s,m);
			r = new node(m+1, e);
		}
	}
	
	void update(int a, int b, int val){
		if(lazy)return;
		if (s == e && a == b){
			lengthopen = 0;
			if(lazy == 0)lazy = val;
			return;
		}
		if (m < a) r->update(a,b,val);
		else if (m >= b) l->update(a,b,val);
		else {l->update(a,m, val);r->update(m+1, b,val);}
		lengthopen = l->lengthopen + r->lengthopen;
		if(l->lazy&&r->lazy)lazy = 1;
	}
	
	int query_distance(int a, int b){
		if (s == a && e == b)return lengthopen;
		if (m < a)return r->query_distance(a,b);
		if (m >= b)return l->query_distance(a,b);
		return l->query_distance(a,m) + r->query_distance(m+1, b);
	}
	
	int query_val(int a){
		if (s == e)return lazy;
		val();
		if (a <= m)return l->query_val(a);
		return r->query_val(a);
	}
	
	void val(){
		if (s == e)return;
		if (l->lazy == 0)l->lazy = lazy;
		if (r->lazy == 0)r->lazy = lazy;
		return;
	}
}*root;

vpi edgeList;
vi aList[300100];
int N,E,a,b;
int p[300100], depth[300100], heavy[300100], head[300100], pos[300100];
int cur, used;

int dfs(int x){
	int size = 1;int mchild = 0;
	for (auto i : aList[x]){
		if (i == p[x])continue;
		p[i] = x;
		depth[i] = depth[x] +1;
		int cs = dfs(i);
		size += cs;
		if (cs > mchild){
			mchild = cs;
			heavy[x] = i;
		}
	}
	return size;
}

void decompose(int x, int h){
	head[x] = h; pos[x] = cur++;
	if (heavy[x] != -1)decompose(heavy[x], h);
	for (auto i : aList[x]){
		if (i == p[x])continue;
		if (i == heavy[x])continue;
		decompose(i,i);
	}
}

bool want[300100];
int prop[300100], ans[300100];

void query_distance(int a, int b){
	int l = 0;
	//cerr<<"Find Distance "<<a<<' '<<b<<'\n';
	if (depth[a] > depth[b])swap(a,b);
	for (;head[a]!=head[b]; b = p[head[b]]){
		if (depth[head[a]] > depth[head[b]])swap(a,b);
		l += root->query_distance(pos[head[b]], pos[b]);
		root->update(pos[head[b]], pos[b], cur);
		//cout<<"Update " << pos[head[b]]<<' '<<pos[b]<<' '<<cur<<'\n';
	}
	if (depth[a] > depth[b])swap(a,b);
	if (a != b){
		l += root->query_distance(pos[a]+1, pos[b]);
		root->update(pos[a] + 1, pos[b], cur);
		//cout<<"Update " << pos[a]+1<<' '<<pos[b]<<' '<<cur<<'\n';
	}
	//cout<<l<<'\n';
	prop[cur] = used;
	used += l; cur++;
	//cout<<cur<<' '<<used<<'\n';
}

int main(){
	//freopen("in.2.txt","r",stdin);
	cin >> N >> E;
	root = new node(1,N);
	for (int i=0;i<E;++i){
		cin>>a>>b;
		edgeList.pb(mp(a,b));
	}
	for (int i=1;i<N;++i){
		cin >> a;
		--a;
		int x = edgeList[a].f;
		int y = edgeList[a].s;
		want[a] = 1;
		aList[x].pb(y);
		aList[y].pb(x);
	}

	memset(heavy,-1,sizeof(heavy));
	cur = 1; dfs(1); decompose(1,1);
	cur = 1; used = 1;
	//for (int i=1;i<=N;++i)cout<<pos[i]<<' ';

	for (int i=0;i<E;++i){
		if (want[i]){
			a = edgeList[i].f, b = edgeList[i].s;
			int x,y;
			if (pos[a] > pos[b])x = pos[a];
			else x = pos[b];
			y = root->query_val(x);
			if (y == 0){
				ans[i] = used;
				root ->update(x,x,used++);
			}else{
				ans[i] = prop[y]++;
			}
		}else{
			query_distance(edgeList[i].f, edgeList[i].s);
			ans[i] = used++;
		}
	}
	for (int i=0;i<E;++i)cout<<ans[i]<<' ';
}


