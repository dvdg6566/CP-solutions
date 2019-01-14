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

string str;
int N,x,y;
int rmq[100100], dp[100100];
multiset<int> S;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> N >> x >> y >> str;
	for (int i = 1; i <= N; ++i){
		rmq[i] = (str[i-1] != '1');
		rmq[i] += rmq[i-1];
	}
	for (int i = 1; i < x; ++i){
		// First few have to all be the same
		dp[i] = dp[i-1] + (str[i-1] == '1');
		//cout << dp[i] << '\n';
	}
	if (x < y){
		for (int i = x; i < y; ++i){
			// Add and calculate but without the removal
			S.insert(dp[i-x] - rmq[i-x]);
			//cout << "Inserting " << dp[i-x] - rmq[i-x] << '\n';
			dp[i] = dp[i-1] + (str[i-1] == '1');
			//cout << "QUERY " << *(--S.end()) + rmq[i] << '\n';
			dp[i] = min(dp[i], *S.begin() + rmq[i]);
			//cout << dp[i] << '\n';
		}
	}
	if (y < N){
		for (int i = y; i <= N; ++i){
			// Erase, add and remove
			S.insert(dp[i-x] - rmq[i-x]);
			//cout << "Inserting " << dp[i-x] - rmq[i-x] << '\n';
			dp[i] = dp[i-1] + (str[i-1] == '1');
			dp[i] = min(dp[i], *S.begin() + rmq[i]);
			S.erase(S.find(dp[i-y] - rmq[i-y]));
			//cout << "Erasing " << dp[i-y] - rmq[i-y] << '\n';
			//cout << dp[i] << '\n';
		}
	}
	//cout << '\n';
	//for (int i = 1; i <= N; ++i)cout << dp[i] << '\n';
	cout << dp[N];
}
