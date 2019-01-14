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

int p[] = {2,60,7,588,2888};
int w[] = {1,17,2,179,809};
int N,M;
ll DP[1001000];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> N;
	for (int i = 0; i < 5; ++i){
		for (int k = 0; k < 10; ++k){
			int cost = (1 << k) * w[i];
			M += cost;
			int value = (1 << k) * p[i];
			if (cost > N)break;
			for (int j = min(M,N); j >= cost; --j){
				DP[j] = max(DP[j],DP[j-1]);
				DP[j] = max(DP[j],DP[j-cost] + value);
			}
		}
	}
	cout << DP[N];
}
