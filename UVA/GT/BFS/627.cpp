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

vi adjList[1000];
int P[1000],CH[1000];

int a,b,c,N,E,Q,w,cnt,res,T;
string s1,s2,s3;
stack<int> S;
queue<int>pq;

int cnv(string s){
	int res = 0,mul=1;
	reverse(s.begin(),s.end());
	for(auto i : s){
		res+=(i-'0')*mul;
		mul*=10;
	}
	return res;
}

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
			P[i] = cur;
			pq.push(i);
		}
	}
}

int main(){ 
	//freopen("input.txt","r",stdin);
	while(cin>>N){
		if(cin.eof()){cout<<'\n';return 0;}
		cout << "-----\n";
		for(int i = 0; i < 500; ++i)adjList[i].clear();
		for(int i = 1; i <= N; ++i){
			cin >> s1;
			s2="";
			for (auto it : s1){
				if (it=='-')break;
				else s2+=it;
			}
			a = cnv(s2);
			s1=s1.substr(s2.size()+1,s1.size()-s2.size()-1);
			//cout << s1 << '\n';
			s2="";
			for (auto x : s1){
				if(x==','){
					b = cnv(s2);
					//cout << b << ' ';
					s2="";
					adjList[a].pb(b);
				}else s2+=x;
			}
			if(s2=="")continue;
			b = cnv(s2);
			adjList[a].pb(b);
			//cout << b << '\n';
		}
		cin >> Q;
		while(Q--){
			cin >> a >> b;
			bfs(a);
			memset(CH,0,sizeof(CH));
			while(S.size())S.pop();
			while(b!=a){
				if(CH[b]){CH[b]=-1;break;}
				S.push(b);
				CH[b]=1;
				b=P[b];
			}
			S.push(a);
			if(CH[b]==-1)cout << "connection impossible\n";
			else{
				while(S.size()){
					cout << S.top();
					if(S.size()!=1)cout << ' ';
					else cout << '\n';
					S.pop();
				}
			}
		} 
	}
}
	
