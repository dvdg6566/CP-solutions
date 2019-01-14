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

int N,D,cnt,A;
pi degree[2000];
string st1,st2,st3;
map<string,int>M;
vector<string> V;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> N >> D;
	V.pb("");
	for (int i = 0; i < N-D+1; ++i){
		cin >> st1;
		st2 = st1.substr(0,D-1);
		st3 = st1.substr(1,D-1);
		if (!M[st2]){cnt++;M[st2] = cnt;V.pb(st2);}
		if (!M[st3]){cnt++;M[st3] = cnt;V.pb(st3);}
		degree[M[st2]].f++;
		degree[M[st3]].s++;
	}
	for (int i = 1; i <= cnt; ++i){
		if (degree[i].f>degree[i].s)cout << V[i][0];
	}
	for (int i = 1; i <= cnt; ++i){
		if (degree[i].f<degree[i].s)cout << V[i][D-2];
	}
}
