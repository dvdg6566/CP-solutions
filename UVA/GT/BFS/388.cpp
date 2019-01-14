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

int a,b,c,N,E,Q,w,cnt,res;
string s1,s2;
char c1,c2;
map<string,int> M;
queue<int>pq;
double W[1000];

double EX[30];

void bfs(int x){
	memset(visited,-1,sizeof(visited));
	visited[x] = 0;
	while(pq.size())pq.pop();
	pq.push(x);
	while(pq.size()){
		int cur = pq.front();
		//cout << cur << '\n';
		pq.pop();
		for (auto i : adjList[cur]){
			if(visited[i]!=-1)continue;
			res++;
			visited[i] = visited[cur]+1;
			pq.push(i);
		}
	}
}

int main(){ 
	//freopen("input.txt","r",stdin);
	EX[0]=(double)1;
	for(int i=1;i<28;++i){
		EX[i]=(double)0.95*EX[i-1];
	}
	while(cin>>N){
		memset(W,0,sizeof(W));
		if(cin.eof())return 0;
		cin.ignore();
		for (int i=0;i<=N+10;++i)adjList[i].clear();
		for (int i = 0; i < N; ++i){
			getline(cin,s1);
			a = s1[0]-'A';
			W[a] += s1[2]-'0';
			W[a]+=(double)(s1[4]-'0')/10;
			W[a]+=(double)(s1[5]-'0')/100;
			s1 = s1.substr(7,s1.size()-7);
			for(auto j:s1){
				if(j=='*')adjList[0].pb(a);
				else{
					b = j-'A';
					adjList[a].pb(b);
				}
			}
		}
		bfs(0);
		double h=-1,ans=0;
		for(int i=0;i<28;++i){
			W[i] = W[i] * EX[visited[i]];
			if(W[i]>h){h=W[i];ans=i;}
		}
		c1=ans+'A';
		cout << "Import from " << c1 << '\n';
	}
}
	
