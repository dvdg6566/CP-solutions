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

int a,b,c,N,E,Q,w,cnt,res,T;
string s1,s2,s3;
map<string,int> M;
queue<int>pq;
stack<int> S;
vector<string>V;

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
			P[i] =cur;
			pq.push(i);
		}
	}
}

int main(){ 
	//freopen("input.txt","r",stdin);
	cin >> T;
	while(T--){
		for(int i =0;i<N+10;++i)adjList[i].clear();
		M.clear();
		V.clear();
		V.pb("");
		cin >> N >> Q;
		int t = 1;
		for (int i = 0; i < N; ++i){
			cin >> s1 >> s2;
			if(!M[s1]){M[s1]=t;t++;V.pb(s1);}
			if(!M[s2]){M[s2]=t;t++;V.pb(s2);}
			adjList[M[s1]].pb(M[s2]);
			adjList[M[s2]].pb(M[s1]);
		}
		while(Q--){
			cin >> s1 >> s2;
			a=M[s1];
			b=M[s2];
			bfs(a);
			while(S.size())S.pop();
			while(b!=a){
				S.push(b);
				b=P[b];
			}
			S.push(a);
			while(S.size()){
				cout << V[S.top()][0];
				S.pop();
			}
			cout << '\n';
		}
		if(T!=0)cout << '\n';
	}
}
	


