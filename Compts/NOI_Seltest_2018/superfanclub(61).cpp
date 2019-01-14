#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll G[200000];
ll n;

void init(int N, int S[]) {
	n = 1<<N;
	for (int i = 1; i < n; ++i)G[i] = S[i];
}

int level (int x){
	if(x==1)return 0;
	return log2(x);
}

ll query(int a,int b){
	ll ans = 0;
	if(a>b)swap(a,b);
	while(level(b) > level(a)){
		ans += G[b];
		b /= 2;
	}
	while (a != b){
		ans += (G[a]+G[b]);
		a/=2;b/=2;
	}
	return ans;
}

int find_closest(int F, long long D) {
	ll m = LONG_LONG_MAX;
	ll ans = 0;
	for (int i = 1; i < n; ++i){
		ll x = query(i,F);
		ll q = abs(D-x);
		//cout << i << ' ' << x << '\n';
		if (m > q){
			m = q;
			ans = i;
		}
	}
	//cout << '\n';
	return ans;
}

using namespace std;
int main(int argc, char* argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("input.txt","r",stdin);
    int N,Q;
    cin>>N>>Q;
    int* S = new int[1<<N];
    S[0]=S[1]=-1;
    for(int i=2;i<(1<<N);++i){
        cin>>S[i];
    }
    init(N,S);
    for(int i=0;i<Q;++i){
        int F;
        long long D;
        cin>>F>>D;
        if(i!=0)cout<<' ';
        cout<<find_closest(F, D);
    }
    cout<<endl;
    exit(0);
}

