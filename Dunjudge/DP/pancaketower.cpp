#include<bits/stdc++.h>
using namespace std;

char c;
int N,t;

deque<int> dq;
int flip;

int h[1000001], forwards[1000001], backwards[1000001], oth[1000001];
vector<int> des;

int main(){
  // freopen("in.txt","r",stdin);
  cin >> N;
  for (int i=0;i<N;++i){
    cin >> c;
    if (c == 'F'){
      flip = 1-flip;
      continue;
    }
    cin >> t;
    des.push_back(t);
    if (flip)dq.push_front(t);
    else dq.push_back(t);
  }
  sort(des.begin(), des.end());
  des.resize(unique(des.begin(), des.end()) - des.begin());

  if (flip)reverse(dq.begin(), dq.end());
  int l=0;

  N = dq.size();
  // for (auto it : dq)cout<<it<<' ';cout<<'\n';
  for (int i=0;i<N;++i){
    int p = lower_bound(h, h+l, dq[i])-h;
    h[p] = dq[i];
    l = max(p+1, l);
    forwards[i] = p+1;
  }

  l=0;
  reverse(dq.begin(), dq.end());
  for (int i=0;i<N;++i){
    int p = lower_bound(h, h+l, dq[i])-h;
    h[p] = dq[i];
    l = max(p+1, l);
    backwards[N-1-i] = l;
  }

  int ans = 0;
  for (int i=0;i<N;++i){
    ans = max(ans, forwards[i+1] + backwards[i] - 1);
  }

  ans = max(ans, backwards[0]);
  cout<<N-ans;
}
