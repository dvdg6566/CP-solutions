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
#define TOP 5000001

int DP[TOP], seive[TOP],a,b;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	seive[0] = seive[1] = 1;
	for (int i = 0; i < TOP; ++i){
		if (seive[i])continue;
		for (int j = i; j < TOP; j += i)seive[j] += i;
	}
	for (int i = 0; i < TOP; ++i){
		if (seive[i] == seive[seive[i]] && seive[i]!=1)DP[i] = 1;
		if(i)DP[i] += DP[i-1];
	}
	while(cin>>a){
		if(!a)return 0;cin>>b;
		cout << DP[b] - DP[a-1] << '\n';
	}
}
