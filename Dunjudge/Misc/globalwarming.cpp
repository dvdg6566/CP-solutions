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

int V[1001000];
vpi V2;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
   int size;
   int i,a;

   cin >> size;
   V[0] = -1;
   int ind = 1;
   for (i=0; i<size; i++){
     cin >> a;
     if(V[ind-1] == a)continue;
     V[ind] = a;
     ++ind;
   }
	V[ind] = -1;
	++ind;
	for (int i = 1; i + 1 < ind; ++i){
		if (V[i] > V[i-1] && V[i] > V[i+1]){
			V2.pb(mp(V[i],1));
		}
		if (V[i] < V[i-1] && V[i] < V[i+1]){
			V2.pb(mp(V[i],-1));
		}
	}
	int prev = -INF;
	int cur = 0;
	int ans = 0;
	sort(V2.begin(),V2.end());
	reverse(V2.begin(),V2.end());
	for (auto i : V2){
		if (i.f != prev){
			ans = max(ans,cur);
		}
		prev = i.f;
		cur += i.s;
	}
   cout << ans;

}
