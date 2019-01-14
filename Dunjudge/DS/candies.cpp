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

int fw[1000100];
int cnt[1000100];
int N,a,b,res;

void update(int x, int v) {
    for (; x<=N; x+=x&(-x)) fw[x] += v; 
}

int sum(int x) {
    int t = 0;
    for(; x; x-=x&(-x)) t += fw[x];
    return t;
}

void binsrch(int low, int upp){
	//cout << low << ' ' << upp << '\n';
	while (upp - low > 1){
		int mid = (upp+low)/2;
		if (sum(mid) != mid)upp = mid;// too high
		else low = mid;
	}
	//cout << low << ' ' << upp << '\n' << '\n';
	if (sum(upp) == upp)res = upp;
	else res = low;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> N;
	for (int i = 0; i < N; ++i){
		cin >> a >> b;
		if (b > 1000050){cout << res << '\n';continue;}
		if (a == 1){
			if (cnt[b]){
				cnt[b]++;
				
			}else{
				update(b,1);
				cnt[b] = 1;
				binsrch(res,N);
				cout << res << '\n';
			}
		}else if (a == 2){
			if (!cnt[b]){
				cout << res << '\n';
			}
			else if (cnt[b] > 1){
				cnt[b] --;
				cout << res << '\n';
			}else{
				update(b,-1);
				cnt[b] = 0;
				binsrch(0,b);
				cout << res << '\n';
			}
		}
		cout << res << '\n';
	}
}
