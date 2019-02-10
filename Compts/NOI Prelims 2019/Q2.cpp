#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans[100100];
ll N,Q,a,b,w;

int main() {
    cin>>N>>Q;
    memset(ans, -1, sizeof(ans));
    for (int i=0;i<Q;++i){
        cin>>a>>b>>w;
        ans[a] = max(ans[a], w);
        ans[b] = max(ans[b], w);
    }
    for (int i=1;i<=N;++i){
        if (ans[i] == -1)cout<<(ll)1e9<<' ';
        else cout<<ans[i]<<' ';
    }
}