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
vector<edge> edgeList;

bool cmp (edge x, edge y) { 
	if(x.w!=y.w)return x.w < y.w; 
	return x.a < y.a;
} 

ll N,E,w,t,TC,air,tot;
map<string,int> M;
int a,b;

int main(){
	//freopen("input.txt","r",stdin);
	cin >> TC;
	for (int xxx = 1; xxx <= TC; ++xxx){
		air = 0;
		cin >> N >> E >> t;
		tot = 0;
		edgeList.clear();
		p[0] = 0;
		for (int i = 1; i <= N; ++i){
			p[i] = i;
			edgeList.pb({0,i,t});
		}
		
		while (E--){
			cin >> a >> b >> w;
			edgeList.pb({a,b,w});
		}
		
		sort(edgeList.begin(),edgeList.end(),cmp);
		for (auto i : edgeList){
			if(par(i.a) == par(i.b))continue;
			p[par(i.a)] = p[i.b];
			tot += i.w;
			if(i.a==0)air++;
		}
		
		cout << "Case #" << xxx << ':' << ' ' << tot << ' ' << air << '\n';
	}
}
