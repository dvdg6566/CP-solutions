#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MOD 1e9+7
#define lb lower_bound
#define ub upper_bound
#define dst distance
#define INF 1000000000

int N,D,a,tot;
vi V;

bool finish(int x){
	int curr = 0, days = D;
	for (auto i : V){
		if (curr + i <= x)curr += i;
		else {
			curr = i;
			days--;
		}
	}
	return days > 0;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	while(1){
		cin >> N;
		if(cin.eof())return 0;
		cin >> D;
		D++;
		V.clear();
		tot = 0;
		for (int i = 0; i <= N; ++i){cin >> a;V.pb(a);tot+=a;}
		int low = *max_element(V.begin(),V.end()), upp = tot;
		while(upp-low>1){
			int mid = (upp+low)/2;
			if (finish(mid))upp = mid;
			else low = mid;
		}
		if (finish(low))cout << low << '\n';
		else cout << upp << '\n';
	}
}
