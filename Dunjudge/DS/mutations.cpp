#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef pair<ll,pi> pii;
typedef vector<pi> vpi;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MOD 1e9+7
ll INF = 1e15;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (ll)x.size()
#define ALL(x) x.begin(),x.end()


struct node{
   int s,e,m,v;
   node *l,*r;
   node(int _s, int _e){
     s=_s;e=_e;m=(s+e)/2;v=1;
     if (s == e)return;
     l = new node(s,m);
     r = new node(m+1, e);
   }

   void up (int a, int b, int c){
     // cout<<"Up " << s << ' ' <<e  << ' ' << a << ' ' << b << " to " << c << '\n';
     if (a == s && b == e){v = c;return;}
     if (v != -1)value();
     if (a > m)r->up(a,b,c);
     else if (b <= m)l->up(a,b,c);
     else l->up(a,m,c), r->up(m+1,b,c); 
   }

   int query(int x){
     // cout<<"Query " << x << " at " << s << ' ' << e << '\n';
     if (v != -1)return v;
     if (x > m)return r->query(x);
     if (x <= m)return l->query(x);
     assert(0);
   }

   void value(){
     if (s == e)return;
     r->v = v;l->v = v;
     v = -1;
   }
}*root;

vector<pair<pi,pi> > queries;
int N,Q,a,b,c,d;
char ch;
map<char,int> conv;
map<int,int> M;
vi des;

int main(){
  // freopen("input.txt","r",stdin);
  conv['A'] = 1;
  conv['C'] = 2;
  conv['G'] = 3;
  conv['T'] = 4;
  char rev[] = {'N','A','C','G','T'};
  cin>>N>>Q;
  for (int i=0;i<Q;++i){
    cin>>a;
    if (a ==1){
      cin>>b>>c>>ch;
      des.pb(b);des.pb(c);
      d = conv[ch];
      queries.pb(mp(mp(a,b), mp(c,d)));
    }
    else {
      cin>>b;
      des.pb(b);
      queries.pb(mp(mp(a,b), mp(-1,-1)));
    }
  }
  sort(ALL(des));
  des.resize(unique(ALL(des)) - des.begin());
  // for (auto i : des)cout<<i<<' ';cout<<'\n';
  for (int i=0;i<SZ(des);++i)M[des[i]] = i;
  root = new node(0, SZ(des)-1);
  for (auto i : queries){
    if (i.f.f == 1){
      // cout<<"Update " << M[i.f.s] <<' '<<M[i.s.f]<<' '<<i.s.s<<'\n';
      root->up(M[i.f.s], M[i.s.f], i.s.s);
    }
    else{
      // cout<<"Query " << M[i.f.s]<<'\n';
      cout<<rev[root->query(M[i.f.s])]<<'\n';
    }
  }
}
