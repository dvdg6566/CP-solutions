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
 
int p[200],C[200];
int par(int x) { return (x==p[x])?x:p[x]=par(p[x]);}
int cpar(int x) { return (x==C[x])?x:C[x]=cpar(C[x]);}
vector<edge> edgeList;
bool cmp (edge x, edge y) { return x.w < y.w; } 
ll N,E,Q,w,t,T,ans;
int a,b,cur;

void MST(int x, int y){
	ll l = 0;
	int con = 0;
	for (int i = 0; i <= N; ++i)C[i] = i;
	for (auto itt : edgeList){
		if (itt.a==x&&itt.b==y)continue;
		if (cpar(itt.a) == cpar(itt.b)) continue;
		C[cpar(itt.a)] = cpar(itt.b);
		l += itt.w;
		con++;
	}
	if (con+1!=N)return;
	ans = min(ans,l);
}

int main(){
	//freopen("input.txt","r",stdin);
	cin>>T;
	while(T--){
		cin >> N >> E;
		for (int i = 0; i <= N; ++i)p[i] = i;
		edgeList.clear();
		while(E--){cin >> a >> b >> w;edgeList.pb({a,b,w});}
		for (int i = 0; i <= N; i++)p[i] = i;
		sort(edgeList.begin(), edgeList.end(), cmp);
		w = 0;
		ans = 1234567890;
		for (auto it : edgeList){
			if (par(it.a) == par(it.b)) continue;
			p[par(it.a)] = par(it.b);
			w += it.w;
			MST(it.a,it.b);
		}
		cout << w << ' ' << ans << '\n';
	}
}

