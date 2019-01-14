#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<int,int> pi;
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

string X;
int N,x,y,T,C=1;
vpi V;
double dist[17][17], DP[1<<16];

double matching(int bm){
	if (bm == T)return DP[bm] = 0;
	if(DP[bm] != -1)return DP[bm];
	double ans = INF;
	int p1,p2;
	for (p1 = 0; p1 < 2*N; ++p1){
		if(!(bm & (1 << p1)))break; //p1 becomes the first bit that is of
	}
	for (p2 = p1+1; p2 < 2*N; ++p2){
		if(bm & (1<<p2))continue;
		ans = min(ans, dist[p1][p2] + matching(bm | (1<< p1) | (1 << p2)));
	}
	return DP[bm] = ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	while(cin >> N){
		if(!N)return 0;
		V.clear();
		for (int i = 0; i < 2*N; ++i){cin >> X >> x >> y; V.pb(mp(x,y));}
		for (int i = 0; i < 2*N-1; ++i){
			for (int j = i; j < 2*N; ++j){
				dist[i][j] = dist[j][i] = hypot(V[i].f - V[j].f, V[i].s - V[j].s);
			}
		}
		T = (1<<(2*N)) - 1;
		for (int i = 0; i <= T; ++i)DP[i] = -1;
		printf("Case %d: %.2lf\n",C++,matching(0));
	}
}
