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

ll N,a,ans;
stack<pi> S;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> N;
	for (int i = 0; i < N; ++i){
		if(S.size())ans = max(ans,S.top().f*S.top().s);
		cin >> a;
		if (!S.size()){S.push(mp(a,1));continue;}
		if (a > S.top().f){S.push(mp(a,1));continue;}
		if (a == S.top().f){S.top().s ++; continue;}
		// a < S.top.f
		int tmp = 1;
		while(S.size()){
			if (S.top().f > a){
				tmp += S.top().s;
				ans = max((tmp-1)*S.top().f, ans);
				S.pop();
			}else break;
		}
		if (!S.size()){S.push(mp(a,tmp));continue;}
		if (a > S.top().f){S.push(mp(a,tmp));continue;}
		if (a == S.top().f){S.top().s += tmp; continue;}
	}
	int tmp = 0;
	while(S.size()){
		tmp += S.top().s;
		ans = max(ans,S.top().f*tmp);
		S.pop();
	}
	cout << ans;
}
