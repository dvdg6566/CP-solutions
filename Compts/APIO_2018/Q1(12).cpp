#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MOD 1e9+7
#define lb lower_bound
#define ub upper_bound
#define dst distance
#define INF 1e18

struct event{
	ll time, index, loc, type, action;
	event(ll a=0,ll b=0,ll c=0, ll d=0, ll e=0): time(a),index(b),loc(c),type(d),action(e){} 
	// Action is 0 for query, 1 for add and -1 for delete
};

bool cmp (event a, event b){
	if (a.time != b.time) return a.time < b.time;
	return a.action > b.action;
}

ll N,K,Q,a,b,c,d;
vector<event> V;
multiset<ll> street[500];
ll output[70000];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("input.txt","r",stdin);
	cin >> N >> K >> Q;
	for (int i = 0; i < N; ++i){
		cin >> a >> b >> c >> d;
		V.pb({c,i,a,b,1});
		V.pb({d,i,a,b,-1});
	}
	for (int i = 0;i < Q; ++i){
		cin >> a >> b;
		V.pb({b,i,a,-1,0});
	}
	sort(V.begin(),V.end(),cmp);
	for (int i = 1; i <= K; ++i){
		street[i].insert(-INF);
		street[i].insert(INF);
	}
	for (auto i : V){
		if (i.action == 0){
			ll res = 0;
			for (int j = 1; j <= K; ++j){
				if(street[j].size() == 2){res = -1; break;}
				ll l = abs(i.loc-*(street[j].lb(i.loc)));
				ll r = abs(i.loc-*(--(street[j].ub(i.loc))));
				res = max(res,min(l,r));
			} 
			output[i.index] = res;
		}
		if(i.action == -1){
			street[i.type].erase(street[i.type].find(i.loc));
		}
		if(i.action == 1){
			street[i.type].insert(i.loc);
		}
	}
	for (int i = 0; i < Q; ++i){
		cout << output[i] << '\n';
	}
}
