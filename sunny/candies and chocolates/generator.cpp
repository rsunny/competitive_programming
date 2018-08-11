//https://csacademy.com/contest/interview-archive/task/pokemon-evolution/

#include <bits/stdc++.h>

#define MAX_N 100000

using namespace std;

int main(){
    int n=10;
    int m=10;
    int x=10;
    int y=5;
    int file=2;
    int mul=1000;
    int mul1=1000;
    ofstream outfile;

    for(int k=0;k<=10;k++){
        n+=abs(rand())%mul;
        m+=abs(rand())%mul;
        x+=abs(rand())%mul1;
        y+=abs(rand())%mul1;

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
        
        if(k%2==0)
            mul*=100;
        if(k%3==0)
            mul1*=100;
        mul1=min(mul1,(int)1e6);
        mul=min(mul,(int)1e9);
        n=min(n,(int)1e9);
        m=min(m,(int)1e7);
        x=min(x,(int)1e7);
        y=min(y,(int)1e6);
        outfile<<n<<"\n";
        outfile<<m<<"\n";
        outfile<<x<<"\n";
        outfile<<y<<"\n";
        //cout<<n<<" "<<m<<" "<<x<<" "<<y<<"\n";
        outfile.close();
	}
	return 0;
}