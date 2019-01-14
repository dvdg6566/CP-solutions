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

int A[2100], N, h[2100], B[2100], l, T, M;
int O[2100];

void LIS(int x){
	memset(h,0,sizeof(h));
	for (int i = l = 0; i < N-x; ++i){
		if (A[i+x] < A[x])continue;
		int p = lower_bound(h,h+l,A[i+x])-h;
		h[p] = A[i+x];
		l = max(p+1,l);
	}
	O[x] = l;
}

void LDS(int x){
	memset(h,0,sizeof(h));
	for (int i = l = 0; i < N-x; ++i){
		if (A[i+x] > A[x])continue;
		int p = lower_bound(h,h+l,B[i+x])-h;
		h[p] = B[i+x];
		l = max(p+1,l);
	}
	O[x]+=l;
}

  
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> T;
	while(T--){
		cin >> N;
		memset(A,0,sizeof(A));
		memset(B,0,sizeof(B));
		memset(O,0,sizeof(O));
		M = 0;
		for (int i = 0; i < N; ++i){
			cin >> A[i];
			M = max(M,A[i]);
		}
		for (int i = 0; i < N; ++i){
			B[i] = M+1-A[i];
		}
		for (int i = 0; i < N; ++i){
			LIS(i);
			LDS(i);
		}
		if (N==0)cout << 0 << '\n';
		else cout << *max_element(O,O+N)-1 << '\n';
	}
}
