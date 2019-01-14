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

ll N,T,F,a,b,w,ans;
vpi adjList[501000];
int par[501000];

void rootdfs(int x){
	for (auto i : adjList[x]){
		if (par[i.f] != -1)continue;
		par[i.f] = x;
		rootdfs(i.f);
	}
}

ll query(int x){
	vector<ll> V;
	if(adjList[x].size() <= 1 && x != 0){
		// Leaf Node
		return 0;
	}
	for (auto i : adjList[x]){
		if(i.f == par[x])continue;
		V.pb(max(0LL,i.s+max(0LL,query(i.f))));
	}
	if (!V.size()) return 0;
	sort(V.begin(),V.end());
	reverse(V.begin(),V.end());
	if (V.size() > 1)ans = max(ans,V[0]+V[1]);
	ans = max(ans,V[0]);
	return max(0LL,V[0]);
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> N >> T >> F;
	for (int i = 0; i < T; ++i){
		cin >> a >> b >> w;
		adjList[a].pb(mp(b,-w));
		adjList[b].pb(mp(a,-w));
	}
	for (int i = 0; i < F; ++i){
		cin >> a >> b >> w;
		adjList[a].pb(mp(b,w));
		adjList[b].pb(mp(a,w));
	}
	memset(par,-1,sizeof(par));
	rootdfs(0);
	par[0] = -1;
	query(0);
	cout << max(0LL,ans);
}
