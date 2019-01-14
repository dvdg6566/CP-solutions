#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<int,int> pi;
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

vpi V;
set<int> S;
multiset<int> W;
int N,res=INF,a,b,C;
map<int,int> M;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> N;
	for (int i = 0; i < N; ++i){
		cin >> a >> b;
		V.pb(mp(a,b));
		S.insert(b);
	}
	sort(V.begin(),V.end());
	for (auto i : V){
		if(M[i.s] == 0){
			C++;
		}
		else {
			//cout << "erasing " << M[i.s] << '\n';
			W.erase(W.find(M[i.s]));
		}
		M[i.s] = i.f;
		W.insert(i.f);
		//cout << "adding " << i.f << '\n';
		if (C == S.size()){
			//cout << "updating " << i.f-*W.begin() << '\n';
			res = min(res, i.f-*W.begin() );
		}
	}
	cout << res;
}
