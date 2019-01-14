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

int fw[1001000],A[1001000];
int N,M,a,b;

void update(ll x, ll y, ll v) { // incluse
	x--;
	for(; y; y-=y&(-y)) fw[y] += v;
	for(; x; x-=x&(-x)) fw[x] -= v;
}

ll query(ll x) {
    ll res = 0;
    for (; x<=N; x+=x&(-x)) res += fw[x];
    return res;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> N >> M;
	for (int i = 0; i < M; ++i){
		cin >> a >> b;
		update(a,b,1);
	}
	for (int i = 1; i <= N; ++i)A[i] = query(i);
	sort(A,A+N);
	cout << A[N/2];
}
