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

int T, M, N;
int A[100100];

bool works(int x){
	int cur = A[0] + x;
	int cnt = 1;
	for (int i = 0; i < N; ++i){
		if (abs(cur-A[i]) <= x)continue;
		cur = A[i] + x;
		cnt ++;
	}
	if (cnt > M)return 0;
	return 1;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> T;
	while(T--){
		cin >> M >> N;
		memset(A,0,sizeof(A));
		for (int i = 0; i < N; ++i){
			cin >> A[i];
			A[i] *= 2;
		}
		sort(A,A+N);
		int low = 0, high = A[N-1];
		while(high > low+1){
			int mid = (high+low)/2;
			if (works(mid))high = mid;
			else low = mid;
		}
		if (works(low)) printf("%.1lf\n",(dl)low/2);
		else printf("%.1lf\n",(dl)high/2);
	}
}
