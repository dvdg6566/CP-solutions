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
typedef pair<string,int> psi;
vector<psi> V;
int N;
string S;
int fw[100100], D[100100];

void update(ll x, ll v) {
    for (; x<=N; x+=x&(-x)) fw[x] += v; 
}

ll sum(ll x) {
    ll res = 0;
    for(; x; x-=x&(-x)) res += fw[x];
    return res;
}

bool cmp(psi a, psi b){
	return a.f < b.f;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	/*
	cout << "2000\n";
	for (int i = 0; i < 2000; ++i){
		for (int j = 0; j < rand() % 10 + 3; ++j){
			char x = rand() % 26 + 'A';
			cout << x;
		}
		cout << '\n';
	}
	return 0;
	*/
	//freopen("input.txt","r",stdin);
	cin >> N;
	for (int i = 1; i <= N; ++i){
		cin >> S;
		V.pb(mp(S,i));
	}
	sort(V.begin(),V.end(),cmp);
	int c = 2;
	D[V[0].s] = 1;
	for (int i = 1; i < N; ++i){
		if(V[i].f == V[i-1].f){
			D[V[i].s] = c-1;
			continue;
		}
		D[V[i].s] = c;
		++c;
	}
	int ans = 0;
	for (int i = 1; i <= N; ++i){
		ans += sum(D[i] - 1);
		update(D[i],1);
	}
	cout << ans;
}
