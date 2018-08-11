#include <iostream>
#include <vector>
#include <map>
#include <string.h>
#include <stdio.h>

using namespace std;


int main(){
	int n;
	for(int i=2;i<=50;i++){
		map<int,bool> vis;
		n=i;
		n*=(i-1);n/=2;
		int a=1;
		while(a<=1000){
			for(int d=1;(i*a)+(n*d)<=1000;d++)
				vis[(i*a)+(n*d)]=1;
			a++;
		}
		map<int,bool> :: iterator it;
		cout<<i<<" ----- \n";
		int last=0;
		for(it=vis.begin();it!=vis.end();it++)
			cout<<(*it).first<<" "<<(*it).first-last<<" | ",last=(*it).first;
		cout<<vis.size()<<"\n";
	}
	return 0;
}
