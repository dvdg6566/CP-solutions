#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;

#define f first
#define s secon
#define mp make_pair
#define pb push_back

int a,b,c,d,n,q;
vector<int> V;

int main(){
	//freopen("input.txt","r",stdin);
	while(1){
		cin >> n >> q;
		if (n == 0)return 0;
		c++;
		V.clear();
		cout << "CASE# " << c  <<  ':' << '\n';
		for (int i = 0; i < n; ++i){
			cin >> a;
			V.pb(a);
		}
		sort(V.begin(),V.end());
		for (int i = 0; i < q; ++i){
			cin >> a;
			if (lower_bound(V.begin(),V.end(),a) == upper_bound(V.begin(),V.end(),a)){
				cout << a << " not found\n";
			}else{
				cout << a << " found at ";
				cout << lower_bound(V.begin(),V.end(),a)-V.begin()+1 << '\n';
			}
		}
	}
}
