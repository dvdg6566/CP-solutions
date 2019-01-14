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

int a,b,c,N,E,Q,w,cnt,res,T;
string s1,s2,s3;
map<string,int> M;
queue<int>pq;
vector<string>V;

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
			visited[i] = visited[cur]+1;
			pq.push(i);
		}
	}
}

int main(){ 
	freopen("input.txt","r",stdin);
	cin >> T;
	while(T--){
		for(int i=1;i<=N;++i)adjList[i].clear();
		if(N!=0)cout << '\n';
		N=1;
		V.clear();
		M.clear();
		V.pb("");
		while(1){
			cin >> s1;
			if(s1=="*")break;
			M[s1]=N;
			N++;
			V.pb(s1);
		}
		for (int i = 1; i <= V.size(); ++i){
			for (int j = 1; j <= V.size(); ++j){
				int cnt = max(V[i].size(),V[j].size());
				for (int k = 0; k < V[i].size() && k < V[j].size(); ++k){
					if(V[j][k] == V[i][k])cnt--;
				}
				if(cnt==1){
					adjList[i].pb(j);
					adjList[j].pb(i);
				}
			}
		}
		cin.ignore();
		while(1){
			getline(cin,s1);
			if(s1=="")break;
			s2="";
			s3="";
			bool ok = 0;
			for (auto i : s1){
				if(i==' '){ok=1;}
				else if (ok){s3+=i;}
				else s2+=i;
			}
			bfs(M[s2]);
			
			cout << s2 << ' '  << s3 << ' ';
			cout << visited[M[s3]] << '\n';
		}
	}
}
	
