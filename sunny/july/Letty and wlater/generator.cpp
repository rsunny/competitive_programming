//https://csacademy.com/contest/virtual8757/task/attack-and-speed/solution/

#include <bits/stdc++.h>

#define MAX_N 100000

using namespace std;

int main(){
	int n=10;
    int m=10;
    int x=10;
    int y=10;
    int s=10;
	int file=2;
    ofstream outfile;
    for(int k=0;k<=10;k++){
    	n+=abs(rand())%1000;
        m+=abs(rand())%1000;
        s+=abs(rand())%100000000;
        x+=abs(rand())%100;
        y+=abs(rand())%100;
        stringstream ss;
        string num;
        ss<<file++;
        ss>>num;
        if(num.size()==1)
            num="0"+num;
        num = "input"+num+".txt";
        char inp[(int)num.size()];
        for(int i=0;i<(int)num.size();i++)
          inp[i]=num[i];
        
        outfile.open(inp);

        if(k==10)
        	n=1e5,m=1e5,s=1e9,x=1000,y=1000;
        s=min(1000000000,s);
        n=min(100000,n);
        m=min(100000,m);
        x=min(1000,x);
        y=min(1000,y);
		outfile<<n<<"\n";
        outfile<<m<<"\n";
        outfile<<x<<"\n";
        outfile<<y<<"\n";
        outfile<<s<<"\n";
        cout<<n<<" "<<m<<" "<<x<<" "<<y<<" "<<s<<"\n";

        outfile.close();
	}
	return 0;
}