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

int gcd(int a, int b){
	if(a==0)return b;
	return gcd(b%a,a);
}

int lcmh(int a, int b){return a*b/gcd(a,b);}

int lcm(int a, int b, int c, int d){
	c = lcmh(min(c,d),max(c,d));
	b = lcmh(min(b,c),max(b,c));
	return lcmh(min(a,b),max(a,b));
}

int N,T,a;
vi V;

void run(int x){
	int low=0,high=INF;
	for(int i = 3; i < N; ++i){
		for(int j = 2; j < i; ++j){
			for(int k = 1; k < j; ++k){
				for(int l=0; l < k; ++l){
					int LCM = lcm(V[i],V[j],V[k],V[l]);
					if(x%LCM==0){
						cout << x << ' ' << x << '\n';
						return;
					}
					int t = x/LCM;
					low = max(low,t*LCM);
					high = min(high,(t+1)*LCM);
				}
			}
		}
	}
	cout << low << ' ' << high << '\n';
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	while(cin>>N>>T){
		if(!N&&!T)return 0;
		V.clear();
		for(int i = 0; i < N; ++i){cin>>a;V.pb(a);}
		for(int i = 0; i < T; ++i){cin>>a;run(a);}
	}
}
