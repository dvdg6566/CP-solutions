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

int res[500100], nxt[500100], cur[500100];
stack<int> stk;
int N,a;

void dfs(int x){
	if (res[nxt[x]] != -1){
		res[x] = res[nxt[x]] + 1;
	}else if (nxt[x] == x){
		res[x] = 1;
	}else if (cur[nxt[x]] != 0 && res[nxt[x]] == -1){
		int cyclen = a+1-cur[nxt[x]];
		while (stk.size()){
			int t = stk.top();
			stk.pop();
			res[t] = cyclen;
			if(t == nxt[x])break;
		}
	}else{
		stk.push(nxt[x]);
		++a;
		cur[nxt[x]] = a;
		dfs(nxt[x]);
		if(res[x] == -1){
			// No cycles in the future involving node x
			res[x] = res[nxt[x]] + 1;
			stk.pop();
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("input.txt","r",stdin);
	cin >> N;
	for (int i = 0; i < N; ++i)cin >> nxt[i];
	memset(res,-1,sizeof(res));
	for (int i = 0; i < N; ++i){
		if (res[i]!=-1)continue;
		a = 1;
		cur[i] = a;
		stk.push(i);
		dfs(i);
	}
	for (int i = 0; i < N; ++i){
		cout << res[i] << ' ';
	}
}
