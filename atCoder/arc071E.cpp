#include<bits/stdc++.h>
using namespace std;

string st1, st2;
int pref1[100100], pref2[100100];
int Q,a,b,c,d;

int main(){
  cin >> st1 >> st2;
  for (int i=0;i<st1.size();++i){
    pref1[i+1] = (st1[i] == 'A');
    pref1[i+1] += pref1[i];
  }
  for (int i=0;i<st2.size();++i){
    pref2[i+1] = (st2[i] == 'A');
    pref2[i+1] += pref2[i];
  }
  cin >> Q;
  while(Q--){
    cin >>a >>b >> c >> d;
    int t = (pref1[b] - pref1[a-1])%3;
    int t2 = (pref2[d] - pref2[c-1])%3;
    int tb = (b - a + 4 - t)%3;
    int t2b = (d - c + 4 - t2)%3;
    int td = (t + 3 - tb)%3;
    int t2d = (t2 + 3 - t2b)%3;

    if (td == t2d)cout<<"YES\n";
    else cout << "NO\n";
  }
}