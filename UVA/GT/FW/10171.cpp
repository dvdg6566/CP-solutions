#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef vector<ll> vi;
typedef pair<pi,pi> pii;
typedef pair<int,pi> ii;
#define f first
#define s second
#define pb push_back
#define mp make_pair

vector<pi> Y[30],O[30];
int dist[30],mig[30];
priority_queue<pi, vector<pi>, greater<pi> > pq;
char a,b,c,d;
int E,N,x,y,z;
map<char,int> M;
vector<char> V; 
vi res;

int main(){
	//freopen("input.txt","r",stdin);
	while(1){
		cin >> E;
		if(E==0)return 0;
		M.clear();
		V.clear();
		V.pb(' ');
		res.clear();
		memset(dist,-1,sizeof(dist));
		memset(mig,-1,sizeof(mig));
		for(int i = 1; i < 30; ++i){
			Y[i].clear();
			O[i].clear();
		}
		int cnt=1;
		while(E--){
			cin >> a >> b >> c >> d >> x;
			if (M[c]==0){
				M[c]=cnt;
				V.pb(c);
				cnt++;
			}
			if (M[d]==0){
				M[d]=cnt;
				V.pb(d);
				cnt++;
			}
			y = M[c];z=M[d];
			if (a=='Y'){
				Y[y].pb(mp(z,x));
				if (b=='B'){
					Y[z].pb(mp(y,x));
				}
			}else{
				O[y].pb(mp(z,x));
				if (b=='B'){
					O[z].pb(mp(y,x));
				}
			}
		}
		cin >> a >> b;
		x= M[a];
		y=M[b];
		dist[x] = 0;
		pq.push(mp(0, x));
		while (!pq.empty()) {
			pi cur = pq.top();
			pq.pop();
			int x = cur.s, d = cur.f;
			if (d > dist[x]) continue;
			for (auto it:Y[x]) {
				int nx = it.f, nd = d+it.s;
				if (dist[nx] != -1 && dist[nx] <= nd) continue;
				dist[nx] = nd;
				pq.push(mp(nd, nx));
			}
		}
		mig[y] = 0;
		pq.push(mp(0, y));
		while (!pq.empty()) {
			pi cur = pq.top();
			pq.pop();
			int x = cur.s, d = cur.f;
			if (d > mig[x]) continue;
			for (auto it:O[x]) {
				int nx = it.f, nd = d+it.s;
				if (mig[nx] != -1 && mig[nx] <= nd) continue;
				mig[nx] = nd;
				pq.push(mp(nd, nx));
			}
		}
		int ans = -1;
		for (int i = 1; i <= V.size(); ++i){
			if(dist[i]==-1)continue;
			if(mig[i]==-1)continue;
			if(ans!=-1&&ans<dist[i]+mig[i])continue;
			if(ans!=-1&&ans==dist[i]+mig[i]){res.pb(i);continue;}
			res.clear();
			res.pb(i);
			ans = dist[i]+mig[i];
		}
		if(ans==-1)cout << "You will never meet.\n";
		else{
			cout << ans;
			sort(res.begin(),res.end());
			for(auto i : res)cout << ' ' << V[i];
			cout << '\n';
		}
	}
}

