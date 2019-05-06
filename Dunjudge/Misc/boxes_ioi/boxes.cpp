#include "boxes.h"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<pair<int,int>> vpi;
typedef vector<int> vi;
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
ll INF = 1e15;

vector<ll> indeces;
vi people;

long long delivery(int N, int K, int L, int p[]) {
	for (int i=0;i<N;++i)if(p[i] != 0)people.pb(p[i]);
	sort(ALL(people));
	N = SZ(people);
	// cout<<N<<'\n';

	indeces.pb(-1);
    for (int i=0;i<=N;i+=K)indeces.pb(i);
    if (N%K != 0)indeces.pb(K*(1+N/K));

    // for (auto i : indeces)cout<<i<<' '; cout<<'\n';
    // for (int i=0;i<N;++i)cout<<people[i]<<' ';cout<<'\n';
    for (int i=N;i<=N+2*K+1;++i)people.pb(L);

    ll ans = INF;
	ll T = SZ(indeces);
	ll midway = L/2;

    for (int i=0;i<K;++i){
    	ll res = 0;
    	for (int it = 1; it < T; ++it){
    		ll x = indeces[it];
    		if (midway >= people[x]){
    			res += 2*people[x];
    			// cout<< "Add " << x << ' ' << 2*people[x]<<'\n';
    		}
    		else if (midway < people[x] && midway >= people[indeces[it-1] + 1] ){
    			res += L;
    			// cout<<"MIDWAY\n";
    		}
    		else {
    			ll y = max(0LL, x - K +1);
    			// cout<<"Add Opposite " << y << ' ' << 2*(L-people[y]) <<'\n';
    			res += 2*(L-people[y]);
    		}
    	}
    	// cout<<"For indeces at \n";
    	// for (int i=1;i<T;++i)cout<<indeces[i]<<' ';cout<<'\n';
    	// cout<<"Result is " << res << '\n' << '\n';
    	for (int i=1;i<T;++i)++indeces[i];
    	ans = min(ans, res);
    }

    return ans;
}