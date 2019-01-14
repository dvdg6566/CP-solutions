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

int A[2100], N, h[2100], B[2100], l, T, M, W[2100];

int LIS(){
	memset(h,0,sizeof(h));
	for (int i = l = 0; i < N; ++i){
		int M = 0;
		for (int j = 0; j < i; ++j){
			if (A[j] >= A[i])continue;
			M = max(M,h[j]);
		}
		h[i] = M+W[i];
	}
	return *max_element(h,h+N);
}

int LDS(){
	memset(h,0,sizeof(h));
	for (int i = l = 0; i < N; ++i){
		int M = 0;
		for (int j = 0; j < i; ++j){
			if (B[j] >= B[i])continue;
			M = max(M,h[j]);
		}
		h[i] = M+W[i];
	}
	return *max_element(h,h+N);
}

  
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> T;
	for (int j = 1; j <= T; ++j){
		cin >> N;
		memset(A,0,sizeof(A));
		memset(B,0,sizeof(B));
		memset(W,0,sizeof(W));
		M = 0;
		for (int i = 0; i < N; ++i){
			cin >> A[i];
			M = max(M,A[i]);
		}
		for (int i = 0; i < N; ++i){
			B[i] = M+1-A[i];
		}
		for (int i = 0; i < N; ++i){
			cin >> W[i];
		}
		int I = LIS();
		int D = LDS();
		if (I>=D){
			cout << "Case " << j << ". Increasing (" << I << "). Decreasing (" << D << ").\n";
		}else{
			cout << "Case " << j << ". Decreasing (" << D << "). Increasing (" << I <<  ").\n";
		}
	}
}
