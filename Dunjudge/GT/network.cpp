#include<bits/stdc++.h>
using namespace std;

#include <cstdio>
#include <cstdlib>

static const int MAX_N = 1010;

static int N, a, b, M,
           pingCount,
           routeLength, current;
static int D[MAX_N][MAX_N];

static void raiseError (const char* message)
{
    printf ("ERROR\n%s\n", message);
    exit (0);
}

int ping (int i, int j)
{
    if (i < 1 || j < 1 || i > N || j > N || i == j)
        raiseError ("ping called with invalid arguments");

    ++pingCount;
    if (pingCount > M)
        raiseError ("Too many calls to ping");

    return D[i-1][j-1];
}

void travelTo (int k)
{
    if (k < 1 || k > N)
        raiseError ("travelTo called with invalid argument");

    if (k == current || D[current-1][k-1] > 0)
        raiseError ("Travelling to nonadjacent computer");

    ++routeLength;
    if (routeLength > D[a-1][b-1] + 1)
        raiseError ("Route is too long");

    current = k;
}

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
vpi V;

bool cmp(pi a, pi b){
	return a.s > b.s;
}

void findRoute (int N, int a, int b)
{
    int d = ping(a,b)+1;
    for (int i = 1; i <= N; ++i){
		if (i == a || i == b)continue;
		int e = ping(i,b);
		V.pb(mp(i,e+1));
	}
    sort(V.begin(),V.end(),cmp);
    V.pb(mp(b,0));
	int curr = a, dst = 0;
	for (auto i : V){
		int x = ping(curr,i.f) + 1;
		if (x != 1)continue;
		if (d != dst + i.s + x)continue;
		dst++;
		curr = i.f;
		travelTo(i.f);
	}
}


int main()
{
	freopen("network.in","r",stdin);
    scanf ("%d%d%d%d", &N, &a, &b, &M);
    for (int u = 0; u < N; ++u)
        for (int v = 0; v < N; ++v)
            scanf("%d", &D[u][v]);

    pingCount = 0;
    routeLength = 0;
    current = a;

    findRoute (N, a, b);

    if (current != b)
        raiseError ("Message has not reached its target");

    if (routeLength < D[a-1][b-1] + 1)
        raiseError ("Unexpected: route is too short");

    printf ("OK\n");

    return 0;
}
