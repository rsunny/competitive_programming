#include <bits/stdc++.h>

long long int MAX_N = 1000000000000000;

using namespace std;

int main(){
    long long int h,w,h1,w1;
    h=10;
    w=19;
    h1=6;
    w1=17;
	int file=2;
    long long int mul=5;
    int mul1=2;
    ofstream outfile;
    for(int k=0;k<=10;k++){
        h+=abs(rand())%mul;h++;
        w+=abs(rand())%mul;w++;
        h1+=abs(rand())%mul1;h1++;
        w1+=abs(rand())%mul1;w1++;
        if(h1>h)
            swap(h1,h);
        if(w1>w)
            swap(w1,w);
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
        	h=MAX_N-1LL,w=MAX_N-1LL,h1=7,w1=5;
        if(k and k%3==0)
            mul*=100000,mul1*=5;
        mul=min(MAX_N,mul);
        mul1=min(100,mul1);
        h=min(MAX_N,h);
        w=min(MAX_N,w);
        h1=min(MAX_N,h1);
        w1=min(MAX_N,w1);
        // cout<<h<<" "<<w<<" "<<h1<<" "<<w1<<"\n";
        outfile<<h<<"\n";
        outfile<<w<<"\n";
        outfile<<h1<<"\n";
        outfile<<w1<<"\n";
        outfile.close();
	}
	return 0;
}