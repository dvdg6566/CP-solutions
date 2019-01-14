#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MOD 1e9+7
#define lb lower_bound
#define ub upper_bound
#define dst distance
#define INF 100000000

ll TC,T;
ll a,b,c,N,E,C;
stringstream ss;
string X;
vector <pair<ll,ll>> V;

ll DP[13][1<<13];
ll adjMat[52][52], D[13][13];

ll tsp(ll pos, ll bm){
	if(bm == T)return D[pos][0]; // Return to start location if ur done
	if (DP[pos][bm] != -1) return DP[pos][bm];
	ll ans = INF;
	for (ll i = 0; i < C; ++i){
		if(bm & (1 << i))continue;
		ans = min(ans,D[pos][i] + tsp(i, bm | (1<<i)));
	}
	return DP[pos][bm] = ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> TC;
	while (TC--){
		cin >> N >> E;
		++N;
		memset(adjMat,-1,sizeof(adjMat));
		for (ll i = 0; i < N; ++i)adjMat[i][i] = 0;
		for (ll i = 0; i < E; ++i){
			cin >> a >> b >> X;
			if(a == b)continue;
			string t;
			bool bb = 0;
			for (auto i : X){
				if(i != '.'){
					t += i;
				}else bb = 1;
			}
			if(!bb)t  = t + "00";
			ss.clear();
			ss << t;
			ss >> c;
			if(adjMat[a][b] != -1)adjMat[a][b] = adjMat[b][a] = min(adjMat[a][b],c);
			else adjMat[a][b] = adjMat[b][a] = c;
		}
		for (ll k = 0; k < N; ++k) {
			for (ll i = 0; i < N; ++i) {
				for (ll j = 0; j < N; ++j) {
					if (adjMat[i][k] == -1 || adjMat[k][j] == -1) continue;
					if (adjMat[i][j] == -1 || adjMat[i][j] > adjMat[i][k] + adjMat[k][j]) 
						adjMat[i][j] = adjMat[i][k] + adjMat[k][j];
				}
			}
		}
		V.clear();
		cin >> C;
		V.pb(mp(0,0));
		for (ll i = 0; i < C; ++i){
			cin >> a >> X;
			string t;
			bool bb = 0;
			for (auto i : X){
				if(i != '.'){
					t += i;
				}else bb = 1;
			}
			if(!bb)t  = t + "00";
			ss.clear();
			ss << t;
			ss >> c;
			V.pb(mp(a,c));
			
		}
		++C;
		for (ll i = 0; i < C; ++i){
			for (ll j = 0; j < C; ++j){
				D[i][j] = adjMat[V[i].f][V[j].f];
			}
		}
		memset(DP,-1,sizeof(DP));
		T = (1 << C) -1;
		ll ans = 0;
		for (ll bm = 0; bm <= T; ++bm){
			ll cur = 0;
			for (ll i = 0; i < C; ++i){
				if (bm & (1<<i))continue;
				cur += V[i].s;
			}
			ans = max(ans,cur-tsp(0,bm));
		}
		if (ans > 0) {
			if(ans%100 > 9)printf("Daniel can save $%lld.%lld\n",ans/100,ans%100);
			else printf("Daniel can save $%lld.0%lld\n",ans/100,ans%100); 
		}
		else cout << "Don't leave the house\n";
	}
}
