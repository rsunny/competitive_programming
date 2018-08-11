//http://codeforces.com/contest/876/problem/C

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

#define MAX_N 1000000000000000LL

using namespace std;

int main(){
	long long int n=10;
	int file=2;
    long long int mul=1000;
    ofstream outfile;
    for(int k=0;k<=10;k++){
    	n+=abs(rand())%mul;
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
            mul*=1000;

        if(k==10)
        	n=MAX_N;
        n=min(MAX_N,n);

        outfile<<n<<"\n";

        outfile.close();
	}
	return 0;
}