#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <vector>

using namespace std;

long long int bit[2009][2009];
int n,m;

void update(int i,int j,long long int val){
	if(i==0 or j==0)
		return ;
	int temp;
	while(i<=n){
		temp=j;
		while(temp<=m){
			bit[i][temp] += val;
			temp+=temp&-temp;
		}
		i+= i&-i;
	}
	return;
}

long long int read(int i,int j){
	long long int sum=0;
	int temp;
	while(i>0){
       	temp=j;
       	while(temp>0){
			sum+=bit[i][temp];
			temp-=temp&-temp;
		}
		i-= i&-i;
	}
	return sum;
}

vector<int> x[2009];
vector<int> y[2009];
vector<long long int> z[2009];
long long int res[2009];
vector<char> ch;
vector<int> x1,x2,y11,y2;
vector<int> swt[2009];
vector<int> qu;

int main(){
	int k,c;
	int i1,i2,j1,j2;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=k;i++){
		int tot;
		scanf("%d",&tot);
		for(int j=0;j<tot;j++){
			scanf("%d %d %d",&i1,&j1,&c);
			x[i].push_back(i1);
			y[i].push_back(j1);
			z[i].push_back((long long int)c);
		}
	}
	int q;
	scanf("%d",&q);
	char s[10];
	for(int i=0;i<q;i++){
		getchar();
		scanf("%s",s);
		if(s[0]=='S'){
			scanf("%d",&i1);
			swt[i1].push_back(i);
		}
		else{
			scanf("%d %d %d %d",&i1,&j1,&i2,&j2);
			qu.push_back(i);
			x1.push_back(i1);
			y11.push_back(j1);
			x2.push_back(i2);
			y2.push_back(j2);
		}
	}

	for(int i=1;i<=k;i++){
		for(int j=0;j<(int)x[i].size();j++){
			update(x[i][j],y[i][j],z[i][j]);
		}
		int tog=1;
		int l=0;
		for(int j=0;j<qu.size();){
			if(l<swt[i].size() and swt[i][l]<qu[j]){
				tog^=1;
				l++;
			}
			else{
				if(tog)
					res[j]+=read(x1[j]-1,y11[j]-1)+read(x2[j],y2[j])-read(x1[j]-1,y2[j])-read(x2[j],y11[j]-1);
				j++;
			}
		}

		for(int j=0;j<(int)x[i].size();j++)
			update(x[i][j],y[i][j],-1LL*z[i][j]);
	}

	for(int i=0;i<qu.size();i++)
		cout<<res[i]<<"\n";

	return 0;
}
