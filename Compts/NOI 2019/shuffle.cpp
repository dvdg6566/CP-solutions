#include "shuffle.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;

#define pb push_back
#define mp make_pair
#define f first 
#define s second
#define SZ(x) x.size()
#define ALL(x) x.begin(), x.end()

int A[1010];
vi four, six;
vi out;
int indexes[1010];
vi di;
vector<vi> tbl;

vector<int> solve(int N, int B, int K, int Q, int ST) {
	if (ST == 4 || ST == 2){
		assert(K==2);
		deque<int> odd, even;
		vector<vector<int>> V;
		for(int i=1;i<=N;i+=2){
			odd.pb(i);
			even.pb(i+1);
		}
		V.resize(B);
		for (int i=0;i<B;++i)V[i].resize(2);
		for (int i=0;i<B;++i){
			V[i][0] = odd[i];
			V[i][1] = even[i];
		}
		vector<vector<int>> res = shuffle(V);
		
		for (auto i : res){
			int a = min(i[0], i[1]);
			int b = max(i[0], i[1]);
			A[a] = b;
			//cout<<"Results "<< a << ' ' << b << '\n';
		}
		swap(V[0][1], V[1][1]);
		vector<vi> r2 = shuffle(V);
		for (int i=0;i<B;++i){
			int a = r2[i][0]; int b = r2[i][1];
			if(b<a)swap(a,b);
			//cout<<"Results "<< a << ' ' << b << '\n';
			if (A[a] == b)continue;
			four.pb(a);
			four.pb(b);
		}
		swap(V[0][1], V[1][1]);
		swap(V[2][1], V[0][1]);
		
		vector<vi> r3 = shuffle(V);
		for (int i=0;i<B;++i){
			int a = r3[i][0]; int b = r3[i][1];
			if(b<a)swap(a,b);
			//cout<<"Results "<< a << ' ' << b << '\n';
			if (A[a] == b)continue;
			six.pb(a);
			six.pb(b);
		}
		
		int rep[1000],a=0,b=0;
		for (auto i : four)rep[i]++;
		for (auto i : six)if (rep[i]){
			if (a == 0)a = i;
			else b = i;
		}	
		swap(V[2][1], V[1][1]);
		for (int i=0;i<B;++i){
			V[i][1] = even[(i+1)%B];
		}
		vector<vi> r4 = shuffle(V);
		int A[1000], D[1000], X[1000], Y[1000];
		for (int i=0;i<B;++i){
			int c = r4[i][0];
			int d = r4[i][1];
			A[c] = d;
			A[d] = c;
			c = r2[i][0];
			d = r2[i][1];
			X[c] = d;
			X[d] = c;
			c = res[i][0];
			d = res[i][1];
			D[c] = d;
			D[d] = c;
			c = r3[i][0];
			d = r3[i][1];
			Y[c] = d;
			Y[d] = c;
		}
		out.resize(N);
		if (A[b] == X[b])swap(a,b);
		out[0] = a;
		out[1] = b;
		for (int i=3; i<=N;++i){
			int j;
			if (i%2==0)j = i-1;
			else j = i+1;
			if (j % 2 == 0){
				out[j-1] = A[out[j-4]];
			}else{
				out[j-1] = D[out[j]];
			}
		}
		
		//for (auto i : out)cout<<i<<' ';cout<<'\n';
	}
	if (ST == 5 || ST == 1){
		out.resize(N);
		int P = N;
		int p = 0;
		while(P){
			++p;
			P /=2;
		}	
		
		for (int i=0;i<N/2;++i){
			di.pb(i);
			di.pb((1<<p)-i-1);
		}
		tbl.resize(N+1);
		for (int i=0;i<=N;++i)tbl[i].resize(p);
		sort(ALL(di));
		for (int i=0;i<SZ(di);++i){
			int x = 0;
			int j = di[i];
			while(j){
				if (j%2==1)tbl[i][x] = 1;
				++x;
				j /= 2;
			}
		}
		
		vector<vi> V;
		V.resize(2);
		for (int x=0;x<SZ(di); ++x){
			if (tbl[x][0])V[0].pb(x+1);
			else V[1].pb(x+1);
		}
		vector<vi> v1 = shuffle(V);
		V[0].pop_back();
		V[1].erase(V[1].begin());
		V[0].pb(1);
		V[1].pb(N);
		vector<vi> v2 = shuffle(V);
		set<int> st;
		for (auto i : v1[0])st.insert(i);
		for (auto i : v2[0])st.erase(i);
		if (SZ(st) != 1){
			st.clear();
			swap(v2[0], v2[1]);
			for (auto i : v1[0])st.insert(i);
			for (auto i : v2[0])st.erase(i);
		}
		int a = *st.begin();
		st.clear();
		for (auto i : v2[0])st.insert(i);
		for (auto i : v1[0])st.erase(i);
		int b = *st.begin();
		
		V[1].pop_back();
		V[0].erase(V[0].begin());
		V[0].pb(N);
		V[1].pb(2);
		vector<vi> v3 = shuffle(V);
		st.clear();
		for (auto i : v1[0])st.insert(i);
		for (auto i : v3[0])st.erase(i);
		if (SZ(st) != 1){
			st.clear();
			swap(v2[0], v3[1]);
			for (auto i : v1[0])st.insert(i);
			for (auto i : v3[0])st.erase(i);
		}
		int c = *st.begin();
		st.clear();
		for (auto i : v2[0])st.insert(i);
		for (auto i : v1[0])st.erase(i);
		int d = *st.begin();
		if (b == c || b == d)b = a;
		out[N-1] = b;
		int in = 0;
		for (auto it : v1[1])if (b == it)in = 1;
		int add = 1;
		for (auto it : v1[in]){
			indexes[it] = indexes[it] + add;
		}
		
		
		//for (auto i : di)cout<<i<<' ';cout<<'\n';
		for (int i=1;i<p;++i){
			vector<vi> V;
			V.resize(2);
			for (int x=0;x<SZ(di); ++x){
				if (tbl[x][i])V[0].pb(x+1);
				else V[1].pb(x+1);
			}

			vector<vi> res = shuffle(V);
			int in = 0;
			for (auto it : res[1])if (b == it)in = 1;
			int add = (1<<i);
			for (auto it : res[in]){
				indexes[it] = indexes[it] + add;
			}
		}
		for (int i =0;i<SZ(di);++i){
			for (int it = 1;it<=N;++it){
				if (indexes[it] == di[i]){
					out[i] = it;
				}
			}
		}
	}
	return out;
}
