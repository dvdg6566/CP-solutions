#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
#define MOD 1000000007LL
ll fw[100100];
ll N,R,T,X,Y;
ll W,D;

ll qmult(ll a, ll b){
   if(b == 0) return 0;
   ll H = qmult(a, b/2);
   H %= MOD;
   H += H;
   H %= MOD;
   if(b % 2 == 1) H += a;
   H %= MOD;
   return H;
}

void update(int x, ll v) {
    for (; x<=N; x+=x&(-x)) {
		fw[x] = (fw[x]+v)%MOD;
    }
}
int sum(int x) {
	if(x==0)return 0;
    ll res = 0;
    for(; x; x-=x&(-x)){
      res = (res+fw[x])%MOD;
    }
    return res;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  //freopen("input.txt","r",stdin);
  cin >> R >> N;
  for (int i = 1; i <= N; ++i){
    cin >> T;
    update(i,T);
  }
  for (int i = 0; i < R; ++i){
    cin >> X >> W >> D >> Y;
    ll t = W/D;
    // S = ut + 1/2 at^2
    ll S = (t)*W - t*(t-1)*D/2;
    ll end = (S+X) % N;
    if (!end)end = N;
    ll rnd = (S+X)/N;
    //cout << S << ' ' << end << ' ' << rnd << '\n';
    //cout << sum(N) << ' ' << rnd << ' ' << sum(X) << ' ' << sum(end) << '\n';
    ll res = qmult(sum(N),rnd) - sum(X-1) + sum(end);
    res = res % MOD;
    if(res<0)res += MOD;
    cout << res << '\n';
    update(X,Y);
  }
}
