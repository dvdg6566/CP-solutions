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

ll A[1001000];
ll li, ui, ls, us, ans, N;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> N;
	for (int i = 1; i <= N; ++i)cin >> A[i];
	li = 1;
	ui = N;
	ls = A[1];
	us = A[N];
	while (li != ui){
		//cout << ls << ' ' << us << '\n';
		if (ls == us){
			//cout << li << ' ' << us << '\n';
			if (ui == li + 1){
				cout << ans;
				return 0;
			}else{
				++li; --ui;
				ls = A[li];
				us = A[ui];
			}
		}else if (ls < us){
			// Increment ls
			++li;
			++ans;
			ls += A[li];
		}else if (ls > us){
			// increment us
			--ui;
			++ans;
			us += A[ui];
		}
	}
	cout << ans;
}
