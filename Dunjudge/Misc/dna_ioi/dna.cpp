#include "dna.h"
#include<bits/stdc++.h>
using namespace std;
#define SZ(x) (int)x.size()

string s1, s2;
int lastone;

std::string analyse(int n, int t) {
  int minl = 0;
  int maxl = n;
  while(maxl > minl + 1){
    int mid = (maxl + minl)/2;
    string st = "";
    for (int it = 0;it<mid;++it)st += "0";
    if (make_test(st))minl = mid;
    else maxl = mid;
  }
  string st = "";
  for (int it = 0;it<maxl;++it)st += "0";
  if (make_test(st))minl = maxl;

  s1 = st;
  while (SZ(s1) != minl)s1.pop_back();
  int conszero = minl;
  while (1){
    s1 = "1" + s1;
    if (make_test(s1)){
      conszero = 0;
    }
    else{
      ++conszero;
      s1[0] = '0';
    }
    if (conszero > minl)break;
  }
  
  s1 = s1.substr(minl+1, SZ(s1) - minl-1);
  maxl = min(n - SZ(s1), minl + 1);
  minl = 0;
  // cerr<<s1<<'\n';

  while(maxl > minl + 1){
    int mid = (maxl + minl)/2;
    string st = "";
    for (int it = 0;it<mid;++it)st += "0";
    st += s1;
    if (make_test(st))minl = mid;
    else maxl = mid;
  }

  if (minl != maxl){
    st = "";
    for (int it = 0;it<maxl;++it)st += "0";
    st += s1;
    if (make_test(st))minl = maxl;
  }
  
  for (int i=0;i<minl;++i){
    s2 += "0";
  }
  s2 += s1;
  while (SZ(s2) < n){
    s2 += "1";
    if (!make_test(s2))s2.back() = '0';
  }
  return s2;
}
