#include<bits/stdc++.h>
using namespace std;
multiset<ll> small, big;
#define lb lower_bound
#define ub upper_bound
int L;

int query(){
  if(!L)return -1;
  // cout << small.size() << ' ' << big.size() << '\n';
  assert(small.size() + big.size() == L);
  assert(small.size() >= big.size());
  assert(small.size() - big.size() <= 1);
  if (L%2 == 0){
    assert(*(--small.end()) >= 0);
    assert(*b.ig.begin() >= 0);
    return (*(--small.end()) + *big.begin()) / 2;
  }
   assert(*(--small.end()) >= 0);

  return *(--small.end());
}

void balance(){
  if(!big.size())return;
   while (*(--small.end()) > *big.begin()){
      small.insert(*big.begin());
      big.insert(*(--small.end()));
      big.erase(big.begin());
      small.erase(--small.end());
    }
}

int init (int *arr, int length){
  sort(arr,arr+length);
  L = length;
  int M = length/2;
  if (length%2)++M;
  for (int i=0;i<M;++i)small.insert(arr[i]);
  for (int i=M;i<length;++i)big.insert(arr[i]);
  return query();
}

int add_number(int x){
  // cout << "ADD\n";
  small.insert(x);
  ++L;
  if (small.size() - big.size() > 1){
    big.insert(*(--small.end()));
    small.erase(--small.end());
  }
  balance(); 
  return query();
}

int remove_number(int x){
  // cout << "REMOVE\n";
  --L;
  if (big.lb(x) != big.ub(x)){
    big.erase(big.find(x));
  }else small.erase(small.find(x));
  // cout << small.size() << ' ' << big.size() << '\n';
  if (small.size()> big.size() + 1){
    // cout << "Scene 1\n";
    big.insert(*(--small.end()));
    small.erase(--small.end());
  }else if (small.size() < big.size()){
    // cout << "Scene 2\n";
    small.insert(*big.begin());
    big.erase(big.begin());
  }
  // cout << small.size() << ' ' << big.size() << '\n';
  return query();
}

int change_number(int old, int newx){
  remove_number(old);
  return add_number(newx);
}

int main() {
  freopen("input.txt","r",stdin);
    char c[8];
    int l,a,b;
    int*arr;
    bool inited=false;
    while(scanf(" %s",c)!=EOF){
        if(strcmp(c,"init")==0){
            if(inited){
                fprintf(stderr,"Cannot call init() more than once!\n");
                return 1;
            }
            inited=true;
            scanf("%d",&l);
            arr=new int[l];
            for(int i=0;i<l;++i){
                scanf("%d",arr+i);
            }
            printf("%d\n",init(arr,l));
        }
        else if(strcmp(c,"add")==0){
            if(!inited){
                fprintf(stderr,"Cannot call add() before calling init()!\n");
                return 1;
            }
            scanf("%d",&a);
            printf("%d\n",add_number(a));
        }
        else if(strcmp(c,"remove")==0){
            if(!inited){
                fprintf(stderr,"Cannot call remove() before calling init()!\n");
                return 1;
            }
            scanf("%d",&a);
            printf("%d\n",remove_number(a));
        }
        else if(strcmp(c,"change")==0){
            if(!inited){
                fprintf(stderr,"Cannot call change() before calling init()!\n");
                return 1;
            }
            scanf("%d%d",&a,&b);
            printf("%d\n",change_number(a,b));
        }
        else{
            fprintf(stderr,"Unknown command \"%s\".\n",c);
            return 1;
        }
    }
    return 0;
}


