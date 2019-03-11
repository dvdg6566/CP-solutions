#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef vector<ll> vi;
typedef vector<pi> vpi;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define SZ(x) (int)x.size()
#define ALL(x) (x).begin(),(x).end()

int p[100100];
vi V[100100];
int done[100100];
int N,M,a,b,T;
int A[100100], B[100100];

int par(int x){return (x == p[x]) ? x:p[x] = par(p[x]);}

bool run(){
	for (int i=1;i<=N;++i){
		for (auto x : V[i])done[A[x]] = 1;
		for (auto x : V[i]){
			if (done[B[x]] == 0)return 0;
		}
		for (auto x : V[i])done[A[x]] = 0;
	}
	return 1;
}
int main(){
	//freopen("in.txt","r",stdin);
	cin>>T;
	while(T--){
		cin>>N>>M;
		for (int i=1;i<=N;++i)cin>>A[i];
		for (int i=1;i<=N;++i)cin>>B[i];
		for (int i=1;i<=N;++i)p[i] = i;
		for (int i=0;i<M;++i){
			cin>>a>>b;
			p[par(a)] = par(b);
		}
		for (int i=1;i<=N;++i)V[i].clear();
		for (int i=1;i<=N;++i)V[par(i)].pb(i);
		if (run())cout<<"YES\n";
		else cout << "NO\n";
	}
}