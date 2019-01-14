include<bits/stdc++.h>
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

ll C[1010][8], P[1010][8]; // OTF DP
ll N,K,res;
ll G[1010][3];

ll tx[] = {0,1,2,3,4,5,6,7,1,4,0,0,3,6};
ll ty[] = {0,1,2,3,4,5,6,7,7,7,3,6,0,0};
ll dm[] = {0,1,1,2,1,2,2,3,2,2,1,1,1,1};

ll mapBmToVal(ll R, ll bm){
	if (bm == 0)return 0;
	if (bm == 1)return G[R][0];
	if (bm == 2)return G[R][1];
	if (bm == 3)return G[R][0] + G[R][1];
	if (bm == 4)return G[R][2];
	if (bm == 5)return G[R][0] + G[R][2];
	if (bm == 6)return G[R][1] + G[R][2];
	if (bm == 7)return G[R][0] + G[R][1] + G[R][2];
	return -INF;
}

bool intersect(ll a, ll b){
	if ((a%2) && (b%2))return 1;
	if (((a%4) >= 2) && ((b%4) >= 2))return 1;
	if ((a >= 4) && (b >= 4)) return 1;
	return 0;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> N >> K;
	for (ll i = 0; i < N; ++i)cin >> G[i][0] >> G[i][1] >> G[i][2];
	for (ll i = 0; i <= K; ++i){
		for (ll j = 0; j < 8; ++j){
			P[i][j] = -INF;
			C[i][j] = -INF;
		}
	}
	
	P[0][0] = C[0][0] = 0;
	P[1][3] = C[1][3] = mapBmToVal(0,3);
	P[1][6] = C[1][6] = mapBmToVal(0,6);

	for (ll i = 1; i < N; ++i){
		for (ll j = 1; j <= K; ++j){
			for (ll c = 0; c < 14; ++c){
				if (j < dm[c])continue;
				// c is the configuration
				for (ll k = 0; k < 8; ++k){
					if (intersect(tx[c],k))continue; // Addditional configuration intersects old one then ignore
					if(P[j-dm[c]][k] == -INF)continue;
					ll wgt = mapBmToVal(i,ty[c]) + mapBmToVal(i-1,tx[c]);
					//cout << wgt << ' ' << P[j-dm[c]][k] << '\n';
					C[j][ty[c]] = max(C[j][ty[c]], wgt + P[j-dm[c]][k]);
					if(j == K)res = max(res,C[j][ty[c]]);
				}
			}
		}
		for (ll j = 1; j <= K; ++j){
			for (ll k = 0; k < 8; ++k){
				P[j][k] = max(P[j][k],C[j][k]);
				//cout << P[j][k] << ' ';
			}
			//cout << '\n';
		}
		//cout << "\n\n";
	}
	cout << res;
}
