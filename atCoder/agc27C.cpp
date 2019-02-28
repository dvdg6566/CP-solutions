#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<int,int> pi;
typedef pair<int,pi> pii;
typedef vector<pi> vpi;
typedef set<int> si;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define f first
#define s second
ll INF = 1e15;
ll MOD = 1e9;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()

int N,M,a,b;
string S;
vi aList[200100];
int R[200100][2];
vi V;
int cnt;
stack<int> stk;

int main(){
  // freopen("input.txt","r",stdin);
  cin>>N>>M;
  cin >> S;
  for (auto i : S){
    if (i == 'A')V.pb(0);
    else V.pb(1);
  }
  for (int i=0;i<M;++i){
    cin>>a>>b;
    --a;--b;
    aList[a].pb(b);
    aList[b].pb(a);
    R[a][V[b]]++;
    R[b][V[a]]++;
  }
  for (int i=0;i<N;++i){
    if (R[i][0] == 0 || R[i][1] ==  0){
      stk.push(i);
    }else{
      ++cnt;
    } 
  }
  while(SZ(stk)){
    int x = stk.top(); stk.pop();
    // cout<<"Top " << x<<'\n';
    for (auto i : aList[x]){
      if (R[i][0] == 0 || R[i][1] == 0)continue;
      R[i][V[x]]--;
      if (R[i][V[x]] == 0){
        stk.push(i);
        --cnt;
      }
    }
  }
  // cout<<cnt<<'\n';
  if (cnt)cout<<"Yes";
  else cout << "No";
}
