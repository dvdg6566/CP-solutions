#include<bits/stdc++.h>
using namespace std;
#define pb push_back

int memo[65560];
string s;
int N,x;
vector<int> V;
bool tmp[65560];
stack<int> stk;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin>>N;
  for (int i=0;i<N;++i){
    cin>>s>>x;
    if (s == "add" || s == "del"){
      V.clear(); 
      V.pb(x);
      tmp[x] = 1;
      for (int i = 8; i < 16; ++i){
        int y = (1<<i);
        if (y & x)continue;
        for (auto j : V){
          if (tmp[j + y])continue;
          stk.push(j+y);
          tmp[j+y] = 1;
        }
        while (stk.size()){
          V.pb(stk.top());
          stk.pop();
        }
      }
      for (auto i : V){
        if (s == "add")memo[i] += 1;
        else memo[i] -= 1;
        tmp[i] = 0;
      }
    }
    if (s == "cnt"){
      int ans = 0;
      V.clear(); 
      V.pb(x);
      tmp[x] = 1;
      for (int i = 0; i < 8; ++i){
        int y = (1<<i);
        if (!(y & x))continue;
        for (auto j : V){
          if (tmp[j - y])continue;
          stk.push(j-y);
          tmp[j-y] = 1;
        }
        while (stk.size()){
          V.pb(stk.top());
          stk.pop();
        }
      }
      for (auto i : V){
        // cout << "Query " << i << '\n';
        ans += memo[i];
        tmp[i] = 0;
      }
      cout << ans << '\n';
    }
  }
}
