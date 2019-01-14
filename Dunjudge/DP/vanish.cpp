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
#define MOD 1000000007LL
#define lb lower_bound
#define ub upper_bound
#define dst distance
#define INF 1000000000

map<ll,ll>M;
vector<ll>V;
ll N,a;
ll DP[500100];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> N;
	for (int i = 0; i < N; ++i){
		cin >> a;
    M[a]++;
  }
  V.pb(-1);
  for (auto i : M)V.pb(i.f);
  DP[1] = M[V[1]] * V[1];
	for (int i = 2; i < V.size(); ++i){
		if (V[i] == V[i-1]+1){
      DP[i] = max(DP[i-1], M[V[i]] * V[i] + DP[i-2]);
    }
    else DP[i] = M[V[i]] * V[i] + DP[i-1];
    // cout<<DP[i]<<'\n';
	}
	cout << DP[V.size()-1];
}
/*
for each i
if i and i-1 are consecutive, R = DP[i-1] + V[i];
else R = DP[i-2] + V[i]
if i and i+1 are consecutive, DP[i+1] = R;
else DP[i] = R;
*/
