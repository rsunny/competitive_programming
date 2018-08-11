#include <iostream>

using namespace std;

int week[10];
int mnth[15];

int main(){
	week[1]= 52;
	week[2]= 52;
	week[3]= 52;
	week[4]= 52;
	week[5]= 53;
	week[6]= 53;
	week[7]= 52;

	mnth[1]= 31;
	mnth[2]= 29;
	mnth[3]= 31;
	mnth[4]= 30;
	mnth[5]= 31;
	mnth[6]= 30;
	mnth[7]= 31;
	mnth[8]= 31;
	mnth[9]= 30;
	mnth[10]= 31;
	mnth[11]= 30;
	mnth[12]= 31;

	int i;
	string s1,s2;

	cin>>i>>s1>>s2;
	if(s2=="week")
		cout<<week[i]<<"\n";
	else {
		int cnt=0;
		for(int j=1;j<=12;j++)
			if(i<=mnth[j])
				cnt++;
		cout<<cnt<<"\n";
	}
	return 0;
}