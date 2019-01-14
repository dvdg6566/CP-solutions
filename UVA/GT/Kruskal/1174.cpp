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
int p[10000];
int par(int x) { return (x==p[x])?x:p[x]=par(p[x]);}
void merge(int a, int b) {p[par(a)] = par(b);}
vector<edge> edgeList;
bool cmp (edge x, edge y) { return x.w < y.w; } 

int t,a,b,w,cnt,m,n;
string str;
map<string,int> M;

int main(){
	//freopen("input.txt","r",stdin);
	cin >> t;
	while(t--){
		M.clear();
		edgeList.clear();
		cin >> m >> n;
		cnt = 1;
		for (int i = 0; i < n; ++i){
			cin >> str;
			if (M[str] == 0){
				M[str]=cnt;
				a=cnt;
				cnt++;
			}else a=M[str];
			cin >> str;
			if (M[str] == 0){
				M[str]=cnt;
				b=cnt;
				cnt++;
			}else b=M[str];
			cin >> w;
			edgeList.pb({a,b,w});
		}
		w=0;
		for (int i = 0; i < 10000; i++)p[i] = i;
		sort(edgeList.begin(), edgeList.end(), cmp);
		for (auto it : edgeList) {
			if (par(it.a) == par(it.b)) continue;
			p[par(it.a)] = par(it.b);
			w+=it.w;
		}
		cout << w << '\n';
		if(t!=0)cout << '\n';
	}
}
