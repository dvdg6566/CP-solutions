#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef vector<ll> vi;
typedef pair<pi,ll> pii;
typedef vector<pi> vpi;
typedef pair<ll,pi> ppi;
typedef vector<ppi> vpp;
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
ll N,K,Q,c,x,y,zero,M,ans,b,a,E;
 
vi adjList[100010];
vpp aList[100010];
ll par[100100], w[100100];
ll BF[120],visit[120];
 
ll permutate(ll num,ll den){
	if(num<den)return 0;
	if(den==1)return num;
	if(den==2)return (num-1)*(num-1);
	if(den==3)return num*(num-1)*(num-2);
}

ll ind[100010], currstack[100010], lowlink[100010], SCC[100010];
stack<ll> stk;
stack<pi> edgeList;

void SCCdfs(ll x){
	if (ind[x] != -1)return;
	ind[x] = a;
	lowlink[x] = a;
	a++;
	currstack[x] = 1;
	stk.push(x);
	for (auto it : adjList[x]){
		if (SCC[it] != -1)continue;
		if(par[x] == it)continue;
		if(par[it] == -1)par[it] = x;
		if (ind[it] == -1){
			SCCdfs(it);
			lowlink[x] = min(lowlink[x], lowlink[it]);
			continue;
		}
		else if (currstack[it]){
			lowlink[x] = min(lowlink[x], ind[it]);
		}
	}
	if (lowlink[x] == ind[x]){
		while (stk.top() != x){
			currstack[stk.top()] = 0;
			SCC[stk.top()] = b;
			stk.pop();
		}
		stk.pop();
		SCC[x] = b;
		b++;
	}
}

ll dfs3(ll x){
    BF[x]= -1;
    for (auto i : adjList[x]){
        if(visit[i])continue;
        if (BF[i] == 1){
            BF[x] = 1;
            continue;
        }
        visit[i] = 1;
        ll r = dfs3(i);
        if (r == 1)BF[x] = 1;
    }
    visit[x]=0;
    return BF[x];
}
ll brute(){
    ll ans = 0;
    for (ll i = 1; i<= N; ++i){
        for (ll j = 1; j <= N; ++j){
            memset(BF,0,sizeof(BF));
            memset(visit,0,sizeof(visit));
 
            BF[j]=1;
            BF[i] = -1;
            visit[i] = 1;
            E = j;
            dfs3(i);
            for (ll k = 1; k <= N; ++k){
                if (k==i||k==j)continue;
                if (BF[k] == 1){
                    ans++;
                }
            }
        }
    }
    return ans;
}
void dfs (ll x){
    for (auto i : aList[x]){
        if (par[i.f]!=-1){continue;}
        par[i.f] = x;
        dfs(i.f);
    }
}
pii query(ll x, ll inherit){
	map<int,int>MP;
    vector<ppi> V;
    ll one = 0, two = 0, three= 0;
    ll wgt = w[x];
    ll a = 0, b = 0;
    three += permutate(wgt,3);
    two += permutate(wgt,2);
    one += permutate(wgt,1);
    for (auto i : aList[x]){
        if (par[i.f] != x)continue; //backedge
        pii r = query(i.f,i.s.s);
        three += r.s; // ALL THREE FROM EDGE
        one += r.f.f; // 1 FROM EDGE
        two += r.f.s; // 2 FROM EDGE
        if(inherit != i.s.f) two += r.f.f*permutate(wgt,1); // 1 FROM EDGE, 1 FROM NODE
        else two += r.f.f;
        three += 2*(r.f.s)*permutate(wgt,1); // TWO FROM EDGE, 1 FROM NODE
        three += (r.f.f)*permutate(wgt,2)*2; // 1 FROM EDGE, 2 FROM NODE
        a += r.f.f;
        b += r.f.s;
        V.pb(mp(i.s.f,mp(r.f.f,r.f.s)));
        MP[i.s.f] += r.f.f;
    }
    for (auto i : V){
        three += (i.s.f*(a-i.s.f)*permutate(wgt,1)); // ONE ONE ONE
        if(wgt != 1){
			assert((MP[i.f] - i.s.f)*(i.s.f)*(permutate(wgt,1)-1)>= 0);
			three -= (MP[i.f] - i.s.f)*(i.s.f)*(permutate(wgt,1)-1);
		}
        three += (i.s.f*(b-i.s.s)); // ONE TWO
        three += (i.s.s*(a-i.s.f)); // TWO ONE
    }
    return mp(mp(one,two),three);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    cin >> N >> M;
    for (ll i = 0; i < M; ++i){
        cin >> x >> y;
        adjList[x].pb(y);
        adjList[y].pb(x);
        edgeList.push(mp(x,y));
    }
    if (N<=50){
        cout << brute();
        return 0;
    }
    memset(par,-1,sizeof(par));
    memset(ind,-1,sizeof(ind));
	memset(SCC, -1, sizeof(SCC));
	b = 1;
	for (ll i = 1; i <= N; ++i){
		if(ind[i]!=-1)continue;
		SCCdfs(i);
	}
	for (ll i = 1; i <= N; ++i){
		w[SCC[i]]++;
	}
    while (!edgeList.empty()){
		pi T = edgeList.top();
		ll tmpx = SCC[T.f];
		ll tmpy = SCC[T.s];
		edgeList.pop();
		if (tmpx == tmpy)continue;
		aList[tmpx].pb(mp(tmpy,mp(T.f,T.s)));
		aList[tmpy].pb(mp(tmpx,mp(T.s,T.f)));
	}
    memset(par,-1,sizeof(par));
    for (ll i = 1; i <= b-1; ++i){
        if (par[i] != -1)continue;
        par[i] = 0;
        dfs(i);
    }
    
    for (ll i = 1; i <= b-1; ++i){
        if (par[i] != 0) continue;
        ans += query(i,-1).s;
    }
    
    cout << ans << '\n';
}
