#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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

int p[220000];
int par(int x) { return (x==p[x])?x:p[x]=par(p[x]);}
void merge(int a, int b) {p[par(a)] = par(b);}
vector<edge> edgeList;
bool cmp (edge x, edge y) { return x.w < y.w; } 
ll N,E,w,t;
int a,b;

int main(){
	//freopen("input.txt","r",stdin);
	while(1){
		cin >> N >> E;
		if(N==0)return 0;
		t = 0;
		edgeList.clear();
		for (int i = 0; i < N; ++i)p[i] = i;
		while (E--){
			cin >> a >> b >> w;
			t += w;
			edgeList.pb({a,b,w});
		}
		sort(edgeList.begin(),edgeList.end(),cmp);
		for (auto i : edgeList){
			if(par(i.a) == par(i.b))continue;
			p[par(i.a)] = p[i.b];
			t -= i.w;
		}
		cout << t << '\n';
	}
}
