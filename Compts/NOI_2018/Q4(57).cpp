#include<bits/stdc++.h>
using namespace std;

#include "citymapping.h"
#define mp make_pair
#define f first
#define pb push_back
#define s second
typedef long long ll;
typedef pair<ll,ll> pi;
vector<pi> connect;
bool cmp(pi a, pi b){
	return a.s<b.s;
}
void find_roads(int N, int Q, int A[], int B[], int W[]) {
	for (int i = 0; i < N - 1; i++) {
		A[i] = 1;
		B[i] = 2;
		W[i] = 1;
	}
	
	if (Q == 500000){
		ll M[1001][1001];
		for (int i = 1; i <= N; ++i){
			for (int j = i+1; j<= N; ++j){
				M[i][j] = M[j][i] = get_distance(i,j);
			} 
		}
		ll l=0,node;
		for (int i = 2; i <= N; ++i){
			ll d = M[1][i];
			if (d > l){
				l = d;
				node = i;
			}
		}
		vector<pi> V;
		for (int i = 1; i <= N; ++i){
			if (i == node)continue;
			V.pb(mp(i,M[i][node]));
		}
		sort(V.begin(),V.end(),cmp);
		int e = 0;
		for (auto i : V){
			if (connect.size() == 0){
				connect.pb(mp(i.f,i.s));
				A[e] = node;
				B[e] = i.f;
				W[e] = i.s;
				e++; 
				continue;
			}
			ll low = 1234567890;
			ll neigh;
			for (auto x : connect){
				if (x.s + M[x.f][i.f] == i.s){
					if (M[x.f][i.f] < low){
						neigh = x.f;
						low = M[x.f][i.f];
					}
				}
			}
			if (low == 1234567890){
				A[e] = node;
				B[e] = i.f;
				W[e] = i.s;
				e++;
				continue;
			}
			A[e] = neigh;
			B[e] = i.f;
			W[e] = low;
			connect.pb(mp(i.f,i.s));
			e++;
		}
		return;
	}else{
		ll l=0,node;
		for (int i = 2; i <= N; ++i){
			ll d = get_distance(1,i);
			if (d > l){
				l = d;
				node = i;
			}
		}
		vector<pi> V;
		for (int i = 1; i <= N; ++i){
			if (i == node)continue;
			V.pb(mp(i,get_distance(i,node)));
		}
		sort(V.begin(),V.end(),cmp);
		ll prev = node;
		ll pw = 0;
		ll e = 0;
		for (auto i : V){
			ll wt = i.s;
			ll nd = i.f;
			A[e] = prev;
			B[e] = nd;
			prev = nd;
			W[e] = wt - pw;
			pw = wt;
			e++;
		}
		return;
	}
	
}
