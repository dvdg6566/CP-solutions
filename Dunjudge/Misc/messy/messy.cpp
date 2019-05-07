#include "messy.h"
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
int INF = 1e8;
int MOD = 1e9;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()

int N;

string clean(){
  string t = "";
  for (int i=0;i<N;++i){
    t+='1';
  }
  return t;
}

vi res;

void add(int s, int e){
  if (s == e)return;
  int m = (s+e)/2;
  string q = clean();
  for (int i=s;i<=e;++i)q[i] = '0';
  for (int i=s;i<=m;++i){
    q[i] = '1';
    add_element(q);
    q[i] = '0';
  }
  add(s,m);add(m+1,e);
}

void fill (int s, int e, vi options){
  //cout<<"From " << s << " to " << e << ": ";
  //for (auto v : options)cout<<v<<' ';cout<<'\n';
  if (s == e){
    res[options[0]] = s;
    return;
  }
  vi left,right;
  int m = (s+e)/2;
  string q = clean();
  for (auto i : options)q[i] = '0';
  for (auto i : options){
    q[i] = '1';
    if (check_element(q)){
      left.pb(i);
    }else right.pb(i);
    q[i] = '0';
  }
  fill (s, m, left);
  fill(m+1,e,right);
}

vi restore_permutation(int n, int w, int r){
  N = n;
  vi opt;
  for (int i=0;i<N;++i)opt.pb(i);
  res.resize(N,0);
  add(0, n-1);
  compile_set();
  fill (0,n-1, opt);
  return res;
}