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

ll N,m,x,y,r,cnt,E;
vpi V;

bool cmp(pi a, pi b){
	if (a.f != b.f)return a.f < b.f;
	return a.s > b.s;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);//freopen("input.txt","r",stdin);
	cin >> m >> N;
	for (int i = 0; i < N; i++){
		cin >> x >> y;
		V.pb(mp(max(x-y,0LL), min(x+y,m)));
	}
	sort(V.begin(),V.end(),cmp);
	for (int i = 0; i < N; ++i){
		if(E==m)break;
		if (E < V[i].f){
			cout << -1;
			return 0;
		}
		ll curmax = V[i].s;
		while (1){
			++i;
			if(i >= N)break;
			if (E < V[i].f)break;
			curmax = max(curmax,V[i].s);
		}
		E = curmax;
		++cnt;
	}
	if(E < m){cout << -1;return 0;}
	cout << cnt;
}
