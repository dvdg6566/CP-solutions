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

vi adjList[3000];
int P[3000],D[3000];

int a,b,c,N,E,Q,w,cnt,res,T;
string s1,s2,s3;
set<int> S;
queue<int>pq;

void bfs(int x){
	memset(P,-1,sizeof(P));
	memset(D,0,sizeof(D));
	P[x] = 0;
	while(pq.size())pq.pop();
	pq.push(x);
	while(pq.size()){
		int cur = pq.front();
		pq.pop();
		for (auto i : adjList[cur]){
			if(P[i]!=-1)continue;
			P[i] = P[cur]+1;
			D[P[cur]+1]++;
			pq.push(i);
		}
	}
}

int main(){ 
	//freopen("input.txt","r",stdin);
	cin >> N;
	for (int i = 0; i < N; ++i){
		cin >> a;
		for (int j = 0; j < a; j++){
			cin >> b;
			adjList[i].pb(b);
		}
	}
	cin >> Q;
	while(Q--){
		cin >> a;
		if (!adjList[a].size()){cout << "0\n";continue;}
		bfs(a);
		int x = *max_element(D,D+2500);
		for (int i = 0; i < N; ++i){
			if (D[i] == x){
				cout << x << ' ' << i << '\n';
				break;
			}
		}
	}
}
	

