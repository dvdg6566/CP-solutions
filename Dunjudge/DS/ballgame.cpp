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

vpi V,O;

ll fw[]
void update(ll x, ll v) {
    for (; x<=N; x+=x&(-x)) fw[x] += v; 
}

ll sum(ll x) {
    ll res = 0;
    for(; x; x-=x&(-x)) res += fw[x];
    return res;
}
