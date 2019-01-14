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
#define MAX 1000000
#define END 1000000000000

bool S[MAX+10];
vector<ll> primes,almost;
ll N,a,b;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	memset(S,1,sizeof(S));
	S[0] = S[1] = 0;
	for (int i = 0; i <= 10010; ++i){
		if(!S[i])continue;
		for (int j = i*i; j <= MAX; j += i)S[j] = 0;
	}
	for (int i = 0; i <= MAX; ++i)if(S[i])primes.pb(i);
	for (auto i : primes){
		ll t = (ll)i;
		while(t*=i){
			if(t>END)break;
			almost.pb(t);
		}
	}
	sort(almost.begin(),almost.end());
	cin >> N;
	while(N--){
		cin >> a >> b;
		cout << ub(almost.begin(),almost.end(),b) - lb(almost.begin(),almost.end(),a) << '\n';
	}
}
