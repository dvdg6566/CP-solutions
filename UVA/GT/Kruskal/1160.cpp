#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef vector<int> vi;

#define f first
#define s second
#define mp make_pair
#define pb push_back
 
int p[110000];
int par(int x) { return (x==p[x])?x:p[x]=par(p[x]);}
int a,b,c;
int main(){
	//freopen("input.txt","r",stdin);
	for (int i = 0; i < 110000; ++i)p[i] = i;
	while(1){
		cin >> a;
		if(cin.eof())return 0;
		if (a == -1){
			cout << c << '\n';
			c = 0;
			for (int i = 0; i < 110000; ++i)p[i] = i;
			continue;
		}
		cin >> b;
		if(par(a) == par(b)){c++;continue;}
		p[par(a)] = par(b);
	}
}
