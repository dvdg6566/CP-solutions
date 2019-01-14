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
#define INF 10000
ll V[] = {0,1,5,10,25,50};
ll X,way[6][30100];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	for (int i = 1; i <= 5; i++)way[i][0] = 1LL;
	for (int j = 1; j <= 30100; j++){
		for (int i = 1; i <= 5; i++){
			int val = V[i];
			way[i][j]=way[i-1][j];
			if(j>=val)way[i][j]+=way[i][j-val];
		}
	}
	while(cin>>X){
		if(cin.eof())return 0;
		if(way[5][X] > 1 && X!=0)cout << "There are " << way[5][X] << " ways to produce " << X << " cents change.\n";
		else cout << "There is only 1 way to produce " << X << " cents change.\n";
	}
}
