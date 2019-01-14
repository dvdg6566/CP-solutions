#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;

#define f first
#define s secon
#define mp make_pair
#define pb push_back

vector<int> adjList[300];
int visited[300],color[300];
int a,b,c,n,e,l;

bool dfs(int x){
  if(visited[x]) return false;
  visited[x] = 1;
  for(auto i : adjList[x]){
    if(color[i] == color[x]){return 1;}
    color[i] = 1-color[x];
    if(!visited[i]){
      if(dfs(i)){return 1;}
    }
  }
  return 0;
}

int main(){
	//freopen("input.txt","r",stdin);
	while (1){
		cin >> n;
		if (n==0)return 0;
		cin >> l;
		for (int i = 0; i < 202; ++i)adjList[i].clear();
		memset(visited,0,sizeof(visited));
		memset(color,-1,sizeof(color));
		while(l--){
			cin >>a >>b;
			adjList[a].pb(b);
			adjList[b].pb(a);
		}
		color[0]=1;
		if (dfs(0))cout << "NOT ";
		cout << "BICOLORABLE.\n";
	}
}
