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

ll N,F,a,b,w;
ll dp[3000];

struct edge {
    ll a, b, w;
    edge (ll _a=0, ll _b=0, ll _w=0): a(_a), b(_b), w(_w) {}
};
vector<edge> V;
bool cmp (edge x, edge y) { 
	if(x.a != y.a)return x.a < y.a; 
	return x.b < y.b;
} //Swap the comparator for maximum


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("input.txt","r",stdin);
	cin >> N >> F;
	for (int i = 0; i < N; ++i){
		cin >> a  >> b >> w;
		V.pb({a,b,w});
	}
	sort(V.begin(),V.end(),cmp);
	dp[0] = V[0].w;
	for (int i = 1; i < N; ++i){
		dp[i] = V[i].w;
		for (int j = 0; j < i; ++j){
			if(V[j].b <= V[i].b){
				dp[i] = max(dp[i],dp[j] + V[i].w);
			}
		} 
	}
	//for (int i = 0; i < N; ++i)cout << dp[i] << ' ';cout << '\n';
	//for (auto i : V)cout << i.a << ' ' << i.b << '\n';
	cout << *max_element(dp,dp+N) << ' ' << 0;
}
