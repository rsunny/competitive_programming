#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int,unordered_map<long long int, bool> >dp;
string a,b;
long long int mini;
long long int powt[20];
int num,num1;

void doit(int pos, long long int diff, int p){
	if(pos==(int)b.size()){
		if(mini!=-1)
			mini=min(mini,abs(diff));
		else
			mini=abs(diff);
		return ;
	}
	if(dp[pos][diff])
		return ;
	dp[pos][diff]=true;
	if(a[pos]=='?' and b[pos]=='?'){
		for(int i=0;i<=9;i++)
			for(int j=0;j<=9;j++)
				doit(pos+1,diff+((i-j)*powt[p]),p-1);
	}
	else if(a[pos]=='?'){
		num=b[pos]-'0';
		for(int i=0;i<=9;i++)
			doit(pos+1,diff+((i-num)*powt[p]),p-1);
	}
	else if(b[pos]=='?'){
		num=a[pos]-'0';
		for(int i=0;i<=9;i++)
			doit(pos+1,diff+((num-i)*powt[p]),p-1);	
	}
	else{
		num=a[pos]-'0';
		num1=b[pos]-'0';
		doit(pos+1,diff+((num-num1)*powt[p]),p-1);	
	}
	return ;
}

bool track(int pos, long long int diff, int p){
	if(pos==(int)b.size()){
		cout<<"track: "<<pos<<" "<<diff<<" "<<p<<" "<<mini<<"\n";
		if(mini==abs(diff))
			return 1;
		return 0;
	}
	if(dp[pos][diff])
		return 0;
	dp[pos][diff]=true;
	if(a[pos]=='?' and b[pos]=='?'){
		for(int i=0;i<=9;i++)
			for(int j=0;j<=9;j++)
				if(track(pos+1,diff+((i-j)*powt[p]),p-1)){
					cout<<pos<<" "<<i<<" "<<j<<" "<<diff+((i-j)*powt[p])<<"\n";
				cout<<a<<" "<<b<<"\n";
					a[pos]='0'+i;
					b[pos]='0'+j;
					return 1;
				}
	}
	else if(a[pos]=='?'){
		num=b[pos]-'0';
		for(int i=0;i<=9;i++)
			if(track(pos+1,diff+((i-num)*powt[p]),p-1)){
				cout<<pos<<" "<<i<<" "<<num<<" "<<diff+((i-num)*powt[p])<<"\n";
				cout<<a<<" "<<b<<"\n";
				a[pos]='0'+i;
				return 1;
			}
	}
	else if(b[pos]=='?'){
		num=a[pos]-'0';
		for(int i=0;i<=9;i++)
			if(track(pos+1,diff+((num-i)*powt[p]),p-1)){
				cout<<pos<<" "<<num<<" "<<i<<" "<<diff+((num-i)*powt[p])<<"\n";
				cout<<a<<" "<<b<<"\n";
				b[pos]='0'+i;
				return 1;
			}
	}
	else{
		num=a[pos]-'0';
		num1=b[pos]-'0';
		if(track(pos+1,diff+((num-num1)*powt[p]),p-1)){
			cout<<pos<<" "<<num<<" "<<num1<<" "<<diff+((num-num1)*powt[p])<<"\n";
				cout<<a<<" "<<b<<"\n";
			return 1;
		}
	}
	return 0;
}

int main(){
	int t;
	cin>>t;
	powt[0]=1;
	for(int i=1;i<=18;i++)
		powt[i]=powt[i-1]*10;
	for(int T=1;T<=t;T++){
		cin>>b>>a;
		dp.clear();
		mini=-1;
		doit(0,0,b.size()-1);
		dp.clear();
		track(0,0,b.size()-1);
		cout<<b<<" "<<a<<"\n";
		cout<<mini<<"\n";
	}
	return 0;
}