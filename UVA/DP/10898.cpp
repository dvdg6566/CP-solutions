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

int N,C,Q,a,t;
int I[7];
int combo[11][11];
int DP[2000000];
int M[] = {1,11,121,1331,14641,161051,2000000};

int matching(int bm){
	if(bm == 0)return DP[bm] = 0;
	if(DP[bm] != -1)return DP[bm];
	int ans = INF;
	for (int i = 0; i < C; ++i){
		bool b = 1;
		int nxt = 0;
		for (int j = 0; j < N; ++j){
			int X = ( bm%M[j+1] )  /M[j];
			if ( X < combo[i][j] ){
				b = 0; 
				break; 
			}// Cannot afford that combo
			nxt += ((X-combo[i][j]) * M[j]);
		}
		if(b)ans = min(ans,matching(nxt) + combo[i][N] );
	}
	if(ans == INF){
		ans = 0;
		for (int j = 0; j < N; ++j){
			int X = (bm%M[j+1]) / M[j];
			ans +=  ( X * I[j] );
		}
	}
	return DP[bm] = ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	while(cin >> N){
		if(cin.eof())return 0;
		for (int i = 0; i < N; ++i)cin >> I[i];
		cin >> C;
		for (int i = 0; i < C; ++i){
			for (int j = 0; j <= N; ++j){
				cin >> combo[i][j];
			}
		}
		memset(DP,-1,sizeof(DP));
		cin >> Q;
		while(Q--){
			t = 0;
			for (int i = 0; i < N; ++i){
				cin >> a;
				t += a*M[i];
			}
			cout << matching(t) << '\n';
		}
	}
}
