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

vi adjList[100000];
int visited[100000];

int a,b,c,E,Q,w,cnt,res,N;
map<int,int> M;
queue<int>pq;

void bfs(int x){
	memset(visited,-1,sizeof(visited));
	visited[x] = 0;
	while(pq.size())pq.pop();
	pq.push(x);
	while(pq.size()){
		int cur = pq.front();
		pq.pop();
		for (auto i : adjList[cur]){
			if(visited[i]!=-1)continue;
			res++;
			visited[i] = visited[cur]+1;
			if(visited[i]<w)pq.push(i);
		}
	}
}

int main(){
	//freopen("input.txt","r",stdin);
	while(cin >> E){
		for (int i=0;i<=N+10;++i)adjList[i].clear();
		if(!E)return 0;
		N=1;
		M.clear();
		while(E--){
			cin>>a>>b;
			if (M[a]==0){M[a] = N;N++;}
			if (M[b]==0){M[b] = N;N++;}
			a=M[a];b=M[b];
			adjList[a].pb(b);
			adjList[b].pb(a);
		}
		N=M.size();
		//cout << N << '\n';
		while(1){
			cin >> Q >> w;
			if(Q==0)break;
			cnt++;
			res=1;
			if (Q==0){w=0;res=0;}
			if(w!=0)bfs(M[Q]);
			cout << "Case " << cnt << ": " << N-res << " nodes not reachable from node " << Q << " with TTL = " << w << '.' << '\n';
		}
	}
}
	
