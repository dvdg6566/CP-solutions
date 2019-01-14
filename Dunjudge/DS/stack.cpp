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

ll fw[6001000],Q[3001000],W[3001000],ind[3001000];
bool cmp[3001000];
int N,M,a,T;
ll res;

void update(ll x, ll v) {
    for (; x<=(N+M); x+=x&(-x)) fw[x] += v; 
}

ll sum(ll x) {
    ll res = 0;
    for(; x; x-=x&(-x)) res += fw[x];
    return res;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> N >> M;
	for (int i = 1; i <= N; ++i)cin >> W[i];
	for (int i = 0; i < M; ++i){
		cin >> Q[i];
	}
	T=N;
	for (int i = 0; i < M; ++i){
		if (cmp[Q[i]])continue;
		update(T,W[Q[i]]);
		cmp[Q[i]] = 1;
		ind[Q[i]] = T;
		--T;
		if (!T)break;
	}
	T = N;
	for (int i = 0; i < M; ++i){
		int it = ind[Q[i]];
		int w = W[Q[i]];
		if (it == T)continue;
		//cout << it << ' ' << w << '\n';
		res += (sum(T) - sum(it));
		update(it,-w);
		++T;
		update(T,w);
		ind[Q[i]] = T;
	}
	cout << res;
}
