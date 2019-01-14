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

ll N,S,a;
queue<ll> Q;
ll lower,tot,ans;

inline ll readInt() {
    ll x = 0;
    char ch = getchar_unlocked();
    while (ch < '0' || ch > '9') ch = getchar_unlocked();
    while (ch >= '0' && ch <= '9'){
		x = (x << 3) + (x << 1) + ch - '0';
		ch = getchar_unlocked();
	}
    return x;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	N = readInt();
	S = readInt();
	for (int i = 0; i < N; ++i){
		a = readInt();
		Q.push(a);
		tot += a;
		while (tot > S){
			tot -= Q.front();Q.pop();
			lower++;
		}
		//cout << i << ' ' << lower << ' ' << tot << '\n';
		ans += (i+1-lower);
	}
	cout << ans;
}
