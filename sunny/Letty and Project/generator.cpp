#include <bits/stdc++.h>

#define MAX_N 100000

using namespace std;

int main(){
	int n=0;
    int m=0;
	int file=3;  
    ofstream outfile;
    for(int k=1;k<=10;k++){
        bool no=true; 
    	n+=abs(rand())%10000;
        n+=abs(rand())%10000;
        m++;
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
        	n=100000,m=10,no=false;
        n=min(100000,n);
        m=min(10,m);
        outfile<<m<<"\n";
		outfile<<n<<"\n";
		for(int i=1;i<=n;i++){
            for(int j=0;j<m;j++){
                int pre=abs(rand())%50;
                if(pre<25 and abs(rand())%10>7 and no)
                    outfile<<"N";
                else outfile<<"Y";
            }
            if(abs(rand())%10>=6 and i>n/3)
                no=false;
            outfile<<"\n";
		}
        outfile.close();
	}
	return 0;
}