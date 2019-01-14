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

vi adjList[300100];
int P[300100];
queue<int> pq;

int a,b,c,N,E,Q,w,cnt,res,T;

void bfs(int x){
	memset(P,-1,sizeof(P));
	P[x] = 0;
	while(pq.size())pq.pop();
	pq.push(x);
	while(pq.size()){
		int cur = pq.front();
		pq.pop();
		for (auto i : adjList[cur]){
			if(P[i]!=-1)continue;
			P[i] = P[cur]+1;
			pq.push(i);
		}
	}
}

int main(){ 
	//freopen("input.txt","r",stdin);
	cin >> T;
	while(T--){
		for(int i =0;i<N+10;++i)adjList[i].clear();
		cin >> N >> E;
		while(E--){
			cin>>a>>b;
			adjList[a].pb(b);
			adjList[b].pb(a);
		}
		bfs(0);
		for(int i = 1; i < N; ++i)cout << P[i] << '\n';
		if(T)cout << '\n';
	}
}
	



