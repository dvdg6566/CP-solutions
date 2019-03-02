#include <bits/stdc++.h>
using namespace std;
#include "rarwall.h"
static inline int _readInt() {
    int c, x, s;
    c = getchar();
    while (c <= 32) c = getchar();
    x = 0;
    s = 1;
    if (c == '-') {
        s = -1;
        c = getchar();
    }
    while (c > 32) {
        x *= 10;
        x += c - '0';
        c = getchar();
    }
    if (s < 0) x = -x;
    return x;
}

int main () {
    freopen("rarwall.2.4.in","r",stdin);
    int L, M, Q;
    L = _readInt();
    M = _readInt();
    Q = _readInt();
    init(L, M, Q);
    for (int N = 1, K, A, B, C; N <= M; ++N) {
        K = _readInt();
        A = _readInt();
        B = _readInt();
        C = _readInt();
        proposal(N, K, A, B, C);
    }
    for (int i = 0, P, X, Y; i < Q; ++i) {
        P = _readInt();
        X = _readInt();
        Y = _readInt();
        printf("%lld\n", (long long) max_height(P, X, Y));
    }
}
