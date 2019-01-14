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

int N,A[1000010], D[1000010];
int h[1000010],l,ans;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> N;
	for (int i = 0; i < N; ++i)cin >> A[i];
	for (int i = l = 0; i < N; ++i){
		int p = lower_bound(h,h+l,A[i])-h;
		h[p] = A[i];
		l = max(p+1,l);
		D[i] = l;
	}
	memset(h,-1,sizeof(h));
	reverse(A,A+N);
	for (int i = l = 0; i < N; ++i){
		int p = lower_bound(h,h+l,A[i])-h;
		h[p] = A[i];
		l = max(p+1,l);
		ans = max(ans, l+D[N-i]-1);
	}
	cout << ans;
}
