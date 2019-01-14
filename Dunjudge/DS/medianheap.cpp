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

priority_queue<int,vector<int>, greater<int>> big;
priority_queue<int> small;
int N,a;
string c;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin >> N;
  for (int i = 0; i < N; ++i){
    cin >> c ;
    if (c == "PUSH"){
      cin >> a;
      small.push(a);
      if (big.size() && small.top() > big.top()){
        int t = big.top();
        big.pop();
        big.push(small.top());
        small.pop();
        small.push(t);
      }
      if (small.size() - big.size() > 1){
        big.push(small.top());
        small.pop();
      }
    }else{
      small.pop();
      if (big.size() > small.size()){
        small.push(big.top());
        big.pop();
      }
    }
  }
  while(small.size()){
    big.push(small.top());
    small.pop();
  }
  while(big.size()){
    cout << big.top() << ' ';
    big.pop();
  }
}
