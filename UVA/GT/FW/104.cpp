#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef double dl;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MOD 1e9+7
#define lb lower_bound
#define ub upper_bound
#define dst distance
#define INF 1000000000

double adjMat[22][22][22];
int N;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("input.txt","r",stdin);
	while(1){
		cin >> N;
		if(cin.eof())return 0;
		for (int i = 1; i <= N; ++i){
			for(int j = 1; j <= N; ++j){
				for(int k = 1; k <= N; ++k){
					adjMat[i][j][k] = INF;
					if(i==j)adjMat[i][j][k] =1;
				}
				if(i!=j) cin >> adjMat[i][j][0];
			}
		}
		for (int i = 1; i <= N; ++i){
			for(int j = 1; j <= N; ++j){
				cout << adjMat[i][j][0] << ' ';
			}
			cout << '\n';
		}
	}
}
