#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end

ll N,t,a,b,c;
string S;

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin>>N;
  for (int i=0;i<N;++i){
    cin>>S;
    t = 0;
    for (auto i : S){
      if (i == '-')continue;
      t += i-'0';
    }
    if (S[0] == '-')t = -t;
    t %= 3;
    if (t <0)t += 3;
    if (t == 0)++a;
    if (t == 1)++b;
    if (t==2)++c;
  }
  assert(a+b+c==N);
  a = 2-(a%2);
  b=2-(b%2);
  c =2-(c%2);
  bool peanut;
  if (a == 2 && b == 2 && c == 2)peanut = 0;
  if (a == 2 && b == 2 && c == 1)peanut = 1;
  if (a == 2 && b == 1 && c == 2)peanut = 1;
  if (a == 1 && b == 2 && c == 2)peanut = 0;
  if (a == 1 && b == 1 && c == 2)peanut = 1;
  if (a == 2 && b == 1 && c == 1)peanut = 1;
  if (a == 1 && b == 2 && c == 1)peanut = 1;
  if (a == 1 && b == 1 && c == 1)peanut = 1;
  if (peanut)cout<<"Peanut";
  else cout <<"RAR";
}
