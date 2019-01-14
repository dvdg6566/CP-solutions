#include<bits/stdc++.h>
using namespace std;
string s;
#define pb push_back
int TC;
int a,b,c,N,l,E;
int h[100000],pre[100000],ind[100000];
vector<int> V;
stack<int> S;

int cnv (string X){
  int res = 0,mul= 1;
  while (X.size()){
    res += mul*(X[X.size()-1]-'0');
    mul = mul*10;
    X=X.substr(0,X.size()-1);
  }
  return res;
}

void LIS(){
	//for (auto i : V)cout << i;
  int l = 0;
  for (int i = 1; i <= N; ++i){
    int p = lower_bound(h,h+l,V[i])-h;
    h[p] = V[i];
    ind[p] = i;
    pre[i] = ind[p-1];
    if (p+1>=l){
      l = p+1;
      E = i;
    }
  }
  cout << "Max hits: " << l << '\n';
  while (pre[E]!=0){
	S.push(V[E]);
	E=pre[E];
  }
  S.push(V[E]);
  while (S.size()){
	cout << S.top() << '\n';
	S.pop();
  }
  if(TC!=0)cout << '\n';
}

int main (){
	V.pb(0);
  //freopen("input.txt","r",stdin);
  getline(cin,s);
  TC = cnv(s);
  getline(cin,s);
  while (true){
    getline(cin,s);
    if (s == ""){
      TC--;
      LIS();
      if(!TC)return 0;
      V.clear();
      memset(h,0,sizeof(h));
      memset(ind,0,sizeof(ind));
      memset(pre,0,sizeof(pre));
      l = 0;
      N=0;
      V.pb(0);
    }else{
      N++;
      a = cnv(s);
      V.pb(a);
    }
  }
}
