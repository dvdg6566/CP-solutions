#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef pair<double,ll> pdl;
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

vector<pair<ll,double>> adjList[400];
double walk=(double)10000/(double)60;
double train = walk*4;
double dist[400];
int  mrts[400];
int T,N,E,M,tc,a,b,w;
vi edgeList;
vector<double> tmp;
vector<pair<double,double>> V;
string st,st1;

ll cnv(string s){
	if(s[0]=='-')return -1;
	ll res = 0,mul=1;
	reverse(s.begin(),s.end());
	for(auto i : s){
		res+=(i-'0')*mul;
		mul*=10;
	}
	return res;
}

priority_queue<pdl, vector<pdl>, greater<pdl> > pq;
void dijkstra(int start){ 
	for (int i = 0; i <= V.size()+10;++i)dist[i]=-1;
	dist[start] = (double)0;
	pq.push(mp((double)0, start));
	while (!pq.empty()) {
	    pdl cur = pq.top();
	    pq.pop();
	    int x = cur.s;
	    double d = cur.f;
	    if (d > dist[x])continue;
	    for (auto it:adjList[x]) {
	        int nx = it.f;
	        double nd = d+it.s;
	        if (dist[nx] != -1 && dist[nx] <= nd){continue;}
	        dist[nx] = nd;
	        pq.push(mp(nd, nx));
	    }
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin>>tc;
	cin.ignore();
	getline(cin,st);
	while(tc--){
		memset(mrts, -1, sizeof(mrts));
		for(int i=0;i<=300;++i)adjList[i].clear();
		edgeList.clear();
		V.clear();
		tmp.clear();
		getline(cin,st);
		st1="";
		st=st+" ";
		for (auto i : st){
			if(i==' '){
				tmp.pb(cnv(st1));
				st1="";
			}else st1+=i;
		}
		
		V.pb(mp(-1,-1));
		V.pb(mp(tmp[0],tmp[1]));
		V.pb(mp(tmp[2],tmp[3]));
		mrts[1]= 0;
		mrts[2] = 1;
		int grp=1,id = 3;
		a = -1;
		st1="";
		
		while(1){
			grp++;
			getline(cin,st);
			if(st=="")break;
			stringstream ss(st);
			while(1){
				ss >> a >> b;
				if(a==-1)break;
				V.pb(mp(a,b));
				mrts[id] = grp;
				id++;
			}
		}
		
		for (int i = 1; i < V.size(); ++i){
			assert(mrts[i]!=-1);
			for (int j = 1; j < V.size(); ++j){
				if(i==j)continue;
				double c = sqrt((V[i].f-V[j].f)*(V[i].f-V[j].f) + (V[i].s-V[j].s)*(V[i].s-V[j].s));
				if (mrts[i] == mrts[j] && abs(i-j)==1){
					adjList[i].pb(mp(j,c/train));
				}
				else {
					adjList[i].pb(mp(j,c/walk));
				}
			}
		}
		dijkstra(1);
		cout << roundf(dist[2]) << '\n';
		if(tc)cout<<'\n';
	}
}

