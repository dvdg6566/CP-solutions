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

ll N,T,F,a,b,w,ans;
vi adjList[1001000];
int par[1001000],vals[1001000];
bool dp[1001000];
vi out;

void rootdfs(int x){
	for (auto i : adjList[x]){
		if (par[i] != -1)continue;
		par[i] = x;
		rootdfs(i);
	}
}

pi query(int x){
	// pair is occupied, then unoccupied
	if (adjList[x].size() == 1 && x){
		dp[x] = 1;
		return mp(vals[x],0);
	}
	int a = 0, b = 0;
	for (auto i : adjList[x]){
		if (i==par[x])continue;
		pi cur = query(i);
		a += cur.s;
		b += cur.f;
	}
	a += vals[x];
	if (a > b){
		dp[x] = 1;
		//node itself is selected
	}
	return mp(max(a,b),b);
}

void inv_query(int x, bool q){
	if (q == 1)out.pb(x);
	if (adjList[x].size() == 1 && x){
		return;
	}
	for (auto i : adjList[x]){
		if (i == par[x])continue;
		if (q == 1){
			inv_query(i,0);
		}
		else{
			if(dp[i])inv_query(i,1);
			else inv_query(i,0);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("input.txt","r",stdin);
	cin >> N;
	for (int i = 1; i < N; ++i){
		cin >> a >> b;
		adjList[a].pb(b);
		adjList[b].pb(a);
	}
	for (int i = 0; i < N; ++i){
		cin >> a;
		vals[i] = a;
	}
	memset(par,-1,sizeof(par));
	memset(dp,0,sizeof(dp));
	rootdfs(0);
	par[0] = -1;
	pi res = query(0);
	cout << res.f << '\n';
	if (dp[0]){inv_query(0,1);}
	else inv_query(0,0);
	cout << out.size() << '\n';
	for (auto i : out)cout << i << ' ';
}
