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

int N,E,Q,a,b,w;
struct edge {
    int a, b, w;
    edge (int _a=0, int _b=0, int _w=0): a(_a), b(_b), w(_w) {}
};
int res[100100];
vector<edge> EdgeList;
bool cmp (edge x, edge y) { return x.w < y.w; } //Swap the comparator for maximum

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> N >> E;
	for (int i = 0; i < E; ++i){
		cin >> a >> b >> w;
		EdgeList.pb({a,b,w});
	}
	sort(EdgeList.begin(),EdgeList.end(),cmp);
	for (auto i : EdgeList){
		int t = res[i.a];
		res[i.a] = max(res[i.a],res[i.b]+1);
		res[i.b] = max(res[i.b],t+1);
		//cout << i.a << ' ' << i.b << ' ' << i.w << '\n';
	}
	//for (int i = 0; i < N; ++i)cout << res[i] << '\n';
	cout << *max_element(res,res+N);
}


