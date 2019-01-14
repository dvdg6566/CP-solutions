#include<bits/stdc++.h>
using namespace std;
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
#define INF 1234567890987654321

ll G[300000];
ll n;
vpi children[300000];

bool cmp(pi a, pi b){
	if (a.f != b.f)return a.f < b.f;
	return a.s < b.s;
}

void init(int N, int S[]) {
	n = 1<<N;
	for (int i = 2; i < n; ++i)G[i] = S[i];
	for (int i = n-1; i >=1; --i){
		if(2*i < n){
			children[i].pb(mp(0,i));
			for (auto it : children[2*i+1]){
				children[i].pb(mp(it.f+G[2*i+1],it.s));
			}
			for (auto it : children[2*i]){
				children[i].pb(mp(it.f+G[2*i],it.s));
			}
			sort(children[i].begin(),children[i].end(),cmp);
		}else children[i].pb(mp(0,i));
	}
}

int findFirst(int index, ll val){
	int low = 0, up = children[index].size() - 1;
	while (up > low+1){
		int mid = (low + up)/2;
		if (children[index][mid].f < val)low = mid;
		else up = mid;
	}
	if (val == children[index][low].f)return children[index][low].s;
	return children[index][up].s;
}

pi closest(int index, ll val){
	ll B = max(children[index][0].f,min(val,children[index].back().f));
	int low = 0, up = children[index].size() - 1;
	while (up > low+1){
		int mid = (low + up)/2;
		if (children[index][mid].f < B)low = mid;
		else up = mid;
	}
	ll a = abs(children[index][low].f - val);
	ll b = abs(children[index][up].f - val);
	if(a == b){
		if(children[index][low].s < children[index][up].s)return mp(a,findFirst(index,children[index][low].f));
		return mp(b,findFirst(index,children[index][up].f));
	}
	if (a > b)return mp(b,findFirst(index,children[index][up].f));
	return mp(a,findFirst(index,children[index][low].f));
}

int find_closest(int F, long long D) {
	pi x = closest(F,D);
	ll res = x.f, ans = x.s, curstack = 0; // res is the closest distance (to D), ans is the node that has that distance
	while(F > 1){
		curstack += G[F];
		int  ind = 4 * (F/2) + 1 - F; // Index of sibling
		ll d = curstack + G[ind];
		pi x = closest(ind,D-d);
		if(x.f < res || (x.f == res && x.s<ans)){
			res = x.f;
			ans = x.s;
		}
		if (abs(D-curstack) <= res){
			res = abs(D-curstack);
			ans = F/2;
		}
		F /= 2;
	}
	return ans;
}

using namespace std;
int main(int argc, char* argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("input.txt","r",stdin);
    int N,Q;
    cin>>N>>Q;
    int* S = new int[1<<N];
    S[0]=S[1]=-1;
    for(int i=2;i<(1<<N);++i){
        cin>>S[i];
    }
    init(N,S);
    for(int i=0;i<Q;++i){
        int F;
        long long D;
        cin>>F>>D;
        if(i!=0)cout<<' ';
        cout<<find_closest(F, D);
    }
    cout<<endl;
    exit(0);
}
