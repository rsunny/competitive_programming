//https://csacademy.com/contest/archive/#task/hallway/

#include <bits/stdc++.h>

#define MAX_N 100000

using namespace std;

int main(){
	int n=10;
    int m=10;
    int q=5;
	int file=2;
    int mul=50;
    ofstream outfile;
    for(int k=0;k<=10;k++){
    	n+=abs(rand())%mul;
        m+=abs(rand())%mul;
        q+=abs(rand())%mul;
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
        	n=5000,m=5000,q=1000;
        if(k%3==0)
            mul*=10;
        mul=min(5000,mul);
        n=min(5000,n);
        m=min(5000,m);
        q=min(1000,q);
		outfile<<n<<"\n";
        outfile<<m<<"\n";
        set<pair<int,int> > cor;
        for(int i=0;i<q;i++){
            int x=abs(rand()%n-1)+1;
            int y=abs(rand()%m-1)+1;
            cor.insert(make_pair(x,y));
        }
        outfile<<cor.size()<<"\n";
        set<pair<int,int> > :: iterator it;
        for(it=cor.begin();it!=cor.end();it++)
            outfile<<it->first<<"\n";
        outfile<<cor.size()<<"\n";
        for(it=cor.begin();it!=cor.end();it++)
            outfile<<it->second<<"\n";
        outfile.close();
	}
	return 0;
}