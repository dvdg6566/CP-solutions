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
ll INF = 1e18;

int N;
ll A[201000],ans=INF,a,b,c,d,e,f,g,h;

ll query(ll a, ll b, ll c, ll d){
  //cout<<a<<' '<<b<<' '<<c<<' '<<d<<'\n';
  return max({a,b,c,d}) - min({a,b,c,d});
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin>>N;
	for(int i =1;i<=N;++i){cin>>A[i];if(i)A[i] += A[i-1];} 
	for (int i =1;i<=N;++i){
		ll big = 0;
		ll small = INF;
		ll L = A[i]/2;

		auto it = ub(A+1,A+N+1,L);
		auto jt = --it;
		++it;
    a = *it;
    b = A[i] - *it;
    c = *jt;
    d = A[i] - *jt;

		L = (A[N] + A[i])/2;
		it = ub(A+1,A+N+1,L);
		jt = --it;
		++it;
		
		e = *it - A[i];
    f = A[N] - *it;
    g = *jt - A[i];
    h = A[N] - *jt;

    //cout<<a<<' '<<b<<' '<<c<<' '<<d<<' '<<e<<' '<<f<<' '<<g<<' '<<h<<'\n';
    ans = min({ans, query(a,b,e,f), query(a,b,g,h), query(c,d,e,f), query(c,d,g,h)});
	}
	cout << ans;
}