#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef pair<ll,pi> ppi;
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

#define MAX_N 5000
#define MAX_CALLS 70000

#define fail(s, x...) do { \
		fprintf(stderr, s "\n", ## x); \
		exit(1); \
	} while(0)

/* Symbol obfuscation */
#define N koala
#define realS kangaroo
#define realD possum
#define inv platypus
#define num_calls echidna

static int N;
static int realS[MAX_N];
static int realD[MAX_N];
static int inv[MAX_N];
static int num_calls;

void answer(int S[], int D[]) {
    int i;
    int correct = 1;
    for (i = 0; i < N; ++i)
        if (S[i] != realS[i] || D[i] != realD[i]) {
            correct = 0;
            break;
        }

    for (i = 0; i < N; ++i) {
        if (i > 0)
            printf(" ");
        printf("%d", S[i]);
    }
    printf("\n");

    for (i = 0; i < N; ++i) {
        if (i > 0)
            printf(" ");
        printf("%d", D[i]);
    }
    printf("\n");

    exit(0);
}

int tryCombination(int S[]) {
    int i;

    if (num_calls >= MAX_CALLS) {
		fprintf(stderr, "INCORRECT\nToo many calls to tryCombination().\n");
        exit(0);
    }
    ++num_calls;

    for (i = 0; i < N; ++i)
        if (S[inv[i]] != realS[inv[i]])
            return i;
    return -1;
}

int init() {
    int i, res;

	res = scanf("%d", &N);

    for (i = 0; i < N; ++i) {
        res = scanf("%d", &realS[i]);
    }
    for (i = 0; i < N; ++i) {
        res = scanf("%d", &realD[i]);
        inv[realD[i]] = i;
    }

    num_calls = 0;
    return N;
}


void exploreCave(int _N) {
    for (int i = 0; i < N; ++i){
		int A[N];
		memset(A,0,sizeof(A));
		bool x = (tryCombination != i)); // Means looking for something off
		int lb = 0;
		int ub = N-1;
		
	}/* ... */
}

int main() {
	freopen("input.txt","r",stdin);
    int N;
	N = init();
	exploreCave(N);
    fprintf(stderr, "INCORRECT\nYour solution did not call answer().\n");
	return 0;
}

