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
vi adjList[400];
int col[400];

bool dfs(int x){
	for (auto i : adjList[x]){
		if(col[i]==col[x])return 1;
		if(col[i]!=-1)continue;
		col[i] = 1-col[x];
		if(dfs(i))return 1;
	}
	return 0;
}

int main(){
	//freopen("input.txt","r",stdin);
	while(1){
		for(int i=0;i<=N;++i)adjList[i].clear();
		cin >> N;
		if(N==0)return 0;
		while(1){
			cin >> a >> b;
			if(a==0&&b==0)break;
			adjList[a].pb(b);
			adjList[b].pb(a);
		}
		res=0;
		memset(col,-1,sizeof(col));
		for(int i =1; i <= N; ++i){
			if(col[i]!=-1)continue;
			col[i]=0;
			if(dfs(i)){
				res=1;
				break;
			}
		}
		if(res)cout << "NO\n";
		else cout << "YES\n";
	}
}

