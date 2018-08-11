#include <bits/stdc++.h>

#define MAX_N 100000

using namespace std;

int main(){
	int n=0;
	int file=3;
    int m = 0;
    ofstream outfile;
    for(int k=1;k<=10;k++){
    	n+=abs(rand())%10000;
        n+=abs(rand())%10000;
        m+=abs(rand())%100000000;
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
        if(k>=7)
        	n=100000,m=1000000000;
        n=min(100000,n);
        m=min(1000000000,m);
		outfile<<n<<"\n";
        if(k<=6){
            int ele = 1;
            for(int i=1;i<=n;i++){
                if(k>4)
                    ele+=abs(rand())%100;
                else
                    ele+=abs(rand())%10000;
                ele++;
                outfile<<ele<<"\n";
            }
        }
        else
            for(int i=1;i<=n;i++){
                outfile<<i<<"\n";
            }
        outfile<<m<<"\n";
        outfile.close();
	}
	return 0;
}