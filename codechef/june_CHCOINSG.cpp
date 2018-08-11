#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <cmath>

using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	for(int test=1;test<=t;test++){
		int n;
		scanf("%d",&n);
		if(n%6)
			cout<<"Chef\n";
		else
			cout<<"Misha\n";
	}
	return 0;
}
