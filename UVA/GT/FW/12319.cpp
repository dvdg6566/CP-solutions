#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef vector<ll> vi;
typedef pair<pi,pi> pii;
typedef pair<int,pi> ii;
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define INF 100000000

int adjMat[110][100], pro[110][110];
int N,a,b,c;
string s,s1,s2;

int cnv(string s){
	int res = 0,mul=1;
	reverse(s.begin(),s.end());
	for(auto i : s){
		res+=(i-'0')*mul;
		mul*=10;
	}
	return res;
}

int main(){
	//freopen("input.txt","r",stdin);
	while(1){
		cin >> N;
		if(!N)return 0;
		cin.ignore();
		
		for(int i=1;i<=N;++i){
			for(int j = 1;j<=N;++j){
				adjMat[i][j]=INF;
				pro[i][j]=INF;
				if(i==j){adjMat[i][i]=0;pro[i][j]=0;}
			}
		}
		
		for(int i =1;i <= N; ++i){
			getline(cin,s);
			if(s.size()==1&&i<=9)continue;
			if(s.size()==2&&i<=99&&i>9)continue;
			if(s.size()==1&&i>99)continue;
			if(i<=9)s = s.substr(2,s.size()-2);
			else if(i<=99)s = s.substr(3,s.size()-3);
			else s = s.substr(4,s.size()-4);
			s1="";
			for (auto it : s){
				if(it==' '){
					a = cnv(s1);
					s1="";
					adjMat[i][a] = 1;
				}else s1 = s1+it;
			}
			if(s.size())adjMat[i][cnv(s1)]=1;
		}
		
		for(int i = 1;i<=N; ++i){
			getline(cin,s);
			if(s.size()==1&&i<=9)continue;
			if(s.size()==2&&i<=99&&i>9)continue;
			if(s.size()==1&&i>99)continue;
			if(i<=9)s = s.substr(2,s.size()-2);
			else if(i<=99)s = s.substr(3,s.size()-3);
			else s = s.substr(4,s.size()-4);
			s1="";
			for (auto it : s){
				if(it==' '){
					a = cnv(s1);
					s1="";
					pro[i][a] = 1;
				}else s1 = s1+it;
			}
			if(s.size())pro[i][cnv(s1)]=1;
		}
		
		cin >> a >> b;
		
		for (int k = 1; k <= N; ++k) {
			for (int i = 1; i <= N; ++i) {
				for (int j = 1; j <= N; ++j) {
					if (adjMat[i][k] == -1 || adjMat[k][j] == -1) continue;
					if (adjMat[i][j] == -1 || adjMat[i][j] > adjMat[i][k] + adjMat[k][j]) 
						adjMat[i][j] = adjMat[i][k] + adjMat[k][j];
				}
			}
		}
		
		for (int k = 1; k <= N; ++k) {
			for (int i = 1; i <= N; ++i) {
				for (int j = 1; j <= N; ++j) {
					if (pro[i][k] == -1 || pro[k][j] == -1) continue;
					if (pro[i][j] == -1 || pro[i][j] > pro[i][k] + pro[k][j]) 
						pro[i][j] = pro[i][k] + pro[k][j];
				}
			}
		}
		
		bool ans = 1;
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				if(pro[i][j] > adjMat[i][j] * a + b){
					ans=0;
				}
			}
		}
		if(ans)cout << "Yes\n";
		else cout << "No\n";
	}
}
