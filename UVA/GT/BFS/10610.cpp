#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pi;
typedef double dl;
typedef long long ll;
typedef vector<pi> vpi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define s second
#define f first

vi adjList[2000];
int P[2000];

int N,E,Q,w,D,res,T,x,y,z;
string S,s1,s2,st1,st2;
dl a,b,c,mul;
bool neg;
queue<int>pq;
vector<pair<dl,dl>>V;

double cnv (string st){
	if(st[0] == '-'){neg=1;st = st.substr(1,st.size()-1);}
	else neg=0;
	y = -1;
	for(int i = 0; i < st.size(); ++i){
		if(st[i]=='.'){y = i; break;}
	}
	assert(y!=-1);
	st1 = st.substr(0,y);
	st2 = st.substr(y+1,st.size()-y-1);
	dl res = 0;
	reverse(st1.begin(),st1.end());
	mul = 1;
	for(auto i : st1){
		res += (i-'0')*mul;
		mul*=10;
	}
	mul=0.1;
	for(auto i : st2){
		res += (i-'0')*mul;
		mul/=10;
	}
	if(neg)res=-res;
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
			P[i] = P[cur]+1;
			pq.push(i);
		}
	}
}

int main(){ 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	while(1){
		for(int i =0;i<N+10;++i)adjList[i].clear();
		V.clear();
		cin >> a >> b;
		if(a==0&&b==0)return 0;
		cin.ignore();
		D = a*b*60;
		while(1){
			getline(cin,S);
			if(S=="")break;
			for(int i = 0; i < S.size(); ++i){
				if(S[i] == ' '){
					x = i;
					break;
				}
			}
			s1 = S.substr(0,x);
			s2 = S.substr(x+1,S.size()-x-1);
			a = cnv(s1);
			b = cnv(s2);
			V.pb(mp(a,b));
		}
		N=V.size();
		for (int i = 0; i < N; ++i){
			for (int j = i+1; j < N; ++j){
				dl x = sqrt((V[i].f-V[j].f)*(V[i].f-V[j].f)+(V[i].s-V[j].s)*(V[i].s-V[j].s));
				if(x>D)continue;
				adjList[i].pb(j);
				adjList[j].pb(i);
			}
		}
		bfs(0);
		if(P[1]!=-1)cout << "Yes, visiting " << P[1]-1 << " other holes.\n";
		else cout << "No.\n";
	}
}
	



