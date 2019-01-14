#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MOD 1e9+7
#define lb lower_bound
#define ub upper_bound
#define dst distance
#define INF 1000000000


struct edge {
    int start, time, d;
    edge (int _start=0, int _time=0, int _d=0): start(_start), time(_time), d(_d) {}
};

map<string, int> M;
vector<edge> adjList[120];
int N,E,a,b,c,tc,d,T;
string S,S2;
vector<pi> V;
int dist[120];
priority_queue<pi,vector<pi>,greater<pi>> pq;

void dijkstra(int x, int t){
	memset(dist,-1,sizeof(dist));
	dist[x] = t;
	pq.push(mp(t,x));
	while(pq.size()){
		pi cur=pq.top();
		pq.pop();
		int x = cur.s, d = cur.f;
	    if (d > dist[x]) continue;
	    for (auto it:adjList[x]) {
	        int nx = it.d;
	        int nd = 24*(d/24) + it.start;
	        if (it.start < d%24)nd += 24;
	        nd += it.time;
	        if (dist[nx] != -1 && dist[nx] <= nd)continue;
	        dist[nx] = nd;
	        pq.push(mp(nd, nx));
	    }
	}
}

int main(){
	//freopen("input.txt","r",stdin);
	cin>>T;
	while(T--){
		tc++;
		cout << "Test Case "<<tc<<".\n";
		for (int i = 1; i <= N+10; ++i)adjList[i].clear();
		M.clear();
		int cnt = 1;
		cin >> E;
		while(E--){
			cin>>S;
			if (M[S] == 0){M[S] = cnt;cnt++;}
			a = M[S];
			cin>>S;
			if (M[S] == 0){M[S] = cnt;cnt++;}
			b = M[S];
			cin>>c>>d;
			if(d>12)continue;
			if(c>6&&c<18)continue;
			if(d==12&&c!=18) continue;
			if((c+d)%24 > 6 && (c+d)%24 < 18) continue;
			adjList[a].pb({c,d,b});
		}
		N = cnt;
		cin>>S>>S2;
		a = M[S] , b = M[S2];
		if(S==S2){cout<<"Vladimir needs 0 litre(s) of blood.\n";continue;}
		if (a==0||b==0){cout << "There is no route Vladimir can take.\n";continue;}
		dijkstra(a,0);
		if(dist[b] == -1){
			cout << "There is no route Vladimir can take.\n";continue;
		}
		int tmp = dist[b];
		dijkstra(a,12);
		tmp = min(dist[b]+12,tmp);
		cout<< "Vladimir needs " << ((dist[b]-12)/24) << " litre(s) of blood.\n";
	}
}

