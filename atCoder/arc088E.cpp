#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef vector<ll> vi;
typedef vector<pi> vpi;
#define f first
#define pb push_back
#define s second
#define mp make_pair
#define SZ(x) (int)x.size()
ll INF = 1e9;

string st;
ll hist[30], odd, N;
deque<ll> dq[30];
ll fw[200100];
pi frontwgt[30], backwgt[30];
ll ans;

void update(ll x){
  // cout<<"Update " << x<<'\n';
  ++x;
  for (;x<=N+10;x+=x&(-x))fw[x] ++;
}
ll sum(ll x){
  // cerr<<"Sum " << x << '\n';
  ++x;
  ll res = 0;
  for (;x;x-=x&(-x))res +=fw[x];
  return res;
}

int main(){
  // freopen("in.txt","r",stdin);
  cin >> st;
  N = st.size();
  for (auto i : st){
    hist[i-'a']++;
  }
  for (ll i=0;i<N;++i){
    dq[st[i]-'a'].pb(i);
  }
  for (ll i=0;i<26;++i){
    if (hist[i]%2){
      ++odd;
    }
  }
  if (odd > 1){
    cout<<-1;
    return 0;
  }
  for (ll i=0;i<26;++i)frontwgt[i] = backwgt[i] = mp(INF, INF);
  for (ll i=0;i<26;++i){
    if (SZ(dq[i])){
      frontwgt[i] = mp(dq[i][0], dq[i][0]);
      backwgt[i] = mp(N - dq[i].back() - 1, dq[i].back());
    }
  }
  ll L = N/2;
  while(L--){
    ll wgt = INF, opt=-1;
    for (ll i=0;i<26;++i){
      if (wgt > frontwgt[i].f + backwgt[i].f){
        wgt = frontwgt[i].f + backwgt[i].f;
        opt = i;
      }
    }
    for (ll i=0;i<26;++i){
      if (frontwgt[i].s > frontwgt[opt].s && frontwgt[i].f != INF){
        --frontwgt[i].f;
      }
      if (frontwgt[i].s > backwgt[opt].s && frontwgt[i].f != INF){
        --frontwgt[i].f;
      }
    }
    ll t = 0;
    for (ll i=0;i<26;++i){
      t += SZ(dq[i]);
      if (backwgt[i].s < backwgt[opt].s && backwgt[i].f != INF){
        --backwgt[i].f;
      }
      if (backwgt[i].s < frontwgt[opt].s && backwgt[i].f != INF){
        --backwgt[i].f;
      }

      // if (opt == -1 && SZ(dq[i])){
        // cout<<backwgt[i].s<<' '<<frontwgt[i].s<<'\n';
      // }
    }
    // if(opt==-1)cout<<'\n';
    // cout<<L<<" Removing " << (char) ('a' + opt)<<' '<<t<<'\n';
    // cout<<wgt<<'\n';
    ans += wgt;
    update(frontwgt[opt].s);
    update(backwgt[opt].s);
    dq[opt].pop_front();
    dq[opt].pop_back();
    if (SZ(dq[opt])){
      frontwgt[opt] = mp(dq[opt][0] - sum(dq[opt][0]), dq[opt][0]);
      backwgt[opt] = mp(N-1-dq[opt].back()-sum(N)+sum(dq[opt].back()), dq[opt].back());
    }else{
      frontwgt[opt] = mp(INF,INF);
      backwgt[opt] = mp(INF,INF);
    }
    // for (ll i=0;i<26;++i){
      // if (frontwgt[i].f != INF){
        // cout<<frontwgt[i].f<<' '<<frontwgt[i].s<<' '<<backwgt[i].f<<' '<<backwgt[i].s<<'\n';
      // }
    // }
  }
  cout<<ans;
}
