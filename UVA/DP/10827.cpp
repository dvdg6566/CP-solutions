#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MOD 1e9+7
#define lb lower_bound
#define ub upper_bound
#define dst distance
#define INF 100000000

int single[100],p[100];
int torus[100][100];
int N,T;

int maxsumTorus(){
	// Array "p" contains the data
	// If does not cross: normal maxsum
	int ans = 0, curr=0;
	int res = 0, ttl = 0;
	for (int i = 0; i < N; ++i){
		res+=p[i];
		res=max(res,0);
		ans=max(ans,res);
	}
	res = 0;
	// If array crosses: take entire array minus the minsum. Can be seen as taking the maxsum of negative values/ 
	for (int i = 0; i < N; ++i){
		ttl += p[i];
		res+=(-p[i]);
		res=max(res,0);
		curr=max(curr,res);
	}
	ans = max(ans,ttl+curr);
	if(ans<=0)return *max_element(p,p+N);
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> T;
	while(T--){
		cin >> N;
		if(cin.eof())return 0;
		for (int i = 0; i < N; ++i){
			for (int j = 0; j < N; ++j){
				cin>>torus[i][j];
			}
		}
		int out = -INF;
		for (int i = 0; i < N; i++){
			memset(p,0,sizeof(p));
			for (int j = i; j < i+N; j++){
				for (int k = 0; k < N; k++){
					p[k] += torus[j%N][k];
				}
				out = max(out,maxsumTorus());
			}
		}
		cout << out << '\n';
	}
}
