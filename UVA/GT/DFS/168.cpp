#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;

#define f first
#define s second
#define mp make_pair
#define pb push_back

int a,b,c,d,e;
string s;
char x;
vector<int> adjList[30];
int light[30];

int main(){
	//freopen("input.txt","r",stdin);
	while (1){
		for (int i = 0; i < 27; ++i)adjList[i].clear();
		cin >> s;		
		if (s=="#")return 0;
		for (int i = 0; i < s.size(); ++i){
			if(s[i] == '.')break;
			int cur = s[i] - 'A';
			i++;
			if (s[i] == ';' || s[i]  == '.')continue;
			i++;
			while (s[i]!=';' && s[i] != '.'){
				adjList[cur].pb(s[i] - 'A');
				i++;
			}
		}	
		
		/*
		for (int i = 0; i < 10; ++i){
			cout << i << ':';
			for (auto j : adjList[i])cout << ' ' << j;
			cout << '\n';
		}
		*/
		//for (int i = 0; i < 27; ++i)sort(adjList[i].begin(),adjList[i].end());
		cin >> x;a=x-'A';//Min
		cin >> x;b=x-'A';//The
		cin>>c;
		d=0;
		memset(light,0,sizeof(light));
		while(1){
			e=a;
			d++;
			if(d%c==0){
				light[e]=1;
			}
			for (auto i : adjList[a]){
				if (!light[i] && i!=b){
					a = i;
					break;
				}
			}
			b=e;
			if (a==b){
				char t = b+'A';
				cout << '/' << t << '\n';
				break;
			}
			if(d%c==0){
				char t = e+'A';
				cout << t << ' ';
			}
		}
	}
}
