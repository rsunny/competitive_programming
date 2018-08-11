#include <iostream>
#include <stack>
#include <cstdio>
#include <unordered_map>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

long long int soil[1000100];
int t,n,h,I,H;
long long int cnt,res;

int main(){
    scanf("%d",&t);
    while(t--){
      scanf("%d %d",&n,&h);
      for(int i=0;i<n;i++){
        scanf("%d %d",&I,&H);
        soil[I+1]-=1LL;
        soil[H+2]+=1LL;
      }
      cnt=0;
      res=1e15;
      for(int i=1;i<=n;i++){
        soil[i]+=soil[i-1];
        cnt+=n+soil[i]; 
        if(i==h){
          res=cnt;
        }
        else if(i>h){
          cnt-=n+soil[i-h];
          res=min(res,cnt);
        }
      }
      printf("%lld\n",res);
      for(int i=1;i<=n;i++)
        soil[i]=0;
    }
    return 0;
}
