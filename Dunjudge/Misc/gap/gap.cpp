#include "gap.h"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
#define pb push_back

vi l,r;
ll a,b,c,d;

long long findGap(int T, int N)
{
	if (T == 1){
		ll lower = 0;
		ll upper = 1e18+1;
		for (int i=0;i<(N+1)/2;++i){
			MinMax(lower,upper,&a,&b);
			if (a == b){
				l.pb(a);
				break;
			}
			l.pb(a);
			r.pb(b);
			lower = a+1;
			upper = b-1;
		}
		reverse(r.begin(),r.end());
		for (auto i : r)l.pb(i);
		// for (auto i : l)cout<<i<<'\n';
		for (int i=0;i<N-1;++i){
			c = max(c, l[i+1] - l[i]);
		}
		return c;
	}
	ll lower = 0;
	ll upper = 1e18+1;
	MinMax(lower,upper,&a,&b);
	lower = a+1;
	upper = b-1;
	ll len = (upper - lower+1);
	ll K = N-1;
	ll window_size = len/K;
	// cout<<lower<<' '<<upper<<'\n';
	// cout<<len<<'\n';
	ll num_adds = len%K;
	if (num_adds == 0)num_adds = K;
	++num_adds;
	// ++K;
	// cout<<K<<' '<<window_size<<' '<<num_adds<<'\n';
	// --num_adds;
	l.pb(a);
	ll low = lower-window_size;

	for (int i=0;i<K;++i){
		low += window_size + (i>num_adds);
		ll upp = low + (i>=num_adds) + window_size - 1;
		// cout<<low<<' '<<upp<<'\n';
		MinMax(low,upp,&c,&d);
		if(c!=-1)l.pb(c);
		if(d!=-1 && c!=d)l.pb(d);
	}
	l.pb(b);
	c = 0;
	// for (auto i : l)cout<<i<<' ';cout<<'\n';
	for (int i=0;i<l.size()-1;++i){
		c = max(c, l[i+1] - l[i]);
	}
	assert(c>=window_size);
	return c;
}
