#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef vector<ll> vi;
typedef pair<pi,pi> pii;
typedef pair<int,pi> ii;
#define f first
#define s second
#define pb push_back
#define mp make_pair
ll N,K,Q,c,x,y,zero,M,ans;
ll out[100000];
 
bool cmp(pii a, pii b){
    if (a.f.f == b.f.f)return a.f.s > b.f.s;
    return a.f.f < b.f.f;
}
 
vector<pii> pq;
ii data[100000];
 
int main(){
    freopen("input.txt","r",stdin);
    cin >> N;
    for (int i = 0; i < N; ++i){
        cin >> x >> y >> c;
        pq.pb(mp(mp(c,i+1),mp(x,y)));
        data[i+1]=mp(c,mp(x,y));
    }
    sort(pq.begin(),pq.end(),cmp);
    while (pq.size()){
        pii a = pq[pq.size()-1];
        pq.pop_back();
        if(out[a.f.s])continue;
        out[a.f.s] = a.f.s;
        for (int i = 1; i <= N; ++i){
            if(out[i])continue;
            ll xc = (a.s.f-data[i].s.f)*(a.s.f-data[i].s.f);
            ll xy = (a.s.s-data[i].s.s)*(a.s.s-data[i].s.s);
            if (data[i].f + a.f.f >= sqrt((double)xc+(double)xy))
            {
                out[i] = a.f.s;
            }
        }
    }
    for (int i = 1; i <= N; ++i){
        cout << out[i] << ' ';
    }
}
