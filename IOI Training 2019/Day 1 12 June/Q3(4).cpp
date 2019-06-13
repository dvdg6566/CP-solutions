#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef pair<ll,pi> pii;
typedef vector<pi> vpi;
typedef set<ll> si;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define f first
#define s second
ll INF = 1e18;
ll MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (ll)x.size()
#define ALL(x) x.begin(),x.end()
#define MAXN 2100

vi aList[MAXN];
vi veri[MAXN];
int C[MAXN];
int N,a,b,E;
int p[MAXN];
int M[MAXN];

void dfs(int x){
	for (auto v :aList[x]){
		if (p[v])continue;
		p[v]=p[x]+1;
		veri[p[v]].pb(v);
		dfs(v);
	}
}

int main(){
	// freopen("in.txt","r",stdin);
	cin >> N >>E;
	for (int i=1;i<N;++i){
		cin>>a>>b;
		aList[a].pb(b);
		aList[b].pb(a);
	}
	for (int i=1;i<=N;++i)cin>>M[i];
	for (int i=1;i<=N;++i){
		for (int j=1;j<=N;++j)veri[j].clear();
		int ans = 0;
		memset(p,0,sizeof(p));
		memset(C,0,sizeof(C));
		p[i]=1;
		dfs(i);
		// cout<<"Visit node "<<i<<'\n';
		// for (int j=1;j<=N;++j)cout<<p[j]<<' ';cout<<'\n';
		for (int j=2;j<=N;++j){
			if (SZ(veri[j]) == 1){
				// cout<<"Node "<<veri[j][0]<<'\n';
				if (C[M[veri[j][0]]] == 0)++ans;
				C[M[veri[j][0]]] = 1;
			}
		}
		cout<<ans<<'\n';
	}
}