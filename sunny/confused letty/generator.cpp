//https://csacademy.com/contest/archive/task/donkey-paradox/

#include <bits/stdc++.h>

#define MAX_N 1000
#define MAX_X 100000

using namespace std;

int main(){
	int n=10;
    int m=10;
	int file=2;
    int mul=10;
    ofstream outfile;
    for(int k=0;k<=10;k++){
    	n+=abs(rand())%mul;
        m=abs(rand())%n; m++;
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

        if(k%3==0)
            mul*=10;

        if(k==10)
        	n=MAX_N,m=n/10;
        n=min(MAX_N,n);

        outfile<<n<<"\n";
        vector<int> p;
        for(int i=0;i<4;i++){
            int pos = abs(rand())%n;
            pos++;
            p.push_back(pos);
        }
        if(abs(rand()%10)>5){
            int res = abs(p[0]-p[1])+abs(p[2]-p[3]);
            if(res%2)
                p[2]++;
            outfile<<p[0]<<"\n";
            outfile<<p[3]<<"\n";
            outfile<<p[1]<<"\n";
            outfile<<p[2]<<"\n";
        }
        else{
            int res = abs(p[0]-p[2])+abs(p[1]-p[3]);
            if(res%2)
                p[2]++;
            outfile<<p[0]<<"\n";
            outfile<<p[1]<<"\n";
            outfile<<p[2]<<"\n";
            outfile<<p[3]<<"\n";   
        }
        outfile.close();
	}
	return 0;
}