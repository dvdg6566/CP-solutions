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


int N,a,b,c,cnt,d,e,g;
int V[200][10];
vi adjList[1000];
vi topo;
bool visited[1000];
ll dp [1000],p[1000];
string M[6];
stack<int> st;

void topodfs(int x){
   for (auto i : adjList[x]) {
        if (visited[i]) continue;
        visited[i]=1;
        topodfs(i);
    }
    topo.pb(x);
}


int main(){
	M[0] = "front";
	M[1] = "back";
	M[2] = "left";
	M[3] = "right";
	M[4] = "top";
	M[5] = "bottom";
	freopen("input.txt","r",stdin);
	while(1){
		if(cnt)cout<<'\n';
		cnt++;
		topo.clear();
		cin>>N;
		if(N==0)return 0;
		memset(V,0,sizeof(V));
		memset(dp,0,sizeof(dp));
		memset(p,0,sizeof(p));
		memset(visited,0,sizeof(visited));
		for (int i = 0; i*6 <= N; ++i)adjList[i].clear();
		cout << "Case #"<<cnt<<"\n";
		for (int i = 1;i<=N;++i){
			cin>>a>>b>>c>>d>>e>>g;
			V[i][0] = a;
			V[i][1] = b;
			V[i][2] = c;
			V[i][3] = d;
			V[i][4] = e;
			V[i][5] = g;
		}
		
		for (int i=1;i<N; ++i){
			for (int j = i+1; j <= N; ++j){
				for (int it = 0; it < 6; ++it){
					for (int jt = 0; jt < 6; ++jt){
						a = i*6+it;
						b = j*6+jt;
						c=it,d=jt;
						if(d%2==0)d++;
						else d--;
						if(V[i][c] != V[it][d])continue;
						adjList[a].pb(b);
					}
				}
			}
		}
		
		for (int i = 7; i <= N*6; ++i){
			if(visited[i])continue;
			visited[i]=1;
			topodfs(i);
		}
		
		reverse(topo.begin(),topo.end());
		
		for (auto i : topo){
			for (auto x : adjList[i]){
				if(dp[x] <= dp[i] + 1){
					p[x] = i;
					dp[x] = dp[i] + 1;
				}
			}
		}
		
		a = *max_element(dp,dp+6*N);
		cout << a+1 << '\n';
		for (int i = 7; i <= N*6; ++i){
			if(dp[i]==a){b = i;a=-1;}
		}
		
		while(b){
			st.push(b);
			b = p[b];
		}
		
		while(st.size()){
			b=st.top();
			st.pop();
			cout << b/6+1 << ' ' << M[b%6] << '\n';
		}
	}
}
