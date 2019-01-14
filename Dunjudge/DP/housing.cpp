#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<int,int> pi;
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

int DP[110][110],X;
/*
 * DP state: DP[i][j] represents allocating i people without any room with j or more
 * DP[i][j] = DP[i-j][j] + DP[i][j-1]
 * Base Case: 
*/

int query(int a, int b){
	//cout << a << ' ' << b << '\n';
	if (DP[a][b] != -1)return DP[a][b];
	if (b < 5) return DP[a][b] = 0;
	if (a < b)return DP[a][b] = max(0,query(a,b-1));
	return DP[a][b] = max(0,query(a-b,b)) + max(0,query(a,b-1));
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> X;
	memset(DP,-1,sizeof(DP));
	for (int i = 0; i <= X; ++i){
		DP[0][i] = 1;
	}
	cout << query(X,X);
	return 0;
	for (int i = 0; i <= X; ++i){
		for (int j = 0; j <= X; ++j)cout << DP[i][j] << ' ';cout << '\n';
	}
}
