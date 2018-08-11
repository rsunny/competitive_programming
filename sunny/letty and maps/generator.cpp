#include <bits/stdc++.h>

#define MAX_N 1000

using namespace std;

int main(){
	int n=30;
	int file=2;
    ofstream outfile;
    for(int k=0;k<=10;k++){
    	n+=abs(rand())%150;
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
        	n=MAX_N;
        n=min(MAX_N,n);
		outfile<<n<<"\n";
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				int e = abs(rand())%10;
				if(e>=5)
					outfile<<".";
				else
					outfile<<"#";
			}
			outfile<<"\n";
		}
        outfile.close();
	}
	return 0;
}