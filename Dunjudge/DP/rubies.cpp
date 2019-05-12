#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef pair<ll,ll> pii;
typedef vector<pi> vpi;
typedef set<ll> si;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define f first
#define s second
ll INF = 1e9;
ll MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (ll)x.size()
#define ALL(x) x.begin(),x.end()
ld eps = 1e-11;
ll N,L,R;
pi A[500100];
ld st[500100];
deque<pair<ld,int>> dq;
ld dp[500100];

void insert(int x){
	if (SZ(dq) && dq[0].s <= x-R-1)dq.pop_front();
	while(SZ(dq) && dq.back().f > st[x-L]){
		// cout<<"Remove " << dq.back().s<<'\n';
		dq.pop_back();
	}
	dq.pb(mp(st[x-L], x-L));
	// cout<<"Append " << x-L<<' '<<st[x-L]<<'\n';
}

bool query(ld p){
	for (int i=1;i<=N;++i){
		st[i] = ((ld) A[i].f - p * ((ld) A[i].s));
		st[i] += st[i-1];
	}
	// for (int i=1;i<=N;++i)cout<<st[i]<<' ';cout<<'\n';
	dq.clear();
	for (int i=L;i<=N;++i){
		insert(i);
		if(st[i] >= dq[0].f)return 1;
	}
	return 0;
}

int main(){
	// freopen("in.txt","r",stdin);
	cin >> N >> L >> R;
	for (int i=1;i<=N;++i)cin >> A[i].f >> A[i].s;
	// cout<<query(0.45)<<'\n';
	ld lower = 0;
	ld upper = 1e6;
	while(upper - eps > lower){
		ld mid = (upper + lower)/2;
		int r = query(mid);
		// printf("%.9Lf %d\n",mid,r);
		if (r)lower = mid;
		else upper = mid;
	}
	printf("%.11Lf ",lower);
}