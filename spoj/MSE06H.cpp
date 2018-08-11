#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <stdio.h>
#include <string.h>

using namespace std;

#define ll long long

ll freq[2009];
int N,M,n;

void update(int i){
	while(i<=2000){
		freq[i] += 1;
		i+= i&-i;
	}
}

ll read(int i){
	ll sum=0;
	while(i>0){
		sum+=freq[i];
		i-= i&-i;
	}
	return sum;
}

int main(){
	int t,a,y1,y2,test=1;
	scanf("%d",&t);
	while(t--){
		memset(freq,0,sizeof freq);
		vector<pair<int,int> >Y;
		long long int strt=0;
		scanf("%d %d %d",&N,&M,&n);
		for(int i=0;i<n;i++){
			scanf("%d %d",&y1,&y2);
			Y.push_back(make_pair(y1,y2));
		}
		sort(Y.begin(), Y.end());

		for(int i=0;i<n;i++){
			a=Y[i].second;
			strt+=read(M)-read(a);
			update(a);
		}
		printf("Test case %d: %lld\n",test,strt);test++;
	}
	return 0;
}