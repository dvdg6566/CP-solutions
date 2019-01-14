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
#define MOD 1000000007LL
#define lb lower_bound
#define ub upper_bound
#define dst distance
#define INF 1000000000

int N,a;
ll fw[100100], D[100100];

void update(ll x, ll v) {
    for (; x<=N; x+=x&(-x)) {fw[x] += v;fw[x] %= MOD;} 
}

ll sum(ll x) {
    ll res = 0;
    for(; x; x-=x&(-x)) {res += fw[x]; res%=MOD;}
    return res;
}
ll res;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("input.txt","r",stdin);
	cin >> N;
	for (int i = 0; i < 2*N; ++i){
		cin >> a;
		res = ((res + sum(a)) %MOD + sum(a+N))%MOD;
		update(a,1);
		update(a+N,1);
	}
	cout << res;
}

