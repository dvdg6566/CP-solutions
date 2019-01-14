#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;

#define f first
#define s second
#define mp make_pair
#define pb push_back

vector<int> adjList[120];
int N,E,V,a,b,c;
bool visited[120];

void dfs(int x){
	for (auto i : adjList[x]){
		if(visited[i])continue;
		visited[i]=1;
		dfs(i);
	}
}

int main(){
	//freopen("input.txt","r",stdin);
	while (1){
		for (int i = 1; i <= N; ++i)adjList[i].clear();
		cin >> N; 
		if(!N)return 0;
		while (1){
			cin >> a;
			if(a==0)break;
			while(1){
				cin >> b;
				if(b==0)break;
				adjList[a].pb(b);
			}
		}
		cin >> E;
		for (int i=0;i<E;++i){
			memset(visited,0,sizeof(visited));
			cin >> a;
			dfs(a);
			V=0;
			for (int i = 1; i <= N; ++i){
				if(!visited[i])V++;
			}
			cout << V;
			for (int i = 1; i <= N; ++i){
				if(!visited[i])cout << ' ' << i;
			}
			cout << '\n';
 		}
	}
}
