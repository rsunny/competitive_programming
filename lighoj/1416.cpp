#include <iostream>
#include <string.h>

using namespace std;

const int mod = 1000000007;

int dp[109][109][309];
int cnt[109][109][30];
string a,b,c;
string s;
int max_len;

int doit(int pos_a,int pos_b,int pos_c){
	if(pos_a==a.size() and pos_b==b.size()){
		dp[pos_a][pos_b][pos_c]=0;
		return 0;
	}
	if(pos_c==c.size())
		return 1000;
	
	if(dp[pos_a][pos_b][pos_c]!=-1)
		return dp[pos_a][pos_b][pos_c];
	
	int res=1000;

	for(int i=pos_c;i<c.size() and pos_a<a.size();i++)
		if(c[i]==a[pos_a]){
			res=min(res,doit(pos_a+1,pos_b,i+1)+1);
			if(a[pos_a]==b[pos_b])
				res=min(res,doit(pos_a+1,pos_b+1,i+1)+1);
			break;
		}

	for(int i=pos_c;i<c.size() and pos_b<b.size();i++)
		if(c[i]==b[pos_b]){
			res=min(res,doit(pos_a,pos_b+1,i+1)+1);
			break;
		}

	dp[pos_a][pos_b][pos_c]=res;
	return res;
}

void traverse(int pos_a,int pos_b,int pos_c){
	if(pos_a==a.size() and pos_b==b.size())
		return ;

	int aa=-1,bb,cc;
	char ch='z';

	int len=dp[pos_a][pos_b][pos_c];

	for(int i=pos_c;i<c.size() and pos_a<a.size();i++)
		if(c[i]==a[pos_a]){
			if(dp[pos_a+1][pos_b][i+1]+1==len)
				aa=pos_a+1,bb=pos_b,cc=i+1,ch=a[pos_a];
			if(a[pos_a]==b[pos_b] and dp[pos_a+1][pos_b+1][i+1]+1==len){
				s+=b[pos_b];
				traverse(pos_a+1,pos_b+1,i+1);
				return;
			}
			break;
		}

	for(int i=pos_c;i<c.size() and pos_b<b.size();i++)
		if(c[i]==b[pos_b]){
			if(dp[pos_a][pos_b+1][i+1]+1==len and b[pos_b]<=ch){
				s+=b[pos_b];
				traverse(pos_a,pos_b+1,i+1);
				return ;
			}
			break;
		}
	if(aa!=-1){
		s+=a[pos_a];
		traverse(aa,bb,cc);
	}
	return ;
}

int number(int pos_a,int pos_b,int pos_c,int aorb){
	if(pos_a==a.size() and pos_b==b.size()){
		return 1;
	}
	if(pos_c==c.size())
		return 0;

	if(cnt[pos_a][pos_b][aorb]!=-1)
		return cnt[pos_a][pos_b][aorb];

	int res=0;
	int len=dp[pos_a][pos_b][pos_c];
	int flag=1;
	for(int i=pos_c;i<c.size() and pos_a<a.size();i++)
		if(c[i]==a[pos_a]){
			if(a[pos_a]==b[pos_b] and dp[pos_a+1][pos_b+1][i+1]+1==len){
				res+=number(pos_a+1,pos_b+1,i+1,a[pos_a]-'a'+1);
				res%=mod;
				flag=0;
			}
			if(dp[pos_a+1][pos_b][i+1]+1==len and flag){
				res+=number(pos_a+1,pos_b,i+1,a[pos_a]-'a'+1);
				res%=mod;
			}
			break;
		}

	for(int i=pos_c;i<c.size() and pos_b<b.size();i++)
		if(c[i]==b[pos_b]){
			if(dp[pos_a][pos_b+1][i+1]+1==len and flag){
				res+=number(pos_a,pos_b+1,i+1,b[pos_b]-'a'+1);
				res%=mod;
			}
			break;
		}
	cnt[pos_a][pos_b][aorb]=res;
	return res;
}


int main(){
	int test;
	cin>>test;
	for(int t=1;t<=test;t++){
		memset(dp,-1,sizeof dp);
		memset(cnt,-1,sizeof cnt);
		cin>>a>>b>>c;
		max_len=doit(0,0,0);	
		if(max_len==1000){
			cout<<"Case "<<t<<": "<<"0 \nNOT FOUND\n";
			continue;
		}
		cout<<max_len<<"\n";
		s="";
		traverse(0,0,0);
		cout<<"Case "<<t<<": "<<number(0,0,0,0)<<" \n"<<s<<"\n";
	}
	return 0;
}