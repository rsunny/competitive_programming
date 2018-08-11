#include <iostream>
#include <stack>
#include <cstdio>
#include <unordered_map>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int t,a,b,res;

int main(){
    scanf("%d",&t);
    while(t--){
      scanf("%d %d",&a,&b);
      res=0;
      while(a&(a-1))
        res++,a/=2;
      while(a!=b)
        if(a<b)a*=2,res++;
        else if(a>b)a/=2,res++;
      cout<<res<<"\n";
    }
    return 0;
}
