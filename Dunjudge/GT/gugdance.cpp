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

int N,a;
int A[500001], B[500100];
vi V,V2;
vpi E;

void chain (int x){
	if(V.size())if(x == V[0])return;
	V.pb(x);
	A[x] = -2;
	chain(B[x]);
}

bool cmp(pi a, pi b){
	return a.f > b.f;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> N;
	memset(A,-1,sizeof(A));
	for (int i = 0; i < N; ++i)cin >> B[i];
	for (int i = 0; i < N; ++i){
		if (A[i] != -1)continue;
		if (B[i] == i){
			A[i] = i; // If the cycle length is 1
		}
		V.clear();
		chain(i);
		if (V.size() % 2 == 1){
			int l = 0, u = V.size() / 2 + 1;
			while (l <= V.size() / 2 && u < V.size()){
				A[V[l]] = V[u];
				l++;
				A[V[u]] = V[l];
				u++;
			}
			A[V[l]] = V[0];
		}else{
			E.pb(mp(V.size(),i));
		}
	}
	sort(E.begin(),E.end(),cmp);
	for (int i = 0; i < E.size(); ++i){
		V.clear();
		V2.clear();
		chain(E[i].s);
		swap(V,V2);
		++i;
		chain(E[i].s);
		for (int j = 0; j < V.size(); ++j){
			A[V[j]] = V2[j];
			if(j+1 != V.size()) A[V2[j]] = V[j+1];
			else A[V2[j]] = V[0];
		}
	}
	for (int i = 0; i < N; ++i)cout << A[i] << ' ';
}
