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

int N,M;
int A[5000], B[5000], D[5000];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> N >> M;
	for (int i = 0; i < N; ++i)cin >> A[i];
	for (int i = 0; i < M; ++i)cin >> B[i];
	for (int i = 0; i < N; ++i){
		if (A[i] == B[0])D[0] = 1;
		/*
		for (int j = 0; j < M; ++j){
			D[i][j] = max(D[i-1][j], D[i][j-1]);
			if (A[i] == B[j])D[i][j] = max(D[i][j], D[i-1][j-1] + 1);
			ans = max(ans,D[i][j]);
		}
		*/
		for (int j = M-1; j >= 1; --j){
			D[j] = max(D[j], D[j-1]);
			if (A[i] == B[j])D[j] = max(D[j], D[j-1] + 1);
		}
		for (int j = 1; j < M; ++j){
			D[j] = max(D[j], D[j-1]);
		}
		//for (int i = 1; i < 
	}
	cout << *max_element(D,D+M);
}
