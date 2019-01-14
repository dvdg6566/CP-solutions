#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MOD 1e9+7
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()

priority_queue<ll> lft;
priority_queue<ll, vector<ll>, greater<ll>> rght;
ll N,S[200100],K,ans;

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin>>N>>K;
  for (int i=0;i<N;++i)cin>>S[i];
  rght.push(S[0]);
  lft.push(S[0]);
  for (ll i=1;i<N;++i){
    ll cur_offset = i*K;
    ll rt = rght.top() + cur_offset;
    ll lt = lft.top() - cur_offset;
    if (S[i] < lt){
      lft.push(S[i] + cur_offset);
      lft.push(S[i] + cur_offset);
      ll t = lt - cur_offset;
      rght.push(t);
      lft.pop();
      ans += abs(lt - S[i]);
    }
    else if (S[i] > rt){
      rght.push(S[i] - cur_offset);
      rght.push(S[i] - cur_offset);
      ll t = rt + cur_offset;
      lft.push(t);
      rght.pop();
      ans += abs(rt - S[i]);
    }else {
      lft.push(S[i] + cur_offset);
      rght.push(S[i] - cur_offset);
    }
  }
  cout<<ans;
}
