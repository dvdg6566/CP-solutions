#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
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
#define INF 1000000000

int N;
bool A[3001][3001];
list<int> L;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> N;
	for (int i = 1; i <= N; ++i)for (int j = 1; j <= N; ++j)cin >> A[i][j];
	cout << N << '\n';
	for (int i = 1; i <= N; ++i){
		if (L.size() == 0){L.pb(i);continue;}
		for (auto it = L.begin(); it != L.end(); ++it){
			if (A[i][*it]){
				L.insert(it, i);
				break;
			}
		}
		if (L.size() != i)L.pb(i);
	}
	/*
	L.pb(0);
	L.pb(2);
	L.pb(3);
	L.push_front(1);
	auto it = L.begin();
	L.insert(++it, 4);
	*/
	for (auto i : L)cout << i << ' ';
}
