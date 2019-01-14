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
#define MOD 1000000007LL
#define lb lower_bound
#define ub upper_bound
#define dst distance
#define INF 1000000000

int M[5][5],T,a,b;
vi adjList[30];
int dx[]  = {1,-1,0,0};
int dy[] = {0,0,1,-1};
ll MAXN;
map<ll,ll> memo[30];

ll query(ll bm, int cur){
	if (bm == MAXN && cur == T){return 1;}
	if (bm == MAXN && cur == T)return -1;
	if (memo[cur][bm] != 0)return memo[cur][bm];
	bm = bm | (1 << cur);
	ll ans = 0;
	for (auto i : adjList[cur]){
		if (bm & (1 << i))continue;
		ll x = query(bm,i);
		if (x != -1)ans += x;
	}
	//cout << bm << ' ' << cur << ' ' << ans << '\n';
	return memo[cur][bm] = ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> T;
	for (int i = 0; i < T; ++i){
		cin >> a >> b;
		M[a-1][b-1] = -1;
	}
	T = 0;
	for (int i = 0; i < 5; ++i){
		for (int j = 0; j < 5; ++j){
			if (M[i][j] == -1)continue;
			M[i][j] = T;
			++T;
		}
	}
	for (int i = 0; i < 5; ++i){
		for (int j = 0; j < 5; ++j){
			if (M[i][j] == -1)continue;
			if (i+j ==8)continue;
			for (int k = 0; k < 4; ++k){
				int cx = i+dx[k];
				int cy = j+dy[k];
				if (cx < 0 || cy < 0 || cx > 4 || cy > 4)continue;
				if (M[cx][cy] == -1)continue;
				adjList[M[i][j]].pb(M[cx][cy]);
			}
		}
	}
	--T;
	MAXN = (1 << T)-1;
	cout << query(0,0) << '\n';
	return 0;
	for (int i = 0; i < 5; ++i){
		for (int j = 0; j < 5; ++j){
			cout << M[i][j] << ' ';
		}
		cout << '\n';
	}
	for (int  i = 0; i < 24; ++i){
		cout << i << ' ';
		for (auto j : adjList[i])cout << j << ' ';
		cout << '\n';
	}
}
