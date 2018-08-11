//http://codeforces.com/gym/100247/problem/H

#include <bits/stdc++.h>

#define MAX_N 100000

using namespace std;

int main(){
	int n=10;
	int file=3;
    ofstream outfile;
    for(int k=1;k<=10;k++){
    	n+=abs(rand())%1000;
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
        	n=10000;
        n=min(10000,n);
        outfile<<n<<"\n";
        string s;
        for(int i=0;i<n;i++){
            for(int j=0;j<5;j++)
                outfile<<(char)('a'+(abs(rand()%26)));
            outfile<<"\n";
        }
        outfile.close();
	}
	return 0;
}