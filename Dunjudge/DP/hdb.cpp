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
#define INF 1000000000

ll N,L,a,b;
ll speed[100100];
vi stairs[100100];
vpi cur;
map<ll,ll> P,curr;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  //freopen("input.txt","r",stdin);
  cin >> N >> L;
  for (ll i = 0; i < N; ++i){
    cin >> speed[i] >> a;
    for(ll x = 0; x < a; ++x){
      cin >> b;stairs[i].pb(b);
    }
    sort(stairs[i].begin(),stairs[i].end());
  }
  stairs[N-1].pb(L);
  for (auto it : stairs[0])P[it] = (it-1)*speed[0];
  for (ll i = 1; i < N; ++i){
    ll l = 0, h = 0;
    for (auto it : stairs[i])curr[it] = -1;
    while(l<stairs[i-1].size() && h<stairs[i].size()){
     if (stairs[i-1][l] <= stairs[i][h]){
        ll ind = stairs[i-1][l];
        // We handle the insertion of lower one first
        ll wgt = (L-ind)*speed[i] + P[ind];
        while (cur.size()){
          if(cur.back().s > wgt){
            cur.pop_back();
          }else break;
        } 
        cur.pb(mp(ind,wgt));
        l++;
     }else{
		 if(!cur.size()){h++;continue;}
       ll ind = stairs[i][h];
       ll wgt = cur[0].s - (L-ind)*speed[i];
       if (curr[ind] == -1)curr[ind] = wgt;
       else curr[ind] = min(curr[ind],wgt);
       h++;
     }
    }
    while(h<stairs[i].size()){
		if(!cur.size()){h++;continue;}
	   ll ind = stairs[i][h];
       ll wgt = cur[0].s - (L-ind)*speed[i];
       if (curr[ind] == -1)curr[ind] = wgt;
       else curr[ind] = min(curr[ind],wgt);
       h++;
	}
    cur.clear();
    l = stairs[i-1].size()-1;
    h = stairs[i].size()-1;
    while(l>=0&&h>=0){
     if (stairs[i-1][l] >= stairs[i][h]){
        ll ind = stairs[i-1][l];
        // We handle the insertion of lower one first
        ll wgt = ind*speed[i] + P[ind];
        while (cur.size()){
          if(cur.back().s > wgt){
            cur.pop_back();
          }else break;
        } 
        cur.pb(mp(ind,wgt));
        l--;
     }else{
	   if(!cur.size()){h--;continue;}
       ll ind = stairs[i][h];
       ll wgt = cur[0].s - ind*speed[i];
       if (curr[ind] == -1)curr[ind] = wgt;
       else curr[ind] = min(curr[ind],wgt);
       h--;
     }
    }
    
    while (h>=0){
		if(!cur.size()){h--;continue;}
	   ll ind = stairs[i][h];
       ll wgt = cur[0].s - ind*speed[i];
       if (curr[ind] == -1)curr[ind] = wgt;
       else curr[ind] = min(curr[ind],wgt);
       h--;
	}
    swap(curr,P);
    cur.clear();
    curr.clear();
  }
  cout << P[L];
}
