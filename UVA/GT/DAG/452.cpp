#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef vector<ll> vi;
typedef vector<pi> vpi;

#define f first
#define s second
#define pb push_back
#define mp make_pair

vi adjList[30];
int N,a,b,c,T,root;
string s,s1,s2;

ll cnv(string stt){
	ll res = 0,mul=1;
	reverse(stt.begin(),stt.end());
	for(auto i : stt){
		res+=(i-'0')*mul;
		mul*=10;
	}
	return res;
}

ll visited[30],g[30];
ll w[30];
vi topo,roots;

void dfs(int x){
   for (auto i : adjList[x]) {
        if (visited[i]) continue;
        visited[i]=1;
        dfs(i);
    }
    topo.pb(x);
}

int main(){
	//freopen("input.txt","r",stdin);
	cin>>T;
	cin.ignore();
	getline(cin,s);
	while(T--){
		for (int i = 0; i < 28; ++i){adjList[i].clear();w[i]=-1;}
		roots.clear();
		memset(g,0,sizeof(g));
		while(1){
			getline(cin,s);
			if(s=="")break;
			a=s[0]-'A';
			if(w[a]!=-1)continue;
			s = s.substr(2,s.size()-2);
			s1="";
			if(s=="")roots.pb(a);
			b=-1;
			for (int i = 0; i < s.size(); ++i){
				if(s[i]==' '){
					b = i;
					break;
				}
				else s1+=s[i];
			}
			c=cnv(s1);
			w[a]=c;
			if(b==-1 || b==s.size()-1){roots.pb(a);continue;}
			s = s.substr(b+1,s.size()-b-1);
			for (auto i : s){
				adjList[i-'A'].pb(a);
			}
		}
		memset(visited,0,sizeof(visited));
		topo.clear();
		a=0;
		for (auto i : roots){
			visited[i] = 1;
			dfs(i);
			g[i] = 1;
		}
		reverse(topo.begin(),topo.end());
		memset(visited,0,sizeof(visited));
		for (auto i : topo){
			if(g[i])visited[i]=w[i];
			for (auto v : adjList[i]){
				visited[v] = max(visited[v], visited[i] + w[v]);
			}
		}
		cout << *max_element(visited,visited+26) << '\n';
		if(T)cout<<'\n';
	}
}
