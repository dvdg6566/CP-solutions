#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef set<int> si;
typedef vector<pi> vpi;
typedef long double ld;

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(),x.end()
#define SZ(x) (ll)x.size()

int p[100100],N,a,b,K;
int full[100100], half[100100], fullfull[100100], fullhalf[100100];
vi aList[100100];
vpi childfull, childhalf, childfullhalf;


void dfs(int x){
	full[x] = half[x] = fullfull[x] = fullhalf[x] = 0;
	if ((x != 1 && SZ(aList[x]) == 1) || SZ(aList[x]) == 0){
		return;
	}
	for (auto it : aList[x]){
		if (p[x] == it)continue;
		p[it] = x;
		dfs(it);
		half[x] = max(half[x], half[it] + 1);
		full[x] = max({full[x], full[it]});
		fullhalf[x] = max({fullhalf[x], fullhalf[it] + 1});
		fullfull[x] = max({fullfull[x], fullfull[it]});
	}

	full[x] = max(full[x], half[x]);
	fullhalf[x] = max({fullhalf[x], full[x]});
	fullfull[x] = max(fullhalf[x], fullfull[x]);

	for (auto it : aList[x]){
		if (p[x] == it)continue;
		childfull.pb(mp(full[it], it));
		childhalf.pb(mp(half[it], it));
		childfullhalf.pb(mp(fullhalf[it], it));
	}
	
	if (SZ(childfull) < 2){
		childfull.clear();
		childhalf.clear();
		childfullhalf.clear();
		return;
	}
	
	sort(ALL(childfull)); sort(ALL(childhalf)); sort(ALL(childfullhalf));
	reverse(ALL(childfull)); reverse(ALL(childhalf)); reverse(ALL(childfullhalf));
	
	full[x] = max(full[x], childhalf[0].f + childhalf[1].f + 2); // Half+Half=full
	fullfull[x] = max({fullfull[x], childfull[0].f + childfull[1].f});
	
	// fullfull is fullhalf + half
	if (childfullhalf[0].s == childhalf[0].s){
		int a = childfullhalf[0].f + childhalf[1].f + 2;
		int b = childfullhalf[1].f + childhalf[0].f + 2;
		fullfull[x] = max({fullfull[x], a, b});
	}else{
		fullfull[x] = max(fullfull[x], 2 + childfullhalf[0].f + childhalf[0].f);
	}
	// fullhalf is full + half
	if (childhalf[0].s == childfull[0].s){
		int a = childfull[0].f + childhalf[1].f + 1;
		int b = childfull[1].f + childhalf[0].f + 1;
		//if (x == 1)cout<<a<<' '<<b<<'\n';
	    fullhalf[x] = max({fullhalf[x], a, b});
	}else{
		fullhalf[x] = max(fullhalf[x], childhalf[0].f + childfull[0].f + 1);
	}
	fullfull[x] = max(fullfull[x], fullhalf[x]);
	
	// fullfull is full half half
	if (SZ(childhalf) > 2){
		for (int i=0;i<=2;++i){
			int ind = childfull[i].s;
			int ans = childfull[i].f + childhalf[0].f + childhalf[1].f + 2;
			for (int j=0;j<=1;++j){
				if (ind == childhalf[j].s) {
				    ans = ans - childhalf[j].f + childhalf[2].f; break;
				}
			}
			fullfull[x] = max(fullfull[x], ans);
		}
	}

  // fullhalf is half half half
  if (SZ(childhalf) > 2){
    fullhalf[x] = max(fullhalf[x], childhalf[0].f + childhalf[1].f + childhalf[2].f + 3);
  }
  fullfull[x] = max(fullfull[x], fullhalf[x]);

  //fullfull is 4*hafl
  if (SZ(childhalf) > 3){
    fullfull[x] = max(fullfull[x],  childhalf[0].f + childhalf[1].f + childhalf[2].f + childhalf[3].f +4);
  }
	
	childfull.clear();
	childhalf.clear();
	childfullhalf.clear();
}

int d[100100];
queue<int> q;

void bfs(int start){
  memset(d, -1, sizeof(d));
  q.push(start);
  while(SZ(q)){
    int x = q.front();
    q.pop();
    for (auto i : aList[x]){
      if (d[i] != -1)continue;
      d[i] = d[x] + 1;
      q.push(i);
    }
  }
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
  // freopen("input.txt","r",stdin);
	cin>>N>>K;
	for (int i=1;i<N;++i){
		cin>>a>>b;
		aList[a].pb(b);
		aList[b].pb(a);
	}
  if (K == 1){
    bfs(1);
    int p = max_element(d, d+N+1) - d;
    bfs(p);
    cout<< (N-1)*2 - *max_element(d, d+N+1);
    return 0;
  }
	dfs(1);
  // for (int i=1;i<=N;++i){
    // cout<<i<< ": "<<half[i]<<' '<<full[i] << ' '<<fullhalf[i]<<' '<<fullfull[i]<<'\n';
  // }
	int ans = 0;
	for (int i=1;i<=N;++i){
		ans = max({ans,fullfull[i], fullhalf[i]});
	}
	cout<<2*N - ans;
}
