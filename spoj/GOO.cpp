#include <iostream>
#include <stdio.h>

using namespace std;

int getint(){
   int c = 'a';
   while (!(c >= '0' && c <= '9') && c != '-')
           c=getchar_unlocked();
   int c2;
   if (c != '-')
     c2 = c;
   else
     c2 = '0';
   int res = 0;
   while((c2 >= '0' && c2 <= '9')){
     res = (res << 3) + (res << 1) + (c2 - '0');
         c2=getchar_unlocked();
   }
   return res * (c == '-' ? -1 : 1);
}

int main(){
    int t;
    t=getint();
    long long int inp,ans1,ans2;
    while(t--){
      inp=getint();
      ans1=(1LL<<(inp-1));
      ans2=ans1;
      for(int i=1;i<inp;i++)
        ans2+=(ans1/2LL);
      printf("%lld %lld\n",ans1,ans2);
    }
    return 0;
}
