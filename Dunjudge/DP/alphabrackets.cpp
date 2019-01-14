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

string S;
stack <int> Stk;
int DP[2000001], P[2000001];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> S;
	memset(P,-1,sizeof(P));
	for (int i = 0; i < S.size(); ++i){
		if (isupper(S[i])){
			Stk.push(i);
			continue;
		}
		if (!Stk.size())continue;
		if (S [Stk.top()] == toupper(S[i])){
			P[i] = Stk.top();
			Stk.pop();
		}else{
			while(Stk.size())Stk.pop();
		}
	}
	ll ans = 0;
	for (int i = 0; i < S.size(); ++i){
		if(P[i] != -1)DP[i] = DP[P[i]-1] + 1;
		ans += DP[i]; 
	}
	cout << ans;
	//for (auto i : M)cout << i.f << ' ' << i.s << '\n';
}
