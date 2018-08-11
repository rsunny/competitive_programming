#include <iostream>
#include <vector>
#include <map>

using namespace std;

int pf[109][30];
int m[109];
vector<int> pr;
long long int dp[1<<26][26][2];
long long int freq[26];

int main(){
	for(int i=2;i<=102;i++){
		int cnt=0;
		for(int j=2;j<=i-1;j++)
			if(i%j==0)
				cnt++;
		if(!cnt)
			pr.push_back(i);
		for(int j=0;j<(int)pr.size();j++)
			if(i%pr[j]==0)
				pf[i][j]=1;
		m[i]=pr.size();
	}

	int mask,flag;
	dp[0][0][0]=1;
	for(int i=2;i<=100;i++){
		for(int j=0;j<=(1<<m[i]);j++){
			for(int k=0;k<26;k++){
				freq[k]=0;
				dp[j][k][1]+=dp[j][k][0];
				mask=j;
				flag=0;
				for(int l=0;l<m[i];l++)
					if(mask&(1<<l) and pf[i][l])
						flag=1;
					else
						mask|=pf[i][l]?(1<<l):0;
				if(flag)
					continue;
				dp[mask][k+1][1]=dp[j][k][0];
			}
		}
		for(int j=0;j<(1<<m[i]);j++){
			for(int k=0;k<26;k++){
				dp[j][k][0]=dp[j][k][1];
				dp[j][k][1]=0;
				freq[k]+=dp[j][k][0];
			}
		}
		cout<<i<<" : ";
		for(int j=0;j<26;j++)
			cout<<freq[j]<<" ";
		cout<<"\n";
	}

	return 0;
}