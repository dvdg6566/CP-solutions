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

set<pi> singles, doubles;
vpi V;
ll N,M,a,b,ans;

void run(){
	//cout << M << ' ' << ans << '\n';
	if (M == 1){
		--M;
		ans += (*singles.begin()).f;
		return;
	}
	if (!doubles.size()){
		++M;
		while(--M){
			pi cur = *singles.begin();
			//cout << cur.f << ' ' << cur.s << '\n';
			singles.erase(cur);
			ans += cur.f;
		}
		return;
	}
	--M;
	// If you want to choose double
	int sw = (*singles.begin()).f + (*(++singles.begin())).f;
	int dw = (*doubles.begin()).f;
	if (dw < sw){
		// two from the same farm are chosen. Choose the first mushroom and take it
		pi cur = *doubles.begin();
		ans += V[cur.s].f;
		doubles.erase(cur); // Remove from the doubles
		singles.erase( mp(V[cur.s].f, cur.s )); // Remove from the singles
		singles.insert( mp( V[cur.s].s, cur.s) ); // Add the 2nd mushroom 
		V[cur.s].f = -1; // Set that the mushroom has been taken
		return;
	}else{
		pi cur = *singles.begin();
		ans += cur.f;
		singles.erase(cur);
		if (V[cur.s].f == -1)return; //Removing second mushroom
		//Removing first mushroom
		doubles.erase( mp(V[cur.s].f+V[cur.s].s, cur.s ));//Remove from the doubles
		singles.insert( mp(V[cur.s].s, cur.s ));//Add 2nd mushroom into the singles
		V[cur.s].f = -1;//Mark the mushroom as taken
		return;
	}
}


int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> N >> M;
	for (int i = 0; i < N; ++i){
		cin >> a >> b;
		singles.insert(mp(a,i));
		doubles.insert(mp(a+b,i));
		V.pb(mp(a,b));
	}
	while(M)run();
	cout << ans;
}
