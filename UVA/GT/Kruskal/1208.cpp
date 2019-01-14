#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;

#define f first
#define s second
#define mp make_pair
#define pb push_back

struct edge {
    int a, b, w;
    edge (int _a=0, int _b=0, int _w=0): a(_a), b(_b), w(_w) {}
};
int p[100];
int par(int x) { return (x==p[x])?x:p[x]=par(p[x]);}
void merge(int a, int b) {p[par(a)] = par(b);}
vector<edge> edgeList;
bool cmp (edge x, edge y) { 
	if(x.w!=y.w)return x.w < y.w; 
	if(x.a!=y.a) return x.a<y.a;
	return x.b<y.b;
} 

int t,n,m,a,b,w;
char c;

int main(){
	//freopen("input.txt","r",stdin);
	cin >> t;
	for (int gg = 1; gg <= t; ++gg){
		edgeList.clear();
		cout << "Case " << gg << ':' << '\n';
		cin >> n;
		for (int i = 1; i <= n; ++i){
			for (int j = 1; j <= n; ++j){
				cin >> a;
				if(j!=n)cin>> c;
				if (a==0)continue;
				if(i<=j)edgeList.pb({i,j,a});
			}
		}
		
		for (int i = 0; i < 100; i++)p[i] = i;
		sort(edgeList.begin(), edgeList.end(), cmp);
		for (auto it : edgeList) {
			if (par(it.a) == par(it.b)) continue;
			p[par(it.a)] = par(it.b);
			c = 'A' + it.a-1;
			cout << c << '-';
			c = 'A' + it.b-1;
			cout << c << ' ' << it.w << '\n';
		}
	}
	//cout << '\n';
}
