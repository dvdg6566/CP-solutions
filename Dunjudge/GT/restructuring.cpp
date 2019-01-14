//#include "restructuring.h"
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

set<int> S;
stack<int> st;
int p[200001];
int par(int x) { return (x==p[x])?x:p[x]=par(p[x]);}
void merge(int a, int b) {p[par(a)] = par(b);}

void init(int N) {
	for (int i = 0; i < N; ++i){S.insert(i);p[i] = i;}
}

void merge_two(int x, int y) {
	x = *S.lb(x);
	y = *S.lb(y);
	if(par(x) != par(y))merge(x,y);
}

void merge_all(int x, int y) {
	int M = *S.lb(y);
	for (auto i = S.lb(x); i != S.lb(y); ++i){
		st.push(*i);
	}
	while(st.size()){
		S.erase(st.top());
		merge(st.top(),M);
		st.pop();
	}
}

bool is_same_department(int x, int y) {
	return par(*S.lb(x)) == par(*S.lb(y));
}

int N, Q;

int main() {
	freopen("input.txt","r",stdin);
	scanf("%d%d", &N, &Q);
	init(N);
	while (Q--) {
		int op, a, b;
		scanf("%d%d%d", &op, &a, &b);
		if (op == 0) merge_two(a, b);
		else if (op == 1) merge_all(a, b);
		else printf("%d\n", is_same_department(a, b));
	}
}


