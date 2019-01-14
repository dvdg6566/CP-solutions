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

int N, arr[2001000], sum, res,ans,tot,chk=1;
int leftDP[2001000];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	res = -INF;
	cin >> N;
	for(int i = 1;i <= N; ++i){
		cin>>arr[i];
		if(arr[i]>=0)chk=0;
		leftDP[i] = max(arr[i],leftDP[i-1] + arr[i]);
		tot += arr[i];
	}
	if(chk){
		sort(arr+1,arr+N+1);
		cout << arr[N] + arr[N-1];
		return 0;
	}
	// Case one is where there is no wrapping around. 
	sum = 0;
	ans = -INF;
	for (int i = N; i >= 1; --i){
		sum = max(arr[i],sum + arr[i]);
		ans = max(sum,ans);
		res = max(res,leftDP[i-1] + ans);
	}
	memset(leftDP,0,sizeof(leftDP));
	for (int i = 1; i <= N; ++i){
		leftDP[i] = min(arr[i],leftDP[i-1]+arr[i]);
	}
	// Case 2 is where there is wrapping around
	sum = 0;
	ans = INF;
	for (int i = N; i >= 1; --i){
		sum = min(arr[i],sum+arr[i]);
		ans = min(sum,ans);
		res = max(res,tot-leftDP[i-1]-ans);
	}
	cout << res;
}
