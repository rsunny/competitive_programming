#include <iostream>
#include <stack>
#include <string.h>
#include <string>

using namespace std;

bool vis[1005];
int pos[1005];

bool isop(char ch){
	return (ch=='+' or ch=='-' or ch=='*' or ch=='/' or ch=='^');
}

string onp(string s){
	stack<int> st;
	string res,op;
	int n=s.size();
	while(1){
		res="",op="";
		for(int i=0;i<n;i++){
			if(s[i]=='(')
				st.push(i);
			if(s[i]==')'){
				int tp=st.top();st.pop();
				for(int j=0;j<tp;j++)
					res+=s[j];
				res+=" ";
				for(int j=tp+1;j<i;j++){
					if(isop(s[j]) and vis[j]==false)
						vis[j]=true,op+=s[j];
					else 
						res+=s[j];
				}
				res+=op;
				res+=" ";
				for(int j=tp+1;j<i;j++)
						vis[j]=isop(res[j]);
				for(int j=i+1;j<n;j++)
					res+=s[j];
				break;
			}
		}
		if(st.size()==0)
			return res;
		while(st.size())
			st.pop();
		s=res;
	}	
	return res;
}

int main(){
	int t;
	string s,res;
	cin>>t;
	while(t--){
		cin>>s;
		memset(vis, false, sizeof vis);
		res=onp(s);
		for(int i=0;i<(int)res.size();i++)
			if(res[i]!=' ')
				printf("%c",res[i]);
		printf("\n");
	}
	return 0;
}