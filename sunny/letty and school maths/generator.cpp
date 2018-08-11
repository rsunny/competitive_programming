//https://csacademy.com/contest/archive/task/max-intersection-partition/

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
        m=min(n/10,m);

        set<pair<int,int> > ed;
        while((int)ed.size()<n){
            int a = abs(rand())%MAX_X;a++;
            int b = abs(rand())%MAX_X;b++;
            if(a>b)
                swap(a,b);
            ed.insert({a,b});
        }
        
        outfile<<n<<"\n";
        for(set<pair<int,int> >::iterator it=ed.begin();it!=ed.end();it++)
            outfile<<it->first<<"\n";
        
        outfile<<n<<"\n";
        for(set<pair<int,int> >::iterator it=ed.begin();it!=ed.end();it++)
            outfile<<it->second<<"\n";
        
        outfile<<m<<"\n";

        outfile.close();
	}
	return 0;
}