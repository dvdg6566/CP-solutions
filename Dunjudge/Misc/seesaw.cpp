#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define MAXN 1000000


/* Symbol obfuscation */
#define N night
#define R rar
#define D rawr
#define num_calls fishes

static int N, R, num_calls;
static int D[MAXN];

void answer(int min_bag, int max_bag) {
    if (min_bag < 0 || max_bag < 0 || min_bag >= N || max_bag >= N) {
		fprintf(stderr, "Wrong Answer\nbag returned are out of range (0 to N-1).\n");
		exit(1);
	}
	printf("%d %d\n", min_bag, max_bag);
    exit(0);
}
bool less_than (int X, int Y) {
	if (X < 0 || Y < 0 || X >= N || Y >= N) {
		fprintf(stderr, "Parameters passed to less_than(int X, int Y) are out of range (0 to N-1).\n");
		exit(1);
	}
	if (++num_calls > R) {
		fprintf(stderr, "Too many calls to less_than(int X, int Y).\n");
		exit(1);
	}
	return D[X] < D[Y];
}

vector<int> top[2], btm[2];
int low,upp;

void seesaw(int N, int R) {
  for (int i=0;i<N;i+=2){
    if (i + 1 == N){top[0].pb(i); btm[0].pb(i);break;}
    if (less_than(i, i+1)){
      btm[0].pb(i);
      top[0].pb(i+1);
    }else{
      btm[0].pb(i+1);
      top[0].pb(i);
    }
  }

  for (int i=1;i<=20;++i){
    //for (auto i : top[1-i%2])cout<<i<<' ';cout<<'\n';
    if (top[1-i%2].size() == 1){
      upp = top[1-i%2][0];
      break;
    }
    top[i%2].clear();
    for (int j=0;j<top[1-i%2].size();j+=2){
      if (j == top[1-i%2].size())top[i%2].pb(top[1-i%2][j]);
      else if (less_than(top[1-i%2][j], top[1-i%2][j+1])) top[i%2].pb( top[1-i%2][j+1]);
      else top[i%2].pb( top[1-i%2][j]);
    }
  }

  for (int i=1;i<=20;++i){
    //for (auto i : btm[1-i%2])cout<<i<<' ';cout<<'\n';
    if (btm[1-i%2].size() == 1){
      low = btm[1-i%2][0];
      break;
    }
    btm[i%2].clear();
    for (int j=0;j<btm[1-i%2].size();j+=2){
      if (j == btm[1-i%2].size())btm[i%2].pb(btm[1-i%2][j]);
      else if (less_than(btm[1-i%2][j], btm[1-i%2][j+1])) btm[i%2].pb( btm[1-i%2][j]);
      else btm[i%2].pb( btm[1-i%2][j+1]);
    }
  }
  answer(low,upp);
}

int main() {
	scanf("%d%d", &N, &R);
	for (int i = 0; i < N; ++i) scanf("%d", &D[i]);
	seesaw(N, R);
	fprintf(stderr, "Your solution did not call answer(int min_bag, int max_bag)!\n");
	return 1;
	
}
