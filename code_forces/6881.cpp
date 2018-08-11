#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <sstream>
#include <algorithm>

using namespace std;

int main(){
	// for(int i=1;i<=100009;i++){
	// 	stringstream ss;
	// 	string s;
	// 	ss<<i;
	// 	ss>>s;
	// 	int f=0;
	// 	int n=s.size();
	// 	if(n%2==1)
	// 		continue;
	// 	for(int i=0;i<n/2;i++)
	// 		if(s[i]!=s[n-i-1]){
	// 			f=1;
	// 			//cout<<s[i]<<" "<<s[n-i]<<",";
	// 		}
	// 	if(!f)
	// 		cout<<i<<"\n";
	// }
	string s;
	cin>>s;
	cout<<s;
	reverse(s.begin(),s.end());
	cout<<s<<"\n";
	return 0;
}
