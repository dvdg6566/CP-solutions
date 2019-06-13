#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef pair<ll,pi> pii;
typedef vector<pi> vpi;
typedef set<ll> si;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define f first
#define s second
ll INF = 1e18;
ll MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (ll)x.size()
#define ALL(x) x.begin(),x.end()
#define MAXN 110

ll optswap[MAXN][MAXN];
ll A[MAXN][MAXN];
ll H,W,a,b,K;

ll dx[] = {0,0,1,-1};
ll dy[] = {1,-1,0,0};
ll dst[MAXN][MAXN];
ll d2[MAXN][MAXN];
queue<pi>q;

void bfs(ll a,ll b){
    q.push(mp(a,b));
    dst[a][b]=A[a][b];
    while(SZ(q)){
        ll x=q.front().f; ll y=q.front().s;
        q.pop();
        ll w = dst[x][y];
        ll l=abs(x-a)+abs(y-b);
        for (ll k=0;k<4;++k){
            ll tx = x+dx[k];
            ll ty=y+dy[k];
            ll tl=abs(tx-a)+abs(ty-b);
            if (tl != l+1)continue;
            if (tx==0||ty==0||tx>H||ty>W)continue;
            if (dst[tx][ty] == -1)q.push(mp(tx,ty));
            dst[tx][ty] = max(dst[tx][ty], w+A[tx][ty]);
        }
    }
}

ll mem[MAXN][MAXN];
priority_queue<pii, vector<pii>, greater<pii>> pq;

void dijkstra(int a, int b){
    pq.push(mp(0, mp(a,b)));
    for (ll i=1;i<=H;++i)for (ll j=1;j<=W;++j)mem[i][j]=INF;
    mem[a][b] = 0;
    while (SZ(pq)){
        int x = pq.top().s.f;
        int y = pq.top().s.s;
        // cout<<x<<' '<<y<<'\n';
        ll d = pq.top().f;
        pq.pop();
        if (mem[x][y] < d)continue;
        for (ll k=0;k<4;++k){
            ll tx = x+dx[k];
            ll ty=y+dy[k];
            if (tx==0||ty==0||tx>H||ty>W)continue;
            ll w=d2[tx][ty]+d;
            // cout<<"Visit? "<<tx<<' '<<ty<<' '<<w<<'\n';
            if (mem[tx][ty]<=w)continue;
            mem[tx][ty] = w;
            pq.push(mp(w, mp(tx,ty)));
        }
    }
}

int main(){
    // assert(H==W);
    // freopen("in.txt","r",stdin);
    cin>>H>>W>>a>>b>>K;
    for (ll i=1;i<=H;++i){
        for (ll j=1;j<=W;++j){
            cin >> A[i][j];
        }
    }
    for (ll i=1;i<=H;++i){
        for (ll j=1;j<=W;++j){
            for (ll k=0;k<4;++k){
                optswap[i][j] = max(optswap[i][j], A[i+dx[k]][j+dy[k]]);
            }
            optswap[i][j] += A[i][j];
        }
    }
    K /= 2;
    memset(dst,-1,sizeof(dst));
    bfs(a,b);
    ll ans=0;
    for (ll i=1;i<=H;++i){
        for (ll j=1;j<=W;++j){
            ll l=abs(i-a)+abs(j-b);
            ll p=K-l;
            if (p<0)continue;
            ans=max(optswap[i][j]*p+dst[i][j]*2-A[i][j],ans);
        }
    }
    set<ll>S;
    ll T = 0;
    for (ll i=1;i<=H;++i){
        for (ll j=1;j<=W;++j){
            T=max(T,optswap[i][j]);
        }
    }
    // cout<<"Dijkstra "<<T<<'\n';

    for (ll i=1;i<=H;++i){
        for (ll j=1;j<=W;++j){
            d2[i][j] = T-A[i][j]*2;
            // cout<<d2[i][j]<<' ';
        }
        // cout<<'\n';
    }
    dijkstra(a,b);
    // for (ll i=1;i<=H;++i){
    //     for (ll j=1;j<=W;++j){
    //         cout<<mem[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    for (ll i=1;i<=H;++i){
        for (ll j=1;j<=W;++j){
            if (optswap[i][j] != T)continue;
            ll P = optswap[i][j]*K;
            P -= (mem[i][j] + A[i][j]);
            ans=max(ans,P);
            // cout<<i<<' '<<j<<' '<<optswap[i][j]*K<<' '<<P<<'\n';
        }
    }
    cout<<ans;
}