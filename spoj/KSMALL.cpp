#include <iostream>
#include <algorithm>

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

unsigned a,b,mod;
int ele[5000009];
int k;

void randomize(){
	for( int i=1 ; i<=5000000 ; i++ ){
		a = 31014 * (a & 65535) + (a >> 16);
		b = 17508 * (b & 65535) + (b >> 16);
		ele[i] = ((a << 16) + b);
		if(ele[i]>=mod)
			 ele[i]%= mod;
	}
	return ;
}

int main(){
	a=getint();	b=getint();	mod=getint();	k=getint();
	randomize();
	nth_element(&ele[1],&ele[k],&ele[5000000]);
	printf("%d\n",ele[k]);
    return 0;
}
