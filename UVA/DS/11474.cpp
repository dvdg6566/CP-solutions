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

int p[200];
int par(int x) { return (x==p[x])?x:p[x]=par(p[x]);}
void merge(int a, int b) {p[par(a)] = par(b);}
vpi points[120];
int N,M,K,D,T,a,b,w;

dl dist(pi a, pi b){
	dl x = a.f, y = a.s, w = b.f, z = b.s;
	return sqrt((x-w)*(x-w)+(y-z)*(y-z));
}

bool isConnected(int i, int j){
	for (auto it : points[i]){
		for (auto jt : points[j]){
			dl X = dist(it,jt);
			if(i==0||j==0){
				if(X <= D)return 1;
			}
			else{
				if(X <= K)return 1;
			}
		}
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin>>T;
	while(T--){
		cin >> N >> M >> K >> D;
		for (int i = 0; i < N+3; ++i){
			points[i].clear();
			p[i] = i;
		}
		while(M--){
			cin>>a>>b;
			points[0].pb(mp(a,b));
		}
		for (int i = 1; i <= N; ++i){
			cin >> w;
			while(w--){
				cin >> a >> b;
				points[i].pb(mp(a,b));
			}
		}
		for (int i = 0; i <= N; ++i){
			for (int j = 0; j < i; ++j){
				if(isConnected(i,j))merge(i,j);
				if(par(0) == par(1))break;
			}
			if(par(0)==par(1))break;
		}
		if(par(0)==par(1)){
			cout << "Tree can be saved :)\n";
		}else{
			cout << "Tree can't be saved :(\n";
		}
	}
}
