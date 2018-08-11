//https://csacademy.com/contest/archive/#task/recursive_shuffle/

#include <bits/stdc++.h>

#define MAX_N 10000000

using namespace std;

int main(){
	int n=10;
    int x=10;
	int file=2;
    int mul=1000;
    ofstream outfile;
    for(int k=0;k<=10;k++){
        n+=abs(rand())%mul;
        x+=abs(rand())%mul;
        if(x>n)
            swap(x,n);
        stringstream ss;
        string num;
        ss<<file++;
        ss>>num;
        if(num.size()==1)
            num="0"+num;
        num = "input"+num+".txt";
        char inp[100];
        for(int i=0;i<(int)num.size();i++)
          inp[i]=num[i];
        
        outfile.open(inp);

        if(k%3==0)
            mul*=10;
        if(k==10)
        	n=MAX_N,x=1000000;
        n=min(MAX_N,n);
		outfile<<n<<"\n";
        outfile<<x<<"\n";
        cout<<n<<" "<<x<<"\n";
        outfile.close();
	}
	return 0;
}