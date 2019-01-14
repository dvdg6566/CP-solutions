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

int P[10100][2],N;
int A[10100];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> N;
	for(int i = 1; i < N; ++i)cin >> A[i];
	for (int i = 0; i < N; ++i){P[i][0] = P[i][1] = INF;}
	P[1][0] = 0;
	for (int i = 1; i < N; ++i){
		for (int j = i+1; j >= 1; --j){
			//Changing P[j][1]
			if (P[j][0] != -1)P[j][1] = min(P[j][1],P[j][0] + A[i]);
			//Changing P[j][0]
			P[j][0] = min(P[j-1][1] + A[i], P[j-1][0]);
		}
	}
	cout << min(P[N/2][0],P[N/2][1]);
}
