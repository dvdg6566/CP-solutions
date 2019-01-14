#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,string> pi;

#define f first
#define s second
#define mp make_pair
#define pb push_back

int N;
string d;
string a,b;
int L,R;
queue<int>Q;
vector<pi> V;

int cnv (string X){
  int res = 0,mul= 1;
  while (X.size()){
    res += mul*(X[X.size()-1]-'0');
    mul = mul*10;
    X=X.substr(0,X.size()-1);
  }
  return res;
}

bool cmp(pi x, pi y){return x.f < y.f;}

int main(){
	//freopen("input.txt","r",stdin);
	cin >> N;	
	while(N--){
		cin.ignore();
		cin.ignore();
		V.clear();
		getline(cin,a);
		b = "";
		for (auto i : a){
			if (i==' '){
				Q.push(cnv(b));
				b = "";
			}else{
				b = b + i;
			}
		}
		Q.push(cnv(b));
		while(Q.size()){
			cin >> d;
			V.pb(mp(Q.front(),d));
			Q.pop();
		}
		sort(V.begin(),V.end(),cmp);
		for (auto i : V)cout << i.s << '\n';
		if(N!=0)cout << '\n';
	}
}
