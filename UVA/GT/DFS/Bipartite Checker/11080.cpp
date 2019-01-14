#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pi;
typedef long long ll;
typedef vector<pi> vpi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define s second
#define f first

int a,b,c,d,T,N,E,res,ans;
vi adjList[300];
int col[300];

bool dfs(int x){
	for (auto i : adjList[x]){
		if(col[i]==col[x])return 1;
		if(col[i]!=-1)continue;
		col[i] = 1-col[x];
		if(col[i])c++;
		if(col[i]==0)d++;
		if(dfs(i))return 1;
	}
	return 0;
}

int main(){
	//freopen("input.txt","r",stdin);
	cin >> T;
	while(T--){
		for(int i=0;i<N;++i)adjList[i].clear();
		cin >> N >> E;
		while(E--){
			cin>>a>>b;
			adjList[a].pb(b);
			adjList[b].pb(a);
		}
		res=0;ans=0;
		memset(col,-1,sizeof(col));
		for(int i = 0; i < N; ++i){
			if(col[i]!=-1)continue;
			col[i]=0;
			c=0;d=1;
			if(dfs(i)){
				res=1;
				break;
			}
			ans+=min(c,d);
			if(min(c,d)==0)ans++;
		}
		if(res)cout << -1 << '\n';
		else cout << ans << '\n';
	}
}
