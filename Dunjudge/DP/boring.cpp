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
#define SZ(x) (int)x.size()
#define INF 1000000000

ll A[30];
map<ll,ll> M[30];
ll ans;
string S;
ll rs[500100];

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input.txt","r",stdin);
  for (int i=0;i<26;++i)cin>>A[i];
  cin>>S;
  for (int i=1;i<=S.size();++i){
    rs[i] = A[S[i-1] - 'a'];
    rs[i] += rs[i-1];
  }
  // for(int i=1;i<=S.size();++i)cout<<rs[i]<<' ';cout<<'\n';
  for (int i=1;i<=S.size();++i){
    ++M[S[i-1] - 'a'][rs[i-1]];
    ans += M[S[i-1] - 'a'][rs[i]];
  }
  cout << ans;
}
