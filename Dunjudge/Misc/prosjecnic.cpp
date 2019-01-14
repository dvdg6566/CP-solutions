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

int N;
int A[105][105];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> N;
	if (N%2){
		for (int i = 1; i <= N*N; ++i){
			cout << i;
			if (i%N == 0)cout << '\n';
			else cout << ' ';
		}
	}else{
		if (N == 2){cout << -1; return 0;}
		A[0][0] = 103000;
		A[0][1] = 102000;
		A[0][2] = 101000;
		A[0][3] = 106000;
		for (int i = 4; i <= N; i += 2){
			A[0][i] = A[0][0] + i * 1000;
			A[0][i+1] = A[0][0] + i * -1000;
		}
		for (int i = 0; i < N; ++i){
			A[1][i] = A[0][i] - 1;
			A[2][i] = A[0][i] - 2;
			A[3][i] = A[0][i] + 3;
			for (int j = 4; j <= N; j += 2){
				A[j][i] = A[0][i] + j;
				A[j+1][i] = A[0][i] - j;
			}
		}
		for (int i = 0; i < N; ++i){
			for (int j = 0; j < N; ++j)cout << A[i][j] << ' ';
			cout << '\n';
		}
	}
}
