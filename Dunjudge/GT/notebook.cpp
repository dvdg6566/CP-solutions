#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef double dl;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MOD 1e9+7
#define lb lower_bound
#define ub upper_bound
#define dst distance
#define INF 1000000000

vpi adjList[501000];
int dist[501000], visited[501000];
queue<int> q;
int N,E,start,fin,a,b,w;
vi V[10];
vi res;

void bfs(int x){
	memset(dist,-1,sizeof(dist));
	q.push(x);
	dist[x] = 0;
	while(q.size()){
		int c = q.front();
		q.pop();
		for (auto i : adjList[c]){
			if(dist[i.f] != -1)continue;
			dist[i.f] = dist[c] + 1;
			q.push(i.f);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> N >> E >> start >> fin;
	while (E--){
		cin >> a >> b >> w;
		adjList[a].pb(mp(b,w));
		adjList[b].pb(mp(a,w));
	}
	bfs(fin);
	if (dist[start] == -1){cout << -1;return 0;}
	q.push(start);
	for (int it = 0; it < dist[start]; ++it){
		ll best = 10;
		while(q.size()){
			int x = q.front();
			q.pop();
			for (auto i : adjList[x]){
				if (dist[x] - 1 != dist[i.f])continue;
				if(visited[i.f])continue;
				if (best < i.s)continue;
				best = min(best,i.s);
				V[i.s].pb(i.f);
			}
		}
		for(int i = 0; i <= 9; ++i){
			if (V[i].size() == 0)continue;
			res.pb(i);
			for (auto j : V[i]){
				if (visited[j])continue;
				visited[j] = 1;
				q.push(j);
			}
			break;
		}
		for(int i = 0; i <= 9; ++i)V[i].clear();
		if (!q.size())break;
	}
	if (res.size() == 0)cout << "0";
	else{
		for (auto i : res)cout << i;
	}
}
