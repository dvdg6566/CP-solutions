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

int N,S,M,a,T;
vpi V;
int DP[101][1<<16];
int base, start;
string X;
stringstream ss;

int merge(int p, int b){
	for (int i = 0; i < S; ++i){
		if (!(p & (1 << i)))continue; // That element isn't part of p: ignore
		if (b & (1 << i)){
			b = b | (1 << (i+S));
		}else  b = b | (1 << i);
	}
	return b;
}

int matching(int H, int bm){
	//cout << H << ' ' << bm << '\n';
	if (bm == T)return 0;
	if (H == -1)return INF;
	if (DP[H][bm] != -1)return DP[H][bm];
	int ans = min( matching(H-1,bm), matching(H-1, merge(V[H].s, bm)) + V[H].f );
	return DP[H][bm] = ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	while(getline(cin,X)){
		ss.clear();
		ss << X;
		ss >> S >> M >> N;
		if(!N)return 0;
		base = 0;
		start = 0;
		V.clear();
		for (int i = 0; i <= N; ++i){
			for (int j = 0; j <= (1 << 2*S); ++j){
				DP[i][j] = -1;
			}
		}
		for (int i = 0; i < M; ++i){
			ss.clear();
			getline(cin,X);
			int C = 0;
			for (auto j : X)if(j==' ')C++;
			if(X[X.length()-1] == ' ')C--;
			ss << X;
			ss >> a;
			base += a;
			//cout << a << ' ';
			for (int j = 0; j < C; ++j){
				ss >> a;
				start = merge(1 << (a-1),start);
			}
			//cout << start << '\n';
		}
		//cout << '\n';
		//cout << start << '\n';
		T = (1 << 2*S) - 1;
		//cout << S << ' ' << T << '\n';
		for (int i = 0; i < N; ++i){
			getline(cin,X);
			int C = 0;
			for (auto j : X)if(j==' ')C++;
			if(X[X.length()-1] == ' ')C--;
			ss.clear();
			ss << X;
			ss >> a;
			V.pb(mp(a,0));
			for (int j = 0; j < C; ++j){
				ss >> a;
				V.back().s = merge((1 << (a-1)),V.back().s);
			}
			//cout << V.back().f << ' ' << V.back().s << '\n';
		}
		//cout << matching(N-1,start)+base << '\n';
	}
}
