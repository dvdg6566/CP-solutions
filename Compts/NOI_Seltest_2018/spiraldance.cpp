#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
char io;
#define mp make_pair
#define pb push_back
ll a=0,b=0,c=0,d=0,m=0,n=0,i=0,l=0,w=0,x=0,y=0,z=0,p=0,siz=0,rep=0;
vector<int>col[30];
string str;
#define f first
#define s second

pi convert(ll cur){
	ll low = floor(sqrt(cur));
	if (low%2==0)low--;
	ll btm = low*low;
	pi loc = mp(-low/2,-low/2);
	if (cur==btm)return loc;
	if (btm+low+1 >= cur){
		y = loc.f-1;
		x = loc.s+cur-btm-1;
		return mp(x,y);
	}
	if (btm+low*2+2 >= cur){
		//assert(0);
		x = loc.s+low;
		y = loc.f+cur-low-btm-2;
		return mp(x,y);
	}
	if (btm+low*3+3>=cur){
		pi opp = mp(1-loc.f,1-loc.s);
		return mp(opp.s-cur+low+low+btm+2,opp.s);
	}
	pi next = mp(loc.f-1,loc.s-1);
	return mp(next.f,next.s+(low+2)*(low+2)-cur);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.cpp","r",stdin);
	cin >> n >> str;
	for(int i = 0; i < n; ++i){
		col[str[i]-'A'].pb(i+1);
	}
	cin >> rep;
	for (ll it = 0; it < rep; ++it){
		cin >> l >> io;
		siz = col[io-'A'].size();
		l--;
		p = floor(l/siz);
		l-=p*siz;
		a = p*n + col[io-'A'][l];
		
		cin >> l >> io;
		l--;
		siz = col[io-'A'].size();
		p = floor(l/siz);
		l-=p*siz;
		b = p*n + col[io-'A'][l];
		
		pi j = convert(a);
		pi k = convert(b);
		cout << (abs(j.f-k.f) + abs(j.s-k.s)) << '\n';
	}
}
