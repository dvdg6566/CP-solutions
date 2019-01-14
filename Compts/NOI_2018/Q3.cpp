#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
bool P[10000100];
#define mp make_pair
#define pb push
#define f first
#define s second
queue<pi> q;
stack<pi> sk;
stack<int> st6;
map<ll,bool>m;
bool st1 = 1, stf = 1;

inline int readInt() {
    int x = 0;
    char ch = getchar_unlocked();
    while (ch < '0' || ch > '9') ch = getchar_unlocked();
    while (ch >= '0' && ch <= '9'){
		x = (x << 3) + (x << 1) + ch - '0';
		ch = getchar_unlocked();
	}
    return x;
}

ll a,b,N,ans;
int main(){
	//freopen("input.txt","r",stdin);
	N = readInt();
	for (int i = 0; i < N; ++i){
		a = readInt();
		b = readInt();
		q.pb(mp(a,b));
		sk.pb(mp(a,b));
		if (b!=1)st1=0;
		if(b!=1&&b!=0)stf=0;
	}
	if (st1){
		cout << N; return 0;
	}
	if (stf){
		while (!q.empty()){
			a = q.front().f, b = q.front().s;
			q.pop();
			if (b == 0){
				st6.push(a);
			}else{
				P[a] = 1;
				ans++;
			}
		}
		while (st6.size()!=0){
			int x = st6.top();
			st6.pop();
			if (x != 0){
				if (P[x-1])continue;
			}
			if (P[x+1])continue;
			ans++;
		}
		cout << ans;
		return 0;
	}
	ll x = -100, y = -100;
	while (q.size()){
		ll cx = q.front().f, cy = q.front().s;
		q.pop();
		if (cx + cy <= x + y)continue;
		m[cx] = 1;
		x = cx;
		y = cy;
	}
	x = LONG_LONG_MAX, y = 0;
	while (sk.size()){
		ll cx = sk.top().f, cy = sk.top().s;
		sk.pop();
		if (y - cy >= x - cx)continue;
		if (m[cx])ans++;
		x = cx;
		y = cy;
	}
	cout << ans;
}