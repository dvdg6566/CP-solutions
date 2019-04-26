#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,int> pii;
typedef vector<pi> vpi;
typedef set<int> si;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define f first
#define s second
ll INF = 1e9;
ll MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()

vi singles;
vpi have, block;
int N,a,b,c,M,K;

int clean[100100];
int closest[100100];
int l[100100], r[100100];
int fw[100100], p[100100], f[100100];
int X[100100];

void update(int x, int v){
  ++x;
  for (;x<=100050;x+=x&(-x))fw[x] += v;
}

int sum(int x){
  ++x;
  int res = 0;
  for (;x;x-=x&(-x))res+=fw[x];
  return res;
}

int rsq(int a, int b){
  if (a == 0)return sum(b);
  return sum(b) - sum(a-1);
}

bool cmp(pi a, pi b){
  return a.s < b.s;
}

int main(){
  // freopen("in.txt","r",stdin);
  cin >> N >> K >> M;
  int poo[100100];
  memset(poo, 0, sizeof(poo));
  for (int i=0;i<M;++i){
    cin >> a >> b >> c;
    if (c == 1){
      have.pb(mp(a,b));
    }
    else{
      block.pb(mp(a,b));
      poo[b+1]++;
      poo[a]-=1;
    }
    singles.pb(a);
    singles.pb(b+1);
  }
  int bad = 0;
  for (int i=1;i<=N;++i){
    poo[i] += poo[i-1];
    if (poo[i] == 0)++bad;
  }
  if (bad == K){
    for (int i=1;i<=N;++i)if (poo[i] == 0)cout<<i<<'\n';
    return 0;
  }
  sort(ALL(singles));
  singles.resize(unique(ALL(singles)) - singles.begin());
  // if (singles.back() > N)singles.pop_back();
  for (int i=0;i<SZ(block);++i){
    block[i].f = lb(ALL(singles), block[i].f) - singles.begin();
    block[i].s = ub(ALL(singles), block[i].s) - singles.begin() - 1;
  }
  for (int i=0;i<SZ(have);++i){
    have[i].f = lb(ALL(singles), have[i].f) - singles.begin();
    have[i].s = ub(ALL(singles), have[i].s) - singles.begin() - 1;
  }
  // for (auto i : have)cout<<i.f<<' '<<i.s<<'\n';
  // cout<<'\n';
  // for (auto i : block)cout<<i.f<<' '<<i.s<<'\n';
  // for (auto i : singles)cout<<i<<' ';cout<<'\n';
  for (auto i : block){
    clean[i.f]++;
    clean[i.s+1]--;
  }
  N = SZ(singles);
  for (int i=1;i<N;++i)clean[i] += clean[i-1];
  for (int i=0;i<N;++i){
    if (clean[i] != 0){
      clean[i] = -1;
    }
  }
  if (clean[0] == -1)p[0] = -1;
  else p[0] = 0;
  for (int i=1;i<N;++i){
    if (clean[i] == -1)p[i] = p[i-1];
    else p[i] = i;
  }
  if (clean[N-1] == -1)f[N-1] = N;
  else f[N-1] = N-1;
  for (int i=N-2;i>=0;--i){
    if (clean[i] == -1)f[i] = f[i+1];
    else f[i] = i;
  }
  // for (int i=0;i<N;++i)cout<<f[i]<<' ';cout<<'\n';
  // for (int i=0;i<N;++i)cout<<p[i]<<' ';cout<<'\n';
  for (int i=0;i<SZ(have);++i){
    have[i].f = f[have[i].f];
    have[i].s = p[have[i].s];
  }
  // for (auto i : have)cout<<i.f<<' '<<i.s<<'\n';
  sort(ALL(have), cmp);
  c = 0;
  for (auto it : have){
    if (rsq(it.f, it.s) == 0){
      X[it.s]++;
      update(it.s, 1);
      ++c;
    }
    if (l[it.s] == -1)l[it.s] = c;
  }
  memset(fw, 0, sizeof(fw));
  sort(ALL(have));
  reverse(ALL(have));
  c = 0;
  for (auto it : have){
    if (rsq(it.f, it.s) == 0){
      X[it.f]++;
      update(it.f, 1);
      ++c;
    }
    if (r[it.f] == -1)r[it.f] = c;
  }
  bool sing[100100];
  memset(sing,0,sizeof(sing));
  for (auto i : have)if (i.f == i.s)sing[i.f] = 1;

  // for (auto i : have)cout<<i.f<<' '<<i.s<<'\n';
  // for (int i=0;i<N;++i)cout<<X[i]<<' ';cout<<'\n';
  // for (auto i : singles)cout<<i<<' ';cout<<'\n';

  int trash = 0;
  singles.pb(singles.back() + 1);
  // cout<<c<<' '<<K<<'\n';
  for (int i=0;i<N;++i){
    if (sing[i]){
        if (singles[i+1] == singles[i] + 1)cout<<singles[i]<<'\n';
        else ++trash;
        continue;
    }
    if (c!=K){
      ++trash;
      continue;
    }
    if (X[i] == 2){
      if (singles[i+1] == singles[i] + 1)cout<<singles[i]<<'\n';
      else ++trash;
    }
    else ++trash;
  }
  
  if (trash == N)cout<<-1;
}
