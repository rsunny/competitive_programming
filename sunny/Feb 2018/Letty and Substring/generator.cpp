//http://codeforces.com/problemset/problem/519/D

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

#define MAX_N 200000LL

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
            mul*=100;

        if(k==10)
        	n=MAX_N;

        n=min(MAX_N,n);

        outfile<<26<<"\n";

        for(int i=0;i<26;i++){
            int ele = rand() % 11;
            if(rand() % 10 >= 5)
                ele *= -1;
            outfile<<ele<<"\n";
        }
        string s;
        int alp = abs(rand())%26;
        for(int i=0;i<n;i++){
            int ele = abs(rand()) % 26;
            if(abs(rand()) % 10 >= 5)
                ele = alp;
            s += ('a' + ele); 
        }
        outfile<<s<<"\n";
        outfile.close();
	}
	return 0;
}