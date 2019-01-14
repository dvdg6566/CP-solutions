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

ll n,m,r,t;
vector<ll> mod[1100];
priority_queue<pi,vector<pi>,greater<pi> >pq;
ll hgt[101000],dist[101000];

void dijkstra(){
	memset(dist,-1,sizeof(dist));
	dist[0] = 0;
	pq.push(mp(0,0));
	while (!pq.empty()) {
	    pi cur = pq.top();
	    pq.pop();
	    ll x = cur.second , d = cur.first;
	    ll h = hgt[x];
	    if (d > dist[x]) continue;
	    if (x == n-1)return;
	    for (auto it : mod[(h+r)%m]){
			if (hgt[x] == hgt[it])continue;
	        ll nd = hgt[it];
	        nd = (h-nd)*(h-nd) + d;
	        if (dist[it] != -1 && dist[it] <= nd) continue;
	        if (dist[n-1] != -1 && nd >= dist[n-1])continue;
	        dist[it] = nd;
	        pq.push(mp(nd, it));
	    }
	    for (auto it : mod[(m+h-r)%m]){
			if (hgt[x] <= hgt[it])continue;
            ll nd = hgt[it];
            nd = (h-nd)*(h-nd) + d;
            if (dist[it] != -1 && dist[it] <= nd) continue;
            if (dist[n-1] != -1 && nd >= dist[n-1])continue;
            dist[it] = nd;
            pq.push(mp(nd, it));
	    }
	}
}

int main(){
 	//freopen("input.txt","r",stdin);
	cin >> n >> m >> r;
	for (ll i = 0; i < n; ++i){
		cin >> t;
		mod[t%m].pb(i);
		hgt[i] = t;
	}
	dijkstra();
	//for (ll i = 0; i < n; ++i)cout << dist[i] << ' ';
	if (dist[n-1] == -1)cout << "Black Mage you scammer!!!";
	else cout << dist[n-1];
}
