#include<bits/stdc++.h>
using namespace std;
typedef double ll;
typedef pair<ll,ll> pi;
typedef vector<int> vi;

#define f first
#define s second
#define mp make_pair
#define pb push_back

struct edge {
    int a, b;
    ll w;
    edge (int _a=0, int _b=0, ll _w=0): a(_a), b(_b), w(_w) {}
};
 
int p[200];
int par(int x) { return (x==p[x])?x:p[x]=par(p[x]);}
vector<edge> edgeList;
bool cmp (edge x, edge y) { return x.w > y.w; } 
ll N,E,Q,w,t,T,cntr;
int a,b,cur;

int main(){
	freopen("input.txt","r",stdin);
	cin>>T;
	while(T--){
		cntr++;
		cin >> N >> E;
		if(N==0)return 0;
		for (int i = 0; i <= N; ++i)p[i] = i;
		edgeList.clear();
		while(E--){cin >> a >> b >> w;edgeList.pb({a,b,w});}
		for (int i = 0; i <= N; i++)p[i] = i;
		sort(edgeList.begin(), edgeList.end(), cmp);
		w = 1234567890;
		for (auto it : edgeList){
			if (par(it.a) == par(it.b)) continue;
			p[par(it.a)] = par(it.b);
			w = min(w,it.w);
		}
		
		cout << "Case #" << cntr << ": " << w << '\n';		
	}
}
