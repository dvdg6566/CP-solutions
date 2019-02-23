#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
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

ll T, N;
stack<char> S,S2;

void calc(ll T){
  ll digits = 0, cur=9;
  for (int it = 1; it < 20; ++it){
    if (it % 2 && it != 1)cur *= 10;
    digits++;
    if (cur > T)break;
    T -= cur;
  }
  // cout<<digits<<' '<<T<<'\n';
  ll half = (digits+1)/2;
  // cout<<half<<'\n';
  for (int i=0;i<half; ++i){
    if (i+ 1 == half)S.push(T+'1');
    else S.push((T%10) + '0');
    T /= 10;
  }
  while(S.size()){
    S2.push(S.top());
    cout<<S.top();
    S.pop();
  }
  if (digits % 2){
    S2.pop();  
  }
  while(S2.size()){cout<<S2.top();S2.pop();}
}

int main(){
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  cin>>T;
  --T;--T;
  calc(T);
  // return 0;
  // for (int i=0;i<=1000;++i){
    // calc(i);
    // cout<<'\n';
  // }
}
