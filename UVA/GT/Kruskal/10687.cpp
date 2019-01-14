#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;

#define f first
#define s second
#define mp make_pair
#define pb push_back

vector<pi> V;
vi adjList[1010];
int a,b,c,d,e,f,N;


int main(){
	//freopen("input.txt","r",stdin);
	while(1){
		V.clear();
		for (int i = 0; i < N; ++i)adjList[i].clear();
		cin >> N >> a >> b;
		V.pb(mp(a,b));
		for (int i = 0; i < N; ++i){
			cin >> c >> d;
			V.pb(mp(c,d));
		}
		sort(V.begin(),V.end());
		
		for (int i = 0; i < N; ++i){
			int closest;
			double shortest = 1234567890;
			for (int j = 0; j < N; ++j){
				double x = V[i].f-V[j].f;
				double y = V[i].s - V[j].s;
				if (sqrt((double)(x*x) + (double(y*y)) < shortest){
					shortest = sqrt((double)(x*x) + (double(y*y)));
					closest = j;
				}
			}
			adjList[i].pb(closest);
			int second;
			shortest = 1234567890;
			for (int j = 0; j < N; ++j){
				if(j==closest)continue;
				double x = V[i].f-V[j].f;
				double y = V[i].s - V[j].s;
				if (sqrt((double)(x*x) + (double(y*y)) < shortest){
					shortest = sqrt((double)(x*x) + (double(y*y)));
					closest = j;
				}
			}
			adjList[i].pb(closest);
		}
		
	}
}
