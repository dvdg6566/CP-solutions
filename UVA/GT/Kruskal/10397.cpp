#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long double,long double> pi;
typedef vector<int> vi;

#define f first
#define s second
#define mp make_pair
#define pb push_back

struct edge {
    int a, b;
    long double w;
    edge (int _a=0, int _b=0, long double _w=0): a(_a), b(_b), w(_w) {}
};

int p[10000];
int par(int x) { return (x==p[x])?x:p[x]=par(p[x]);}
void merge(int a, int b) {p[par(a)] = par(b);}
vector<edge> edgeList;
bool cmp (edge x, edge y) { return x.w < y.w; } 
vector<pi> nd;

int T,N,M,G;
long double a,b,res,w;

int main(){
	//freopen("input.txt","r",stdin);
	while(1){
		cin>>N;
		if(cin.eof())return 0;
		edgeList.clear();
		memset(p,0,sizeof(p));
		nd.clear();
		nd.pb(mp(-1,-1));
		for (int i = 1; i <= N; ++i){
			cin >> a >> b;
			nd.pb(mp(a,b));
		}
		for (int i = 1; i <= N; ++i){
			for (int j = i; j <= N; ++j){
				if(i==j)continue;
				long double t = (nd[i].f-nd[j].f)*(nd[i].f-nd[j].f)+(nd[i].s-nd[j].s)*(nd[i].s-nd[j].s);
				long double x = sqrt(t);
				edgeList.pb({i,j,x});
			}
		}
		cin >> M;
		w=0;
		for (int i = 1; i <= N; i++)p[i] = i;
		while(M--){
			cin>>a>>b;
			if(par(a)==par(b))continue;
			p[par(a)] = par(b);
			N--;
		}
		sort(edgeList.begin(), edgeList.end(), cmp);
		for (auto it : edgeList){
			if (par(it.a) == par(it.b)) continue;
			p[par(it.a)] = par(it.b);
			w += it.w;
			N--;
			if (N==G)break;
		}
		printf("%.2Lf\n",floor(100*w+0.5)/100);
	}
}



