#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define OVER 500000001LL
#define s second
#define f first
typedef long long ll;
typedef pair<int,int>pi;
vector<pi> adjList[20010];
ll fw[20010][600];
ll N,M,H,A,B,W;



int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input1.txt","r",stdin);
	cin >> N >> M >> H;
	for (int i = 0; i < N-1; ++i){
		for (int j = 0; j < H; ++j){
			cin >> B >> W;
			//cout << i << ' ' << B << ' ' << W << '\n';
			if (i >= B)continue;
			adjList[i].pb(mp(B,W));
		}
	}
	fw[0][1] = 1;
	for (int i = 0; i < N-1; ++i){
		for (int j = 1; j <= M; ++j){
			fw[i][j] = min(OVER,fw[i][j]+fw[i][j-1]);
		}
		for (int j = 1; j <= M; ++j){
			ll w = min(OVER,fw[i][j]);
			if(!w)continue;
			for (auto it : adjList[i]){
				fw[it.f][it.s+j] = min(OVER,w+fw[it.f][it.s+j]);
			}
		}
	}
	for (int k = 1; k <= M; ++k){
		ll c = fw[N-1][k];
		cout << min(OVER,c) << ' ';
	}
}