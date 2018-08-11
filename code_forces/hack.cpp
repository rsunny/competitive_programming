#include <iostream>

using namespace std;

int main(){
	int n;
	n=100000;
	printf("%d\n",n);
	int x1,x2;
	x1=-1000000;
	x2=1000000;
	printf("%d %d\n",x1,x2);
	int k,b;
	for(int i=0;i<n;i++){
		k=0,b=i+10;
		if(i==10001)
			k=1, b=0;
		if(i==10002)
			k=-1,b=3;
		printf("%d %d\n",k,b);
	}
	return 0;
}