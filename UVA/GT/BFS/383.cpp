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
ll visited[100000];

int a,b,c,N,E,Q,w,cnt,res;
string s1,s2;
map<string,int> M;
queue<int>pq;

int bfs(int x){
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
			if(i==c)return visited[i];
			pq.push(i);
		}
	}
	return -1;
}

int main(){ 
	//freopen("input.txt","r",stdin);
	cout << "SHIPPING ROUTES OUTPUT\n\n";
	int T;cin>>T;
	for(int i=1;i<=T;++i){
		cout << "DATA SET  " << i << "\n\n";
		cin >> N>>E>>Q;
		for (int i=0;i<=N+10;++i)adjList[i].clear();
		M.clear();
		for(int i=1;i<=N;++i){cin>>s1;M[s1]=i;}
		while(E--){
			cin>>s1>>s2;
			a=M[s1];b=M[s2];
			adjList[a].pb(b);
			adjList[b].pb(a);
			//cout << a << ' ' << b << '\n';
		}
		while(Q--){
			cin >> a >> s1>>s2;
			//cout << a << ' ';
			b=M[s1],c=M[s2];
			//cout << b << ' ' << c << ' ';
			res=1;
			visited[b]=0;
			ll w = bfs(b)*a*100;
			if(w<0)cout << "NO SHIPMENT POSSIBLE\n";
			else cout << '$' << w << '\n';
		}
		cout << '\n';
	}
	cout << "END OF OUTPUT\n";
}
	
