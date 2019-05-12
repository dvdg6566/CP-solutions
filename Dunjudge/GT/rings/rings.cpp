#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define MAXN 1000100
int A[MAXN], B[MAXN], C[MAXN], p[MAXN], deg[MAXN];

int par(int x){return (p[x] == x) ? x : p[x] = par(p[x]);}
int cy[MAXN];

int N,T,cycle,fill;
vi opt,tmp;

void Init(int N_) {
	N = N_;
	for (int i=0;i<N;++i){
		A[i] = B[i] = C[i] = -1;
		deg[i] = 0;
	}
	for (int i=0;i<N;++i)opt.pb(i);
	T = N;
	for (int i=0;i<N;++i)p[i] = i;
}

void mergeInto(int x,int bo){
	// cout<<"Mi " << x << ' '<< deg[x] << '\n';
	int a=x,b=A[x],c=B[x],d=C[x];
	if (!bo)b=c=d=-1;
	// cout<<"Merging Into " <<' '<<a<<' '<<b<<' '<<c<<' '<<d<<'\n';
	tmp.clear();
	swap(opt,tmp);
	for (auto i : tmp){
		if (i != a && i != b && i !=c && i != d )continue;
		opt.pb(i);
	}
	T = SZ(opt);
}

void merge(int a, int b){
	// cout<<"Comb "<<a<<' '<<b<<'\n';
	tmp.clear();
	swap(opt,tmp);
	for (auto i : tmp){
		if (i != a && i != b)continue;
		opt.pb(i);
	}
	T = SZ(opt);
}

vpi ord;
void rmv(int x){
	while(deg[x] < 3){
		// cout<<"Rmv " << x <<' '<<A[x]<< '\n';
		ord.pb(mp(x,0));
		cy[x] = -1;
		if (cy[A[x]] == 1) x = A[x];
		else if (B[x] != -1 && cy[B[x]] == 1)x = B[x];
		else break;
		ord.back().s = x;
	}
}

void filter(){
	tmp.clear();
	swap(opt,tmp);
	for (auto i : tmp){
		if (cy[i] != 1)continue;
		opt.pb(i);
	}
	T = SZ(opt);
}

int st;

void Link(int a, int b) {
	// cout<<"Linking "<<a<<' '<<b<<'\n';
	if (T == 0)return;
	if (A[a] == b || B[a] == b || C[a] == b)return;
	if (A[b] == a || B[b] == a || C[b] == a)return;

	if (deg[a] < deg[b])swap(a,b);
	deg[a]++;
	deg[b]++;

	if (A[a] == -1)A[a] = b;
	else if (B[a] == -1)B[a] = b;
	else C[a] = b;

	if (A[b] == -1)A[b] = a;
	else if (B[b] == -1)B[b] = a;
	else C[b] = a;

	if (deg[a] > 3){
		mergeInto(a,0);
	}
	if (deg[b] > 3){
		mergeInto(b,0);
	}
	if (deg[a] == 3){
		// cout<<"Merge "<<a<<'\n';
		mergeInto(a,1);
	}
	if (deg[b] == 3){
		// cout<<"Merge "<<b<<'\n';
		mergeInto(b,1);
	}

	if (T == 0){
		return;
	}

	if(cycle){
		// cout<<cy[a]<<' '<<cy[b]<<'\n';
		if (cy[a] == -1 && cy[b] == -1 && par(a) == par(b) && par(a) != par(opt[0])){
			
			// Disjoint cycles
			T = 0;
		}
		else if (cy[a] == cy[b] && cy[a] != -1){
			mergeInto(cy[a],0);
			T = SZ(opt);
		}
		else if (cy[a] != -1 && cy[b] != -1){
			if (a == cy[a] && b == cy[b]){
				// Direct edge
				merge(a,b);
				return;
			}
			a = cy[a];
			b = cy[b];
			if (A[a] == b || B[a] == b || C[a] == b || A[b] == a || B[b] == a || C[b] == a){
				merge(a,b);
			}else{
				T = 0;
			}
		}
		else{
			if (cy[a] == -1 && cy[b] == -1){
				p[par(b)] = par(a);
				return;
			}
			if (cy[a] == -1)swap(a,b);
			// cout<<"For nodes " << a << " and " << b << '\n';
			// cout<<"Home nodes " << cy[a] << " and " << cy[b]<< '\n';
			// cout<<"Parent nodes "<<par(a)<<" and " << par(b)<<'\n';
			cy[b] = cy[a];
			p[par(b)] = par(a);
		}
	}
	else if (par(a) == par(b)){
		// for (auto i : opt)cout<<i<<' ';cout<<'\n';
		// cout<<"Cycle found\n";
		st = par(a);
		cycle = 1;
		memset(cy, -1, sizeof(cy));
		// Cycle has been found
		int x = par(a);
		for (int i=0;i<N;++i){
			if (par(i) != x)continue;
			cy[i] = 1;
		}

		for (int i=0;i<N;++i){
			if (par(i) != x)continue;
			if (deg[i] == 1){
				rmv(i);
			}
		}
		// for (int i=0;i<N;++i)if (cy[i] == 1)cout<<i<<' ';cout<<'\n';
		filter();
		reverse(ALL(ord));
		// for (auto i : opt)cout<<i<<' ';cout<<"\n\n";

		for (int i=0;i<N;++i)if(cy[i] == 1){cy[i] = i;}

		for (auto i : ord){
			cy[i.f] = cy[i.s];
		}
		T = SZ(opt);
	}else{
		// No Cycle Yet
		p[par(b)] = par(a);
	}
}

int CountCritical() {

  return T;

}