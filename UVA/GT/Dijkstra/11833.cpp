#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second
#define INF 1000000000
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define dst distance
#define MOD 1000000009

int N,M,C,K,a,b,w;
vpi adjList[300];
int dp[300],dist[300];
priority_queue<pi,vector<pi>,greater<pi>> pq;

void preprocess(int start){
	memset(dp,-1,sizeof(dp));
	dp[start] = 0;
	while(1){
		if(start == 0)return;
		for (auto i : adjList[start]){
			if(i.f + 1 == start){
				dp[i.f] = dp[start] + i.s;
			}
		}
		start -= 1;
	}
}

void dijkstra(int start){
	int ans = INF;
	memset(dist, -1, sizeof(dist));
	dist[start] = 0;
	pq.push(mp(0, start));
	while (!pq.empty()) {
	    pi cur = pq.top();
	    pq.pop();
	    int x = cur.s, d = cur.f;
	    if (d > dist[x]) continue;
		if(x < C){
			ans = min(ans,dp[x] + d);
			continue;
		}
	    for (auto it:adjList[x]) {
	        int nx = it.f, nd = d+it.s;
	        if (dist[nx] != -1 && dist[nx] <= nd) continue;
	        dist[nx] = nd;
	        pq.push(mp(nd, nx));
	    }
	}
	cout << ans << '\n';
}

int main(){
	//freopen("input.txt","r",stdin);
	while(cin>>N>>M>>C>>K){
		if(N==0)return 0;
		for(int i = 0; i < N; ++i)adjList[i].clear();
		while(M--){
			cin>>a>>b>>w;
			adjList[a].pb(mp(b,w));
			adjList[b].pb(mp(a,w));
		}
		// Destination is C-1. 
		preprocess(C-1);
		dijkstra(K);
	}
}
