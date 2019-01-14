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

ll A[2010],DP[2010];
ll N;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> N;
	for (int i = 0; i < N; ++i){
		cin >> A[i];
	}
	DP[0] = 1;
	for (int i = 1; i < N; ++i){
		DP[i] = 1;
		for (int j = 0; j < i; ++j){
			if(A[i]&A[j])continue;
			DP[i] = max(DP[i],DP[j] + 1);
		}
	}
	cout << *max_element(DP,DP+N);
}
