#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<int,int> pi;
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
	ll s, e, w;
	node (ll _s, ll _e, ll _w): s(_s), e(_e), w(_w){} 
};

ll N,a,b,w,T,ans;
priority_queue<ll, vector<ll>, greater<ll> > Q;
ll DP[1001000];
vector<node> V;

bool cmp(node a, node b){return a.s < b.s;}

void update(int x){
	while (Q.size()){
		if (Q.top() < x){
			T = max(DP[Q.top()], T);
			Q.pop();
		}else break;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> N;
	for (int i = 0; i < N; ++i){
		cin >> a >> b >> w;
		V.pb({a,b,w});
	}
	sort(V.begin(),V.end(), cmp);
	T = 0;
	for (auto i : V){
		//cout << i.s << ' ' << i.e << ' ' << i.w << '\n';
		update(i.s);
		if (T+i.w > DP[i.e]){
			DP[i.e] = T+i.w;
			Q.push(i.e);
		}
		//cout << "result " << i.e << ' ' << DP[i.e] << '\n';
		ans = max(DP[i.e], ans);
	}
	cout << ans;
}
