#include<bits/stdc++.h>
using namespace std;

#define INF 100000000

int N,a,b,c,cnt;
int adjMat[150][150];
string s;

int cnv(string s){
	reverse(s.begin(),s.end());
	int res=0,mul=1;
	for(auto i:s){
		res+=(i-'0')*mul;
		mul*=10;
	}
	return res;
}

int main(){
	//freopen("input.txt","r",stdin);
	while(1){
		cin>>N;
		if(cin.eof())return 0;
		
		for(int i=1;i<=N;++i){
			for(int j =1;j<=N;++j){
				adjMat[i][j]=INF;
			}
		}
		
		for (int i=1; i <= N; ++i){
			for (int j=1; j < i; ++j){
				cin >> s;
				if(s=="x")continue;
				a=cnv(s);
				adjMat[i][j]=a;
				adjMat[j][i]=a;
			}
		}
		
		for (int k =1; k <=N; k++){
			for (int i = 1; i <=N; i++){
				for (int j = 1; j <=N; j++){
					if (adjMat[i][k] + adjMat[k][j] < adjMat[i][j]) {
						adjMat[i][j] = adjMat[i][k] + adjMat[k][j];
					}
				}
			}
		}
		c=0;
		for (int i = 2; i <= N; ++i){
			c=max(c,adjMat[1][i]);
		}
		cout << c << '\n';
	}
}
