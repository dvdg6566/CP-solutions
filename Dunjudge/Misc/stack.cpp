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

int N,M,a;
int A[3001000];
vi V;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("input.txt","r",stdin);
	cin >> N >> M;
	for (int i = 0; i < N; ++i)cin >> a;
	for (int i = 0; i < M; ++i)cin >> A[i];
	sort(A,A+M);
	for (int i = 0; i < M; ++i){
		int cnt = 0, act = A[i];
		while (i < M){
			++i;
			if (A[i] == A[i-1])++cnt;
			else break;
		}
		V.pb(
	}
}
