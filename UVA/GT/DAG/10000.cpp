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

vi adjList[130];
int N,a,b,c,T,root;

ll visited[130];
ll w[130];
vi topo,roots;
int cnt=1;

void dfs(int x){
   for (auto i : adjList[x]) {
        if (visited[i]) continue;
        visited[i]=1;
        dfs(i);
    }
    topo.pb(x);
}

int main(){
	//freopen("input.txt","r",stdin);
	while(cnt++){
		cin >> N;
		if(N==0)return 0;
		cin >> root;
		for(int i=1;i<=N;++i)adjList[i].clear();
		while(1){
			cin>>a>>b;
			if(a==0&&b==0)break;
			adjList[a].pb(b);
		}
		topo.clear();
		memset(visited,0,sizeof(visited));
		visited[root]=1;
		dfs(root);
		memset(visited,0,sizeof(visited));
		b=0;
		reverse(topo.begin(),topo.end());
		for (auto i : topo){
			for(auto x : adjList[i]){
				visited[x] = max(visited[x], visited[i]+1);
				if(visited[x]==b&&x<c)c=x;
				if(visited[x]>b){
					b=visited[x];
					c=x;
				}
			}
		}
		if(b==0){
			c=root;
		}
		cout<< "Case " << cnt-1 << ": The longest path from " << root << " has length "<<b<<", finishing at "<<c<<".\n\n";
	}
}

