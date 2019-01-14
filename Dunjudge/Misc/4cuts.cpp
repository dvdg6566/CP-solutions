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
#define INF 1000000000000000000

int N;
ll A[2001000],ans=INF,a,b;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin>>N;
	for(int i =1;i<=N;++i){cin>>A[i];if(i)A[i] += A[i-1];}
	for (int i =1;i<N;++i){
		ll big = 0;
		ll small = INF;
		ll L = (A[i]+A[1])/2;
		//cout << L << '\n';
		auto it = lb(A,A+N,L);
		auto jt = --it;
		++it;
		if (abs(*it-L) < abs(*jt-L)){
			a = *it;
			b = A[i] - *it;
		}else{
			a = *jt;
			b = A[i] - *jt;
		}
		//cout << a << ' ' << b << '\n';
		small = min(small,a);
		big = max(big,a);
		small = min(small,b);
		big = max(big,b);
		
		L = (A[N] + A[i])/2;
		it = lb(A,A+N,L);
		jt = --it;
		++it;
		if (abs(*it-L) < abs(*jt-L)){
			a = *it-A[i];
			b = A[N] - *it;
		}else{
			a = *jt-A[i];
			b = A[N] - *jt;
		}
		small = min(small,a);
		big = max(big,a);
		small = min(small,b);
		big = max(big,b);
		//cout << a << ' ' << b << '\n';
		ans = min(ans,big-small);
	}
	cout << ans;
}
