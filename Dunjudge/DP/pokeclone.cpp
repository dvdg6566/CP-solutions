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

int N,A[16000], h[16000],l;
int LIS[16000], LDS[16000];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> N;
	for (int i = 0; i < N; ++i)cin >> A[i];
	memset(h,0,sizeof(h));
	for (int i = l = 0; i < N; ++i){
		int p = lower_bound(h,h+l,A[i])-h;
		h[p] = A[i];
		l = max(p+1,l);
		LIS[i] = l;
	}
	
	memset(h,0,sizeof(h));
	reverse(A,A+N);
	for (int i = l = 0; i < N; ++i){
		int p = lower_bound(h,h+l,A[i])-h;
		h[p] = A[i];
		l = max(p+1,l);
		LDS[i] = l;
	}
	reverse(LDS,LDS+N);
	int ans = 0;
	for (int i = 0; i < N; ++i){
		ans = max(ans, min(LIS[i],LDS[i])*2-1 );
	}
	cout << ans;
}
