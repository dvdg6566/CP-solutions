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
ll N,E,Q,w,t,T,ans,cnt,cont;
int a,b,cur;

void MST(int ind){
	ll l = 0;
	int con = 0;
	for (int i = 0; i <= N; ++i)C[i] = i;
	for (int x = 0; x < E; ++x){
		edge itt = edgeList[x];
		if (x==ind)continue;
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
		cnt++;
		cout << "Case #" << cnt << " : ";
		cin >> N >> E;
		for (int i = 0; i <= N; ++i)p[i] = i;
		edgeList.clear();
		for(int i=0;i<E;++i){cin >> a >> b >> w;edgeList.pb({a,b,w});}
		for (int i = 0; i <= N; i++)p[i] = i;
		sort(edgeList.begin(), edgeList.end(), cmp);
		w = 0;
		ans = 1234567890;
		cont = 0;
		for (int x = 0; x < E; ++x){
			edge it = edgeList[x];
			if (par(it.a) == par(it.b)) continue;
			p[par(it.a)] = par(it.b);
			w += it.w;
			cont++;
			MST(x);
		}
		if(cont+1!=N)cout << "No way\n";
		else if (ans==1234567890)cout << "No second way\n";
		else cout << ans << '\n';
	}
}


