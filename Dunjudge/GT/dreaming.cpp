#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef double dl;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MOD 1e9+7
#define lb lower_bound
#define ub upper_bound
#define INF 1000000000

/*
	For each tree disconnected sub-graph, find the centroid.
	Centroid found by dfs to furthest node and find diametre. Then use the 2 furthest apart nodes to calculate. 
	Use L + the sum of radii of 2 largest trees.
	If L is large, the sum of 2L and the 2nd and 3rd largest trees may be worse 
	Edgecase: Within a tree is the longest path
*/

int dst[100100],dst2[100100],dst3[100100],SCC[100100];
vpi adjList[100100];
vpi str,str2;
vi str3;
int cur = -1;

void dfs(int x){
	for (auto i : adjList[x]){
		if (dst[i.f]!=-1)continue;
		dst[i.f] = dst[x] + i.s;
		if (str[cur].s <= dst[i.f]){
			str[cur] = mp(i.f,dst[i.f]);
		}
		dfs(i.f);
	}
}

void dfs2(int x){
	for (auto i : adjList[x]){
		if (dst2[i.f]!=-1)continue;
		dst2[i.f] = dst2[x] + i.s;
		if (str2[cur].s <= dst2[i.f]){
			str2[cur] = mp(i.f,dst2[i.f]);
		}
		dfs2(i.f);
	}
}

void dfs3(int x){
	for (auto i : adjList[x]){
		if (dst3[i.f]!=-1)continue;
		dst3[i.f] = dst3[x] + i.s;
		str3[cur] = min(str3[cur],max(dst2[i.f],dst3[i.f]));
		dfs3(i.f);
	}
}

int travelTime(int N, int M, int L, int A[], int B[], int T[]) {
	for (int i = 0; i < M; ++i){
		adjList[A[i]].pb(mp(B[i],T[i]));
		adjList[B[i]].pb(mp(A[i],T[i]));
	}
    memset(dst,-1,sizeof(dst));
    memset(dst2,-1,sizeof(dst2));
    memset(SCC,-1,sizeof(SCC));
    memset(dst3,-1,sizeof(dst3));
    for (int i = 0; i < N; ++i){
		if (dst[i]<0){
			dst[i] = 0;
			cur++;
			SCC[i] = i;
			str.pb(mp(i,0));
			dfs(i);
		}
	}
	cur=-1;
	for (auto i : str){
	    cur++;
		dst2[i.f] = 0;
		str2.pb(mp(i.f,0));
		dfs2(i.f);
	}
	cur=-1;
	for (auto i : str2){
	    cur++;
		dst3[i.f] = 0;
		str3.pb(i.s);
		dfs3(i.f);		
	}
	int ans = 0;
	sort(str3.begin(),str3.end());
	reverse(str3.begin(),str3.end());
	ans = max(ans,*max_element(dst2,dst2+N));
	if(str3.size() >= 2){
		ans = max(ans,str3[0]+str3[1]+L);
	}
	if (str3.size() > 2){
		ans = max(ans,str3[1] + str3[2] + 2*L);
	}
	return ans;
}

#define MAX_N 100000

static int A[MAX_N];
static int B[MAX_N];
static int T[MAX_N];

int main() {
	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N, M, L, i;
	int res;

	res = scanf( "%d%d%d", &N, &M, &L);
	for (i = 0; i < M; i++)
		res = scanf( "%d%d%d", &A[i], &B[i], &T[i]);

	int answer = travelTime(N, M, L, A, B, T);
	printf("%d\n", answer);

	return 0;
}
