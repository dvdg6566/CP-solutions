#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef pair<ll,pi> ppi;
typedef vector<pi> vpi;
typedef double dl;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MOD 1e9+7
#define lb lower_bound
#define ub upper_bound
#define INF 1000000000000000000

int R,C,N,a,b,c;
vpi L;
vi W;

bool works(int x, int y, ll h){
	for (int i = 0; i < N; ++i){
		if (h >= abs(x-L[i].f)+abs(y-L[i].s)+W[i])continue;
		return 0;
	}
	return 1;
}

ll bsta(int x, int y){
	ll lb = 0, ub = INF;
	while(ub>lb+1){
		ll mid = (ub+lb)/2;
		if(works(x,y,mid))ub = mid;
		else lb = mid;
	}
	if(works(x,y,lb))return lb;
	return ub;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> R >> C >> N;
	for(int i = 0; i < N; ++i){
		cin >> a >> b >> c;
		L.pb(mp(a,b));
		W.pb(c);
	}
	if(N == 2){
		if (L[0].f > L[1].f){swap(L[0],L[1]);swap(W[0],W[1]);}
		ll d = abs(L[0].f - L[1].f) + abs(L[0].s - L[1].s);
		ll H = (W[0] + W[1] + 1 + d)/2;
		cout << L[0].f + H - W[0] << " 1 " << H;
		return 0;
	}
	ll res = INF;
	pi ans = mp(-1,-1);
	for (int i = 0; i < C; ++i){
		for (int j = 0; j < R; ++j){
			ll x = bsta(i,j);
			if(x <= res){
				ans = mp(i,j);
				res = x;
			}
		}
	}
	assert(ans.f != -1);
	cout << ans.f << ' ' << ans.s << ' ' << res;
}
