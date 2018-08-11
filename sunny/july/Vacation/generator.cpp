//https://csacademy.com/contest/archive/task/unfair_game/statement/

#include <bits/stdc++.h>

#define MAX_N 100000

using namespace std;

int main(){
	int n=10;
	int file=2;
    ofstream outfile;
    for(int k=0;k<=10;k++){
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
        cout<<n<<"\n";
        for(int i=0;i<n;i++){
            int ele=abs(rand()%100000000);
            if(abs(rand()%10)>7 and k!=8)
                ele*=-1;
            outfile<<ele<<"\n";
        }
        outfile.close();
	}
	return 0;
}