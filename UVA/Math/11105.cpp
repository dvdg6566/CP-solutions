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
#define TOP 1000001
#define SQRT 1001

bool M[TOP+10];
int X[TOP+10];
vector<ll> P;int a;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	for (int i = 1; i <= TOP; i += 4)M[i] = 1;
	for (int i = 5; i <= TOP; i += 4){
		if (i > SQRT){
			if (M[i])P.pb(i);
			continue;
		}
		if (M[i]==0)continue;
		P.pb(i);
		for (ll j = i*i; j <= TOP; j += 4*i)M[j] = 0;
	}
	for (int i = 0; i < P.size(); ++i){
		for (int j = i; j < P.size(); ++j){
			if (P[i]*P[j]>TOP)break;
			X[P[i]*P[j]] = 1;
		}
	}
	for (int i = 5; i <= TOP; i += 4){
		X[i] += X[i-4];
	}
	while(cin>>a){
		if(!a)return 0;
		cout << a << ' ' << X[a] << '\n';
	}
}
