#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef double dl;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MOD 1e9+7
#define lb lower_bound
#define ub upper_bound
#define INF 1000000000
multiset<int> S;
vpi V;
int A[1000100],N, R[10001000],cnt,a;

bool cmp(pi a, pi b){
  if (a.f != b.f)return a.f < b.f;
  return a.s > b.s;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin >> N;
  for (int i = 0; i < N; ++i){
    cin >> a;
    V.pb(mp(a,0));
  }
  for(int i = 0; i < N; ++i)cin >> V[i].s;
  sort(V.begin(),V.end(),cmp);
  // for (auto i : V)cout << i.s << ' ';cout << '\n';
  for (int i = 1; i <= N; ++i)A[i] = V[i-1].s;
  R[1] = A[1];
  for (int i = 2; i <= N; ++i){
    R[i] = min(R[i-1],A[i]);
  }
  for (int i= N; i > 0; --i){
    auto it = S.ub(A[i]);
    if (it == S.end())S.insert(A[i]);
    else {
      S.erase(it);
      if (A[i] > R[i-1])S.insert(A[i]);
      else {++cnt;}
    }
    while(S.size() && *(--(S.end())) <= R[i-1]){
      //cout << "erasing " << *(--S.end()) << '\n';
      S.erase(--S.end());
      ++cnt;
    }
  }
  //for (auto i : S)cout << i << ' ';cout << '\n';
  cout << S.size()+cnt;
}
