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
ll MOD = 10e9+7;
#define lb lower_bound
#define ub upper_bound
#define dst distance
#define INF 1000000000

struct edge {
    ll a, b, w;
    edge (ll _a=0, ll _b=0, ll _w=0): a(_a), b(_b), w(_w) {}
};
int p[50001];
int par(int x) { return (x==p[x])?x:p[x]=par(p[x]);}
void merge(pi a) {p[par(a.f)] = par(a.s);}
vector<edge> edgeList;
bool cmp (edge x, edge y) { return x.w < y.w; } //Swap the comparator for maximum
set<int> S;
bool equal(pi a, pi b){
	assert(a.f != a.s);
	assert(b.f != b.s);
	if (a.f == b.s && a.s == b.f)return 1;
	if (a.s == b.s && a.f == b.f)return 1;
	return 0;
}

bool trip(pi a, pi b, pi c){
	S.clear();
	S.insert(a.f);
	S.insert(a.s);
	S.insert(b.f);
	S.insert(b.s);
	S.insert(c.f);
	S.insert(c.s);
	return S.size() == 3;
}

vpi cur;
ll N,E,a,b,w,wgt;
ll ans;

void run(){
	if (cur.size() == 0)return;
	//cout << "Running with " << cur.size() << '\n';
	if (cur.size() == 1){
		merge(cur[0]);
		wgt += w;
	}else if(cur.size() == 2){
		//cout << "G\n";
		if (equal(cur[0], cur[1])){
			merge(cur[0]);
			ans = (ans*2) % MOD;
			wgt += w;
		}else{
			merge(cur[0]);
			merge(cur[1]);
			wgt += 2*w;
		}
	}else if (cur.size() == 3){
		if (equal(cur[0], cur[1])){
			if (equal(cur[0],cur[2])){
				// cout << "A\n";
				// All 3 equal
				merge(cur[0]);
				ans = (ans*3)%MOD;
				wgt += w;
			}else{
				//cout << "B\n";
				// 0,1 equal
				merge(cur[0]);
				merge(cur[2]);
				ans = (ans*2) % MOD;
				wgt += 2*w;
			}
		}else if (equal(cur[0], cur[2])){
			// 0, 2 equal
			//cout << "C\n";
			merge(cur[0]);
			merge(cur[1]);
			ans = (ans*2) % MOD;
			wgt += 2*w;
		}else if (equal(cur[1], cur[2])){
			// 1, 2 equal
			//cout << "D\n";
			merge(cur[0]);
			merge(cur[1]);
			ans = (ans*2) % MOD;
			wgt += 2*w;
		}else if (trip(cur[0], cur[1], cur[2])){
			//cout << "E\n";
			merge(cur[0]);
			merge(cur[1]);
			ans = (ans*3) % MOD;
			wgt += 2*w;
		}else{
			//cout << "F\n";
			merge(cur[0]);
			merge(cur[1]);
			merge(cur[2]);
			wgt += 3*w;
		}
	}
	cout << cur.size() << ' ' << ans << '\n';
	cur.clear();
	w = -1;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("input.txt","r",stdin);
	cin >> N >> E;
	for (int i = 0; i < E; ++i){
		cin >> a >> b >> w;
		edgeList.pb({a,b,w});
	}
	w = -1; ans = 1;
	for (int i = 0; i <= N; i++)p[i] = i;
	sort(edgeList.begin(), edgeList.end(), cmp);
	for(auto it : edgeList){
	    if (w == -1)w = it.w;
	    if (w != it.w){
			run();
			w = it.w;
		}
		if (par(it.a) == par(it.b)) continue;
		cur.pb(mp(par(it.a),par(it.b)));
	}
	run();
	cout << wgt << ' ' << ans;
}
