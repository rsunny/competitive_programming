//http://codeforces.com/problemset/problem/830/B

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

#define MAX_N 1000LL

using namespace std;

int main(){
	long long int n=10;
	int file=2;
    long long int mul=10;
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
            mul*=10;

        if(k==10)
        	n=MAX_N;

        n=min(MAX_N,n);

        outfile<<n<<"\n";
        for(int i=0;i<n;i++){
            int ele = abs(rand()) % 100000;
            ele++;
            if(abs(rand()) % 10 >= 8)
                ele = 100000;
            outfile << ele << "\n";
        }

        outfile.close();
	}
	return 0;
}