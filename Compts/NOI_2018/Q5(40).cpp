#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
ll p[10010],S[10010],N,H,M,C[210010];
deque<pi> dq;
#define pb push_back
#define mp make_pair
#define f first
#define s second

int main(){
	//freopen("input.txt","r",stdin);
	cin >> N >> H;
	for (int i = 0; i < N; ++i){
		cin >> C[i];
	}
	M = *max_element(C,C+N);
	if (H == 0){
		// ST 4
		assert(0);
		sort(C,C+N);
		int act = C[N/2];
		ll ans = 0;
		for (int i = 0; i < N; ++i){
			ans += abs(act-C[i]);
		}
		cout << ans;
		return 0;
	}
	for (int i = 0; i <= M; ++i){
		S[i] = abs(C[0]-i);
	}
	for (ll i = 1; i < N; ++i){
		for (ll j = 0; j <= min(H,M); ++j){
			while(dq.size()){
				if(dq.back().s >= S[j])dq.pop_back();
				else break;
			}
			dq.pb(mp(j,S[j]));
		}
		for (ll j = 0; j <= M; ++j){
			if(j+H <= M){
				while(dq.size()){
					if(dq.back().s >= S[j+H])dq.pop_back();
					else break;
				}
				dq.pb(mp(j+H,S[j+H]));
			}
			p[j] = dq.front().s + abs(j-C[i]);
			if(dq.front().f == j-H)dq.pop_front();
		}
		swap(p,S);
		dq.clear();
	}
	//for (int i = 0; i <= M; ++i)cout << S[i] << '\n';
	cout << *min_element(S,S+M+1);
}
