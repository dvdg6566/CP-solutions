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
#define MOD (ll)1000000007
#define lb lower_bound
#define ub upper_bound
#define dst distance
#define INF 1000000000

int H,W,M,num_grp,ans;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int p[1000100];
int par(int x) { return (x==p[x])?x:p[x]=par(p[x]);}

void merge(int a, int b) { // Merging with UFDS
	if (par(a) == par(b))return; // Already connected
	p[par(a)] = par(b);
	//cout << "MERGING " << a << ' ' << b << '\n';
	--num_grp;
}
vector<pair<int,pi>> V;
set<int,greater<int>> S;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin >> H >> W;
	for (int i = 0; i <= H*W; ++i)p[i] = i;
	int A[H][W];
	memset(A,-1,sizeof(A));
	for (int i = 0; i < H; ++i){
		for (int j = 0; j < W; ++j){
			cin >> A[i][j];
			V.pb(mp(A[i][j],mp(i,j)));
			S.insert(A[i][j]);
		}
	}
	sort(V.begin(),V.end());
	reverse(V.begin(),V.end());
	int index = 0;
	for (auto j : S){
		while (V[index].f == j){
			pi i = V[index].s;
			++num_grp;
			int cur = i.f*W+i.s;
			//cout << "Visiting: " << cur << '\n';
			for (int k = 0; k < 4; ++k){
				int cx = i.f+dx[k];
				int cy = i.s+dy[k];
				if (cx < 0 || cx >= H || cy < 0 || cy >= W)continue;
				if (A[cx][cy] < j)continue; // Neighbour is underwater
				merge(cur,cx*W + cy);
			}
			if(index == V.size())break;
			++index;
		}
		ans = max(ans,num_grp);
	}
	cout << ans;
}
