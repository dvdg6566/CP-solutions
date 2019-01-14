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

vi adjList[201000];
int N,a,Q;

void dfs(int x){
	for (auto i : adjList[x]){
		p[i][0] = x;
		depth[i] = depth[x] + 1;
		dfs(i);
		desc[x] += desc[i];
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("input.txt","r",stdin);
	cin >> N;
	for (int i = 1; i <= N; ++i){
		cin >> a;
		if (i!=1) adjList[a].pb(i);
	}
	dfs(1);
	for (int i = 1; i <= N; ++i)cout << desc[i] << ' ' ;
	for (int i = 1; i < 19; i++){
		for (int j = 1; j <= N; j++){
			if (p[j][i-1] == -1) p[j][i] = -1;
			else p[j][i]=p[p[j][i-1]][i-1];
		}
	}
	cin >> Q;
	
}

