#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef double dl;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MOD 1e9+7
#define lb lower_bound
#define ub upper_bound
#define dst distance
#define INF 1000000000

struct node{
	int a,b,c;
	node (int _a= 0, int _b = 0, int _c = 0): a(_a), b(_b), c(_c){}
};

vector<node> V;
int DP[60],N,x,y,z;
bool cmp(node a, node b){
	if (a.c != b.c)return a.c < b.c;
	if (a.b != b.b) return a.b < b.b;
	return a.a < b.a;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input,txt","r",stdin);
	cin >> N;
	for (int i = 0; i < N; ++i){
		cin >> x >> y >> z;
		if (x>y)swap(x,y);
		if (y>z)swap(y,z);
		if (x>y)swap(x,y);
		assert(x<=y && y <= z);
		V.pb({x,y,z});
	}
	sort(V.begin(),V.end(),cmp);
	DP[0] = 1;
	for (int i = 1; i < N; ++i){
		DP[i] = 1;
		//cout << V[i].a << ' ' << V[i].b << ' ' << V[i].c << '\n';
		for (int j = 0; j < i; ++j){
			if(V[i].a < V[j].a)continue;
			if(V[i].b < V[j].b)continue;
			if(V[i].c < V[j].c)continue;
			DP[i] = max(DP[i],DP[j]+1);
		}
	}
	cout << *max_element(DP,DP+N);
}
