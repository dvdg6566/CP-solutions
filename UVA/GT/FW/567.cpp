#include<bits/stdc++.h>
using namespace std;

#define INF 100000000

int N,a,b,c,cnt;
int adjMat[25][25];
string s;

int main(){
	N=20;
	//freopen("input.txt","r",stdin);
	while(1){
		cnt++;
		for(int i=1;i<=N;++i){
			for(int j =1;j<=N;++j){
				adjMat[i][j]=INF;
				if(i==j)adjMat[i][i]=0;
			}
		}
		
		for (int i = 1; i < N; ++i){
			cin>>a;
			if(i==1){if(cin.eof())return 0;}
			while(a--){
				cin>>b;
				adjMat[i][b]=1;
				adjMat[b][i]=1;
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
		cout << "Test Set #" << cnt << '\n';
		cin>>c;
		while(c--){
			cin >> a >> b;
			if(a<10)cout<<' ';
			cout<<a<<" to ";
			if(b<10)cout<<' ';
			cout << b << ": " << adjMat[a][b] << '\n';
		}
		cout << '\n';
	}
}

