#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>

using namespace std;

const int maxn=100009;
const int lmt=20;

int res[maxn];
int sumd[maxn];
int mark[maxn];
int freenum[maxn];

int main(){
	for(int i=2;i*i<=lmt;i++)
		mark[i*i]=1;
	for(int i=1;i<=lmt;i++){
		for(int j=1;j*i<=lmt;j++){
			sumd[j*i]+=i;
			if(mark[i])
				freenum[i*j]=1;
		}
	}
	for(int i=1;i<=lmt;i++){
		res[i]=res[i-1];
	}
	int t,l,r;
	scanf("%d",&t);
	for(int test=1;test<=t;test++){
		scanf("%d %d",&r,&l);
		printf("%d\n",res[r]-res[l-1]);
	}
	return 0;
}
