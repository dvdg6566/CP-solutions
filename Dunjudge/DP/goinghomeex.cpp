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

struct edge {
    ll a, b, w;
    edge (ll _a=0, ll _b=0, ll _w=0): a(_a), b(_b), w(_w) {}
};
vector<edge> V;
bool cmp (edge x, edge y) { return x.b < y.b; } //Swap the comparator for maximum

map<ll,ll> M;
ll N,S,R,a,b,c,ind;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> N >> S >> R;
	M[0] = 0;
	for (int i = 0; i < S; ++i){
		cin >> a >> b >> c;
		M[a] = a*R;
		M[b] = b*R;
		if ((b-a)*R < c)continue;
		V.pb({a,b,c});
	}
	sort(V.begin(),V.end(),cmp);
	M[N] = N*R;
	for (auto i = ++M.begin(); i != M.end(); ++i){
		int index = (*i).f;
		int prev = (*(--i)).f;
		//cout << prev << ' ' << index << '\n';
		M[index] = min(M[index], M[prev] + (index - prev) * R); // If take taxi from previous location
		while (ind <= S){
			if (V[ind].b == index){
				M[index] = min(M[index], M[V[ind].a] + V[ind].w);
				++ind;
			}else break;
		}
		++i;
	}
	cout << M[N];
}
