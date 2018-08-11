#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>

using namespace std;

#define MAX_N 100010
#define CHILDREN int tm = (tl+tr)>>1; \
					int cl = node<<1; \
					int cr = cl|1

struct segNode{
	int val,start,cnt;
};

int arr[MAX_N];
segNode array[MAX_N];
int tree[4*MAX_N];
string s;

void build(int node,int tl,int tr){
	if(tl==tr){
		tree[node]=array[tl].cnt;
		return;
	}
	CHILDREN;
	build(cl,tl,tm);
	build(cr,tm+1,tr);
	tree[node]=max(tree[cl],tree[cr]);
}

int query(int node,int tl,int tr,int l,int r){
	if(r<l)
		return 0;
	if(tl==l and tr==r)
	{
		return tree[node];
	}
	CHILDREN;
	return max(query(cl,tl,tm,l,min(r,tm)),query(cr,tm+1,tr,max(l,tm+1),r));
}

int main(){
	int t;
	scanf("%d",&t);
	for(int test=1;test<=t;test++){
		printf("Case %d: ",test);
		cin>>s;
		
		
	}
	return 0;
}
