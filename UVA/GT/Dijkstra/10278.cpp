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

int tc,F,E,a,b,w,N;
int dist[600];
int fire[600];
vpi adjList[600];
string str;
priority_queue<pi, vector<pi>, greater<pi> > pq;
vector<int>V;
stringstream ss;

int dijkstra(int start){
	memset(dist, -1, sizeof(dist));
	for (auto j : V){
		dist[j] = 0;
		pq.push(mp(0,j));
	}
	dist[start] = 0;
	pq.push(mp(0,start));
	while (!pq.empty()) {
	    pi cur = pq.top();
	    pq.pop();
	    int x = cur.s, d = cur.f;
	    if (d > dist[x]) continue;
	    for (auto it:adjList[x]) {
	        int nx = it.f, nd = d+it.s;
	        if (dist[nx] != -1 && dist[nx] <= nd) continue;
	        dist[nx] = nd;
	        pq.push(mp(nd, nx));
	    }
	}
	return *max_element(dist,dist+N+1);
}

int main(){
	//freopen("input.txt","r",stdin);
	cin>>tc;
	while(tc--){
		V.clear();
		cin>>F>>N;
		for (int i = 0; i <= N+10; ++i)adjList[i].clear();
		memset(fire,0,sizeof(fire));
		for (int i = 0; i < F; ++i){
			cin>>a;
			V.pb(a);
			fire[a] = 1;
		}
		cin.ignore();
		while(1){
			ss.clear();
			getline(cin,str);
			if(str=="")break;
			ss << str;
			ss>>a>>b>>w;
			adjList[a].pb(mp(b,w));
			adjList[b].pb(mp(a,w));
		}
		int res = -1, ans = INF;
		for (int i = 1; i <= N; ++i){
			int x = dijkstra(i);
			if (x < ans){
				ans = x;
				res = i;
			}
		}
		cout << res << '\n';
		if(tc)cout<<'\n';
	}
}
