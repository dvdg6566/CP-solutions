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
string S;
int DP[26][26];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// freopen("input.txt","r",stdin);
	cin >> N;
	for (int i = 0; i< 26; ++i){
		for (int j = 0; j < 26; ++j)DP[i][j] = -INF;
	}
	while(N--){
		cin >> S;
		int L = S.size();
		int a = S[0]-'a';
		int b = S[L-1] - 'a';
		//cout << a << ' ' << b << '\n';
		if (a == b){
			for (int i = 0; i < 26; ++i){
			  DP[i][a] += L;
      }
      DP[a][b] = max(DP[a][b],L);
		}else{
			DP[a][b] = max(DP[a][b], L);
			for (int i = 0; i < 26; ++i){
				DP[i][b] = max(DP[i][b], DP[i][a] + L);
			}
		}
	}
	// for (int i = 0; i < 26; ++i){for (int j = 0; j < 26; ++j)cout << DP[i][j]<< ' '; cout << '\n';}
	int ans = 0;
	for (int i = 0; i < 26; ++i)ans = max(ans, DP[i][i]);
	cout << ans;
}
