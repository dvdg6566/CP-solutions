#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;

#define f first
#define s secon
#define mp make_pair
#define pb push_back

ll a,b,c,d,e,f,g;

stack<int>S;

int main(){
	freopen("input.txt","r",stdin);
	while(1){
		cin >> g;
		if (g == 0)return 0;
		a=a+1;
		c = 0;
		for(int i=0;i<g;++i){
			cin >> b;
			S.push(b);
			c+=b;
		}
		c=c/g;
		//cout << c<< '\n';
		b = 0;
		while(S.size()){
			if(S.top()>=c)b+=(S.top()-c);
			S.pop();
		}
		cout << "Set #" << a << '\n';
		cout << "The minimum number of moves is " << b << '.' << '\n' << '\n';
	}
}
