//http://codeforces.com/gym/100247/problem/H

#include <bits/stdc++.h>

#define MAX_N 100000

using namespace std;

int main(){
	int n=10;
	int file=3;
    ofstream outfile;
    for(int k=1;k<=10;k++){
    	n+=abs(rand())%10000;
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
        	n=100000;
        n=min(100000,n);
        outfile<<n<<"\n";
        string s;
        for(int i=0;i<n;i++){
            if(abs(rand()%10)>3)
                s+="0";
            else
                s+="1";
        }
        outfile<<s<<"\n";
        for(int i=0;i<n;i++){
            if(abs(rand()%10)>3)
                outfile<<"0";
            else
                outfile<<s[i];
        }
        outfile<<"\n";
        outfile.close();
	}
	return 0;
}