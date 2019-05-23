#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef pair<ll,ll> pii;
typedef vector<pi> vpi;
typedef set<ll> si;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define f first
#define s second
ll INF = 1e15;
ll MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (ll)x.size()
#define ALL(x) x.begin(),x.end()

ll profMat[110][110], D[110][110], aMat[110][110];
pi costs[110][1010];
ll N,E,P,a,b,c;

bool query(ll cost){
	// cout<<"Checking " << cost<<'\n';
	for (int i=0;i<N;++i){
		for (int j=0;j<N;++j){
			if (D[i][j]!=-1){
				aMat[i][j] = -(profMat[i][j] - cost * D[i][j]);
			}else aMat[i][j] = INF;
			// cout<<aMat[i][j]<<' ';
		}
		// cout<<'\n';
	}

	for (int k=0;k<N;++k){
		for (int i=0;i<N;++i){
			for (int j=0;j<N;++j){
				if (aMat[i][k] == INF || aMat[k][j] == INF)continue;
				if (aMat[i][j] == INF || aMat[i][j] > aMat[i][k] + aMat[k][j]){
					aMat[i][j] = aMat[i][k] + aMat[k][j];
				}
			}
		}
	}

	for (int i=0;i<N;++i){
		if (aMat[i][i] <= 0)return 1;
	}
	// for (int i=0;i<N;++i)for (int j=0;j<N;++j)if (aMat[i][j] + aMat[j][i] <= 0)return 1;
	return 0;
}

int main(){
	// freopen("in.txt","r",stdin);
	cin >> N >> E >> P;
	for (int i=0;i<N;++i){
		for (int j=0;j<P;++j){
			cin >> costs[i][j].f >> costs[i][j].s;
		}
	}
	for (int i=0;i<N;++i){
		for (int j=0;j<N;++j){
			ll mp = 0;
			for (int k=0;k<P;++k){
				if (costs[j][k].s == -1 ||costs[i][k].f == -1)continue;
				mp = max(mp, costs[j][k].s - costs[i][k].f);
			}
			profMat[i][j] = mp;
			// cout<<profMat[i][j]<<' ';
		}
		// cout<<'\n';
	}

	memset(D,-1,sizeof(D));
	for (int i=0;i<E;++i){
		cin >> a >> b >> c;
		--a;--b;
		D[a][b] = c;
	}
	for (int k=0;k<N;++k){
		for (int i=0;i<N;++i){
			for (int j=0;j<N;++j){
				if (D[i][k] == -1 || D[k][j] == -1)continue;
				if (D[i][j] == -1 || D[i][j] > D[i][k] + D[k][j]){
					D[i][j] = D[i][k] + D[k][j];
				}
			}
		}
	}
	// for (int i=0;i<N;++i){for (int j=0;j<N;++j)cout<<D[i][j]<< ' ';cout<<'\n';}
	// for (int i=0;i<N;++i){
	// 	for (int j=0;j<N;++j)cout<<D[i][j]<<' ';cout<<'\n';
	// }
	// return 0;
	ll llb = 0;
	ll upb = 1e9;
	// for (int i=0;i<20;++i)cout<<query(i)<<'\n';
	// return 0;
	while(upb > llb+1){
		ll mid = (upb+llb)/2;
		bool opt = query(mid);
		if (opt)llb = mid;
		else upb = mid-1;
	}
	// cout<<llb<<' '<<upb<<'\n';
	if (query(upb))llb = upb;
	cout<<llb;
}