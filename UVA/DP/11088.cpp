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

int D[16],N,C=1,T;
int DP[1<<16];

int matching(int bm){
	if(bm==T)return DP[bm] = 0;
	if(DP[bm]!=-1)return DP[bm];
	int ans = 0;
	int p1,p2,p3;
	for (p1 = 0; p1 < N; ++p1){
		if(!(bm & (1 << p1)))break; //p1 becomes the first bit that is of
	}
	for (p2 = p1+1; p2 < N; ++p2){
		if(bm & (1<<p2))continue;
		for (p3 = p2+1; p3 < N; ++p3){
			if(bm&(1<<p3))continue;
			int w = matching(bm | (1<< p1) | (1 << p2) | (1<<p3));
			if (D[p1] + D[p2] + D[p3] >= 20)++w;
			ans = max(ans, w);
		}
	}
	return DP[bm] = ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	while(cin >> N){
		if(!N)return 0;
		for (int i = 0; i < N; ++i)cin >> D[i];
		for (int i = 0; i < (1<<N); ++i)DP[i] = -1;
		T = (1<<N)-1;
		printf("Case %d: %d\n",C++,matching(0));
	}
}
