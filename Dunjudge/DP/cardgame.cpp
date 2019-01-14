#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<int,int> pi;
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

int DP[3010][3010];
int A[3010];
int K,L,N,ans;
deque<pi> dq;

void add(pi x){
	//cout << x.f << ' ' << x.s << '\n';
	// Remove from the front
	if (dq.size())if (dq[0].f <= x.f - L)dq.pop_front();
	while (dq.size()){
		if (dq.back().s <= x.s)dq.pop_back();
		else break;
	}
	dq.pb(x);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> N >> K >> L;
	for (int i = 1; i <= N; ++i)cin>>A[i];
	for (int i = 1; i <= N; ++i)A[i] += A[i-1];
	for (int k = 1; k <= K; ++k){
		dq.clear();
		add(mp(0, DP[0][k-1]));
		for (int i = 1; i <= N; ++i){
			DP[i][k] = DP[i][k] = max(DP[i-1][k], DP[i][k-1]);
			/*
			for (int j = max(i-L,0); j < i; ++j){
				DP[i][k] = max(DP[i][k], DP[j][k-1] + A[i] - A[j]);
			}
			*/
			if(dq.size())DP[i][k] = max(DP[i][k], dq[0].s + A[i]);
			add(mp(i, DP[i][k-1] - A[i]));
			ans = max(DP[i][k], ans);
			//cout << DP[i][k] << ' ';
		}
		//cout << '\n';
	}
	cout << ans;
}
