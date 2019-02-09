#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef pair<ll,pi> pii;
typedef vector<ll> vi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define ALL(X) X.begin(),X.end()
#define SZ(X) (int)X.size()
#define lb lower_bound
#define ub upper_bound
ll MOD = 1e9+7;
ll INF = 1e15;
string S;

bool ispal(int l, int u){
  // cout<<l<<' '<<u<<'\n';
  if (l == u || l-1 == u)return 1;
  if (S[l] != S[u])return 0;
  return ispal(l+1, u-1);
}

ll a, b;
int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  // freopen("in.txt","r",stdin);
  cin>>a>>b;
  for (ll i=a;i<=b;++i){
    S = "";
    ll j=i;
    while(j!=0){
      S += (char)((j%10) + '0');
      j /= 10;
    }
    reverse(ALL(S));
    if (ispal(0, SZ(S)-1))cout<<"Palindrome!\n";
    else cout << i<<'\n';
  }
}
