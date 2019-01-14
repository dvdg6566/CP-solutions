#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;

#define f first
#define s second
#define mp make_pair
#define pb push_back

bool visited[100000];
vector<int> topo;
int ord[100000];
vi adjList[1001];

void topodfs(int x){
    visited[x] = 1;
    for (auto i : adjList[x]) {
        if (visited[i]) continue;
        topodfs(i);
    }
    topo.pb(x);
}

int a,b,c,d,N,E;

int main(){
	//freopen("input.txt","r",stdin);
	while(1){
		for (int i = 1; i <= N; ++i)adjList[i].clear();
		cin >> N >> E;
		if(N==0&&E==0)return 0;
		while (E--){
			cin >>a >> b;
			adjList[a].pb(b);
		}
		topo.clear();
		memset(visited,0,sizeof(visited));
		for (int i = 1; i <= N; ++i) {
			if (visited[i]) continue;
			topodfs(i);
		}
		reverse(topo.begin(), topo.end());
		for (auto i : topo){
			if (i!=topo[0])cout << ' ';
			cout << i;
		}
		cout << '\n';
	}
}
