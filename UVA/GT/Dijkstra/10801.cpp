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

int N,k,a,b,w,c,d;
vpi adjList[1200];
stringstream ss;
string str;

vector<int> V;
priority_queue<pi, vector<pi>, greater<pi> > pq;
int dist[1200];
void dijkstra(){
	memset(dist, -1, sizeof(dist));
	for (int i = 0; i < N; ++i){
		pq.push(mp(0,i*100));
		dist[i*100]=0;
	}
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
}
int main(){
	//freopen("input.txt","r",stdin);
	while(1){
		for (int i = 0; i < 500; ++i)adjList[i].clear();
		V.clear();
		cin >> N;
		if(cin.eof())return 0;
		cin >> k;
		for (int i = 0; i < N; ++i){
			cin >> a;
			V.pb(a);
		}
		cin.ignore();
		for (int i = 0; i < N; ++i){
			int spaces = 0;
			ss.clear();
			getline(cin,str);
			for (auto x : str){
				if(x == ' ')spaces++;
			}
			ss << str;
			ss >> b;
			w = V[i];
			for (int j = 0; j < spaces; ++j){
				ss >> a;
				c = a + 100*i;
				d = b + 100*i;
				adjList[c].pb(mp(d,w*abs(b-a)));
				adjList[d].pb(mp(c,w*abs(b-a)));
				b = a;
			}
		}
		w = 60;
		for(int j = 0; j < 100; ++j){
			for (int it = 0; it < N; ++it){
				for (int itt = 0; itt < N; ++itt){
					adjList[j+100*itt].pb(mp(j+100*it,w));
					adjList[j+100*it].pb(mp(j+100*itt,w));
				}
			}
		}
		int ans = INF;
		dijkstra();
		for (int i = 0; i < N; ++i){
			if(dist[i*100+k] == -1)continue;
			ans = min(ans,dist[i*100+k]);
		}
		if (ans != INF)cout<<ans<<'\n';
		else cout << "IMPOSSIBLE\n";
	}	
}
