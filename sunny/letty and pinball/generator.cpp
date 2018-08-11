//https://csacademy.com/contest/archive/task/pirouettes/

#include <bits/stdc++.h>

#define MAX_N 100

using namespace std;

int main(){
	int n=10;
    int m=5;
    int q=15;
	int file=2;
    int mul=5;
    ofstream outfile;
    for(int k=0;k<=10;k++){
    	n+=abs(rand())%mul;
        m+=abs(rand())%(n+1);
        q+=abs(rand())%((2*n)+1);
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

        if(k==10)
        	n=100,m=70,q=150;
        if(k%3==0)
            mul*=2;
        mul=min(100,mul);
        n=min(100,n);
        m=min(100,m);
        q=min(200,q);
        cout<<q<<" "<<n<<" "<<m<<"\n";
        outfile<<q<<"\n";
		outfile<<n<<"\n";
        outfile<<m<<"\n";
        outfile.close();
	}
	return 0;
}