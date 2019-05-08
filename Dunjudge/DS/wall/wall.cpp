#include "wall.h"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<int, pi> pii;
typedef set<int> si;
typedef vector<pi> vpi;
typedef double dl;
#define mp make_pair
#define pb push_back
#define f first
#define s second
ll MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
#define INF 1000000000
#define SZ(x) x.size()
#define ALL(x) x.begin(),x.end()

vi des;
vi out;

struct node {
  int s, e, m, add = 0, rmv = INF;
  int latest = -1;
  node *l, *r;
  node(ll _s, ll _e) {
    s = _s; e = _e; m = (s+e)/2;
    if (s!=e) {
      l = new node(s, m);
      r = new node(m+1, e);
    }
  }
  void up(int x, int y, int val, int type) {
    if (s == x && e == y){
      if (type == 1){
      	if (val < add)return;
      	latest = 1; // Latest is adding
      	if (val > rmv){
      		rmv = val;
      		add = val;
      		return;
      	}
      	add = val;
      }
      else{
      	if (val > rmv)return;
      	latest = 2; // Latest is removing
      	if (add >= val){
      		add = val;
      		rmv = val;
      		return;
      	}
      	rmv = val;
      }
    }
    else {
      prop(0);
      if (x > m) r->up(x, y, val, type);
      else if (y <= m) l->up(x, y, val, type);
      else {
      	l->up(x, m, val,type);
      	r->up(m+1, y, val,type);
      }
    }
  }

  void prop(bool full){
    // cout<<"Prop " << s <<' '<<e<<' '<<add<<' '<<rmv<<' '<<latest<<'\n';
  	if (s == e)return;
  	if (latest != -1){
  		if (add != rmv){
        
        if (rmv < l->rmv){
          if(latest == 2 || add <= l->add)l->latest = 2;
        }
        if (add > l->add){
          l->add = add;
          if (latest == 1 || rmv >= l->rmv)l->latest = 1;
        }

        if (rmv < l->rmv){
          l->rmv = rmv;
        }


		  	if (l->add >= l->rmv){
		  		// If add is later
		  		if (l->latest == 1){
		  			l->rmv = l->add;
		  		}else if (l->latest == 2){
		  			l->add = l->rmv;
		  		}
		  	}

        // if (s == 14 && e == 17)cout<<"Running Prop " << add << ' ' << rmv << ' ' << latest << " onto " << r->add<<' '<<r->rmv<<' '<<r->latest<<'\n';
		  	if (rmv < r->rmv){
          if(latest == 2 || add <= r->add)r->latest = 2;
        }
        if (add > r->add){
          r->add = add;
          if (latest == 1 || rmv >= r->rmv)r->latest = 1;
        }

        if (rmv < r->rmv){
          r->rmv = rmv;
        }

        // if (s == 14 && e == 17)cout<<"Status " << r->add<<' '<<r->rmv<<' '<<r->latest<<'\n';


		  	if (r->add >= r->rmv){
		  		// If add is later
		  		if (r->latest == 1){
		  			r->rmv = r->add;
		  		}else if (r->latest == 2){
		  			r->add = r->rmv;
		  		}
		  	}

	  	}
	  	else{
	  		l->add = l->rmv = r->add = r->rmv = add;
        l->latest = r->latest = latest;
	  	}

	  	add = 0;
  		rmv = INF;
  		latest = -1;
  	}
  	assert(add == 0 && rmv ==INF);
  	if (!full)return;
  	l->prop(full);
  	r->prop(full);
  }

  void fill(){
  	if (s == e){
  		if (latest == 1 || rmv > add)out[s] = add;
  		else if (latest == 2)out[s] = rmv;
  	}else{
  		l->fill();r->fill();
  	}
  }

  void db(){
  	cout<<"From " << s << " to " << e << " Add " << add << " Remove " << rmv <<' ' <<" with latest " << latest<< '\n';
  	if (s == e)return;
  	l->db();
  	r->db();
  }
    
}*root;

int N;
vi res;

void buildWall(int n, int k, int op[], int left[], int right[], int height[], int finalHeight[]){
  // for (int i=0;i<k;++i){
  //   des.pb(right[i]);
  //   des.pb(left[i]);
  //   des.pb(right[i] + 1);
  //   des.pb(left[i]+1);
  //   if (right[i])des.pb(right[i] - 1);
  //   if (left[i])des.pb(left[i] - 1);
  // }
  // des.pb(0);
  // des.pb(1);
  // des.pb(n-1);
  // sort(ALL(des));
  // des.resize(unique(ALL(des)) - des.begin());
  // if (des.back() >= n)des.pop_back();

  // N = SZ(des);
  // // for (auto i : des)cout<<i<<' ';cout<<'\n';
  // out.resize(N,0);
  // root = new node (0, N-1);
  // for (int i=0;i<k;++i){

  // 	int l = lb(ALL(des), left[i]) - des.begin();
  // 	int r = lb(ALL(des), right[i]) - des.begin();
  //   cout<< op[i]<<' '<<l << ' ' << r << ' '<<height[i]<<' '<<'\n';
  //   root->up(l,r,height[i], op[i]);
  //   root->prop(1);
  //   // root->db();
  //   // cout<<'\n';
  // }

  // root->prop(1);
  // root->fill();
  // // root->db();
  // // for (auto i : out)cout<<i<<' ';cout<<'\n';
  // des.pb(n);
  // for (int i=0;i<N;++i){
  // 	for (int k=des[i];k<des[i+1];++k)res.pb(out[i]);
  // }

  // for (int i=0;i<n;++i)finalHeight[i] = res[i];
  res.clear();
  des.clear();
  for (int i=0;i<k;++i){
    des.pb(right[i]);
    des.pb(left[i]);
    des.pb(right[i] + 1);
    des.pb(left[i]+1);
    if (right[i])des.pb(right[i] - 1);
    if (left[i])des.pb(left[i] - 1);
  }
  des.pb(0);
  des.pb(1);
  des.pb(n-1);
  sort(ALL(des));
  des.resize(unique(ALL(des)) - des.begin());
  if (des.back() >= n)des.pop_back();

  N = SZ(des);
  // for (auto i : des)cout<<i<<' ';cout<<'\n';
  out.resize(N,0);
  root = new node (0, N-1);
  for (int i=0;i<k;++i){

    int l = lb(ALL(des), left[i]) - des.begin();
    int r = lb(ALL(des), right[i]) - des.begin();
    // cout<<"Update " << l << ' ' << r << '\n';
    root->up(l,r,height[i], op[i]);
    // root->prop(1);
    // root->db();
    // cout<<'\n';
  }

  root->prop(1);
  root->fill();
  // root->db();
  // for (auto i : out)cout<<i<<' ';cout<<'\n';
  des.pb(n);
  res.clear();
  for (int i=0;i<N;++i){
    for (int k=des[i];k<des[i+1];++k)res.pb(out[i]);
  }

  for (int i=0;i<n;++i)finalHeight[i] = res[i];
  // bool cur = 1;
  // for (int i=0;i<n;++i)if (res[i] != finalHeight[i])cur = 0;
  // if(cur)cout<<"Correct\n";
  // else cout<<"Wrong\n";

  // for (int i=0;i<n;++i)if (res[i] != finalHeight[i])cout<<i<<' '<<res[i]<<' '<<finalHeight[i]<<'\n';
  return;
}