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

int N,E,S,K;
vi adjList[500100];
int dist[500100],t[500100];
int a,b;
queue<int> q;

bool check(int H){
	q.push(S);
	memset(t,-1,sizeof(t));
	t[S] = 0;
	while (q.size()){
		int x = q.front();
		q.pop();
		for (auto i : adjList[x]){
			if (t[i] != -1)continue;
			t[i] = t[x] + 1;
			if (t[i] + dist[i] > H)continue; // Cannot reach any proper checkpoints
			t[i] = min(t[i],dist[i]); // Can go to a checkpoint and back
			q.push(i);
		}
	}
	if(t[0] == -1)return 0;
	return 1;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> N >> E >> S >> K;
	memset(dist,-1,sizeof(dist));
	for (int i = 0; i < K; ++i){
		cin >> a;
		dist[a] = 0;
		q.push(a);
	}
	for (int i = 0; i < E; ++i){
		cin >> a >> b;
		adjList[a].pb(b);
		adjList[b].pb(a);
	}
	if (K == 2){dist[q.front()] = -1; q.pop();}
	while (q.size()){
		int c = q.front();
		q.pop();
		for (auto i : adjList[c]){
			if(dist[i] != -1)continue;
			dist[i] = dist[c] + 1;
			q.push(i);
		}
	}
	if(K == 2){cout << max(dist[0],dist[S]);return 0;}
	int low = 1, high = N;
	while(low + 1 < high){
		int mid = (low+high)/2;
		if(check(mid))high = mid;
		else low = mid;
	}
	
	if (check(low))cout << low;
	else {
		cout << high;
	}
}
