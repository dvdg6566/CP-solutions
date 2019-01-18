#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,N,M,R;

int main(){
  cin>>T;
  for (int i=0;i<T;++i){
    cin>>M>>N;
    if (M%2==0){
      R = N/M;
      N%=M;
      if(N==0){N+=M;--R;}
      if(N%2==1){
        cout<<N/2+1<<' ' << R<<'\n';
      }else cout<<M+1-N/2<<' '<<R<<'\n';
    }else{
      R=(N/(2*M));
      N%=(2*M);
      if(N==0){N+=M*2;--R;}
      R *= 2;
      if (N>M){
        N-=M;
        ++R;
        if(N%2==0){
          cout<<(N+1)/2<<' ' << R<<'\n';
        }else cout<<M+1-(N+1)/2<<' '<<R<<'\n';
      }else{
        if(N%2==1){
          cout<<N/2+1<<' ' << R<<'\n';
        }else cout<<M+1-N/2<<' '<<R<<'\n';
      }
    }
  }  
}