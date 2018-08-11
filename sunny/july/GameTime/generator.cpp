//https://csacademy.com/contest/archive/task/counting-quests/statement/

#include <bits/stdc++.h>

#define MAX_N 100000

using namespace std;

int main(){
	int n=10;
	int file=2;
    ofstream outfile;
    for(int k=0;k<=10;k++){
    	n+=abs(rand())%15;
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
        	n=100;
        n=min(100,n);
		outfile<<n<<"\n";
        outfile.close();
	}
	return 0;
}