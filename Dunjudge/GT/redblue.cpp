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

int p[2001];
int N,E,H,a,b,w;
int par(int x) { return (x==p[x])?x:p[x]=par(p[x]);}
struct edge{
	int a,b,w;
	edge(int _a, int _b, int _w): a(_a), b(_b), w(_w) {}
};
vector<edge> red, blue;
vector<edge> cred, cblue;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> N >> E;
	if (N%2 == 0){
		cout << "NO";
		return 0;
	}
	for (int i = 0; i < N; i++)p[i] = i;
	H = (N-1)/2; // There should be H edges of each colour
	for (int i = 0; i < E; ++i){
		cin >> a >> b >> w;
		if (w)blue.pb({a,b,i});
		else red.pb({a,b,i});
	}
	// Step 1: Add all possible red edges, forming a red forest. Reject if too few red edges
	for (auto i : red){
		if (par(i.a) == par(i.b))continue;
		p[par(i.a)] = par(i.b);
		cred.pb(i);
	}
	//cout << cred.size() << '\n';
	if (cred.size() < H){
		cout << "NO";
		return 0;
	}
	// Step 2: Add blue edges. Reject if graph isn't connected
	for (auto i : blue){
		if (par(i.a) == par(i.b))continue;
		p[par(i.a)] = par(i.b);
		cblue.pb(i);
	}
	//cout << cblue.size() << '\n';
	if (cred.size() + cblue.size() < N-1){
		cout << "NO";
		return 0;
	}
	// Step 3: remove all red edges
	for (int i = 0; i < N; i++)p[i] = i;
	for (auto i : cblue){
		p[par(i.a)] = par(i.b);
	}
	cred.clear();
	// Step 4: Add enough blue edges
	for (auto i : blue){
		if (cblue.size() == H)break;
		if (par(i.a) == par(i.b))continue;
		p[par(i.a)] = par(i.b);
		cblue.pb(i);
	}
	//cout << cblue.size() << '\n';
	if(cblue.size() != H){
		cout << "NO";
		return 0;
	}
	// Step 5: Add all the red edges
	for (auto i : red){
		if (par(i.a) == par(i.b))continue;
		p[par(i.a)] = par(i.b);
		cred.pb(i);
	}
	//cout << cred.size() << '\n';
	if (cred.size() != H){
		cout << "NO";
		return 0;
	}
	cout << "YES\n";
	for (auto i : cblue)cout << i.w << ' ';
	for (auto i : cred)cout << i.w << ' ';
}
