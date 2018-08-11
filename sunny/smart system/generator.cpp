//https://csacademy.com/contest/virtual23/#task/library_book


#include <bits/stdc++.h>

#define MAX_N 100000

using namespace std;

int main(){
	int n=10;
    int m=10;
	int file=2;
    ofstream outfile;
    for(int k=0;k<=10;k++){
    	n+=abs(rand())%100;
        m+=abs(rand())%100;
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
        	n=1000,m=1000;
        n=min(1000,n);
        m=min(1000,m);
		vector<int> v;
        outfile<<n<<"\n";
        for(int i=1;i<=n;i++){
			int a=abs(rand())%100000;
            if(k>=8)
                a=2*i*49;
            a++;
            outfile<<a<<"\n";
            int b=abs(rand())%100000;
            b++;
            v.push_back(b);
		}
        outfile<<n<<"\n";
        for(int i=1;i<=n;i++)
            outfile<<v[i-1]<<"\n";
        v.clear();
        outfile<<m<<"\n";
        for(int i=1;i<=m;i++){
            int a=abs(rand())%100000;
            a++;
            if(k>=8)
                a=i;
            outfile<<a<<"\n";
            int b=m-i+1;
            b++;
            v.push_back(b);
        }
        outfile<<m<<"\n";
        for(int i=1;i<=m;i++)
            outfile<<v[i-1]<<"\n";
        v.clear();
        outfile.close();
	}
	return 0;
}