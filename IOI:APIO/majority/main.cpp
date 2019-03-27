#include <cstdio>
#include "majority.h"
using namespace std;

int main () {
	freopen("majority-sample.in","r",stdin);
	int N;
	int * A;
	scanf("%d", &N);
	A = new int[N];
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);
	printf("%d\n", majority(N,A));
	return 0;
}
