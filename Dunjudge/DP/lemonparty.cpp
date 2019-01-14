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

int DP[15],NXT[15];
int N,a,K,tot;
ll ans;

int cmd(int x){
	if (x < 0)return x+K;
	return x%K;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin); 
	cin >> N >> K;
	for (int i = 0; i < N; ++i){
		cin >> a;
		a %= K;
		tot = cmd(tot+a);
		DP[cmd(a-tot)] ++;
		//cout << "Added to " << cmd(a-tot) << '\n';
		ans += DP[cmd(-tot)];
		//cout << "Added " << DP[cmd(-tot)] << " from " << cmd(-tot) << '\n';
	}
	cout << ans;
}
