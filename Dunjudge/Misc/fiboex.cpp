#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int num, tc;
ll MOD = 1e9+7;

struct matrix {
    ll m[2][2];
    matrix (ll a=1, ll b=1, ll c=1, ll d=0) {
        m[0][0]=a;
        m[0][1]=b;
        m[1][0]=c;
        m[1][1]=d;
    }
    matrix clone() { return matrix(m[0][0], m[0][1], m[1][0], m[1][1]); }
    matrix operator* (matrix b) {
        matrix a = (*this).clone(), o;
        o.m[0][0] = (a.m[0][0]*b.m[0][0] + a.m[0][1]*b.m[1][0]) % MOD;
        o.m[1][0] = (a.m[0][1]*b.m[0][0] + a.m[1][1]*b.m[1][0]) % MOD;
        o.m[0][1] = (a.m[0][0]*b.m[0][1] + a.m[0][1]*b.m[1][1]) % MOD;
        o.m[1][1] = (a.m[1][0]*b.m[0][1] + a.m[1][1]*b.m[1][1]) % MOD;
        return o;
    }
};

matrix qfib(int n) {
    if (n == 1) return matrix(1, 1, 1, 0);
    matrix half = qfib(n/2);
    half = half * half;
    if (n%2==1) half = half* matrix(1, 1, 1, 0);
    return half;
}
int T,N;

int main(){
  cin>>T;
  for (int i=0; i < T;++i){
    cin>>N>>MOD;
    --N;
    cout<<qfib(N).m[0][0]<<'\n';
  }
}