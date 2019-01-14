#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef double dl;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MOD (ll)1000000007
#define lb lower_bound
#define ub upper_bound
#define dst distance
#define INF 1000000000

vi big; // X[j]
vi ymax; // max(Y[j...N-1])
vi pos; // Positions of the non-1 numbers

ll Ax[500100], Ay[500100], L, M;
ll dp[500100];

struct node {
  ll s, e, m;
  ll rangeM = 0, non1 = 0, overflow = 0, product;
  node *l, *r;
  node(int _s, int _e) {
    s = _s; e = _e; m = (s+e)/2;
    if (s!=e) {
		l = new node(s, m);
		r = new node(m+1, e);
		rangeM = l->rangeM+r->rangeM;
		non1 = l->non1+r->non1;
		overflow = l->overflow||r->overflow;
		product = l->product*r->product;
		if (product >= MOD) {product %= MOD; overflow = 1;}
    }else{
		//Leaf node
		rangeM = Ay[s];
		non1 = (Ax[s] != 1);
		product = Ax[s];
		overflow = 0;
	}
  }
  void updateDataX(int pos, int val){
	    if (s == e){
			non1 = (val != 1);
			product = val;
			overflow = 0;
			return;
		}
	    if(pos > m){r->updateDataX(pos,val);}
		if(pos <= m){l->updateDataX(pos,val);}
		non1 = l->non1 + r->non1;
		overflow = (l->overflow || r->overflow);
		product = l->product*r->product;
		if (product >= MOD) {product %= MOD; overflow = 1;}
  }
  void updateDataY(int pos, int val){
		if (s == e){	
			rangeM = val;
			return;
		}
		if(pos > m){r->updateDataY(pos,val);}
		if(pos <= m){l->updateDataY(pos,val);}
		rangeM = l->rangeM+r->rangeM;
  }
  void dfs(ll yMax, ll P){
		if (s == e){
			// Leaf node
			big.pb(product); // X value
			ymax.pb(max(yMax,rangeM)); // Y value
			pos.pb(s); // Position
			return;
		}
		if (r->non1 > 0){r->dfs(yMax,P);}
		P *= r->product;
		if (P>=MOD || r->overflow)return;
		yMax = max(yMax,r->rangeM);
		if (l->non1>0){l->dfs(yMax,P);}
  }
  
}*root;


ll calc(){
	big.clear();
	ymax.clear();
	pos.clear();
	root->dfs(1,1);
	big.pb(1);ymax.pb(M);pos.pb(-1);
	ll product = 1;
	int bestI = -1;
	for (int i=0;i<big.size();i++) {
		if (product <= ymax[i]) bestI = i; // better to sell than wait
		product = max(product*big[i], big[i]*(ll)ymax[i]); // update to compare to next value
	}
	return dp[pos[bestI]+1]*ymax[bestI]%MOD;
}


int init(int N, int X[], int Y[]) {
	memset(dp,0,sizeof(dp));
	for (int i = 0; i < N; ++i){
		Ax[i] = (ll)X[i];
		Ay[i] = (ll)Y[i];
		M = max(M,(ll)Y[i]);
		dp[i] = (ll)X[i];
		if(i!=0)dp[i] = dp[i] * dp[i-1];
		dp[i] = dp[i] % MOD;
	}
	L = N;
	root = new node(0,N-1);
	return calc();
}

int updateX(int pos, int val) {
	root->updateDataX(pos,val);
	return calc();
}

int updateY(int pos, int val) {
	root -> updateDataY(pos,val);
	return calc();
}








static char _buffer[1024];
static int _currentChar = 0;
static int _charsNumber = 0;

static inline int _read() {
    if (_charsNumber < 0) {
        exit(1);
    }
    if (!_charsNumber || _currentChar == _charsNumber) {
        _charsNumber = (int)fread(_buffer, sizeof(_buffer[0]), sizeof(_buffer), stdin);
        _currentChar = 0;
    }
    if (_charsNumber <= 0) {
        return -1;
    }
    return _buffer[_currentChar++];
}

static inline int _readInt() {
    int c, x, s;
    c = _read();
    while (c <= 32) c = _read();
    x = 0;
    s = 1;
    if (c == '-') {
        s = -1;
        c = _read();
    }
    while (c > 32) {
        x *= 10;
        x += c - '0';
        c = _read();
    }
    if (s < 0) x = -x;
    return x;
}


int main() {
	freopen("input.txt","r",stdin);
	int N; N = _readInt();

	int *X = (int*)malloc(sizeof(int)*(unsigned int)N);
	int *Y = (int*)malloc(sizeof(int)*(unsigned int)N);

	for (int i = 0; i < N; i++) {
		X[i] = _readInt();
	}

	for (int i = 0; i < N; i++) {
		Y[i] = _readInt();
	}	

	printf("%d\n",init(N,X,Y));

	int M; M = _readInt();

	for (int i = 0; i < M; i++) {
		int type; type = _readInt();
		int pos; pos = _readInt();
		int val; val = _readInt(); 

		if (type == 1) {
			printf("%d\n",updateX(pos,val));
		} else if (type == 2) {
			printf("%d\n",updateY(pos,val));
		}
	}

	return 0;
}

