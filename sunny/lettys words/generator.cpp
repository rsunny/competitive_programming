//https://csacademy.com/contest/virtual37/#task/similar_words

#include <bits/stdc++.h>

#define MAX_N 10000

using namespace std;

string makes(int n){
    string s="";
    for(int i=0;i<n;i++){
        char ch='a'+abs(rand())%26;
        s+=ch;
    }
    return s;
}

int main(){
	int n=10;
    int m=10;
	int file=3;
    ofstream outfile;
    for(int k=1;k<=10;k++){
    	n+=10;
        m+=abs(rand())%1000;
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
        	n=100,m=10000;
        n=min(99,n);
        m=min(10000,m);
        string s=makes(n);
		outfile<<s<<"\n";
        outfile<<m<<"\n";
        for(int i=1;i<=m;i++){
            int as=rand()%4;
            int used=1;
            if(as==0){
                for(int j=0;j<(int)s.size();j++){
                    if(used and abs(rand())%50<25){
                        used--;
                        char ch='a'+abs(rand())%26;
                        outfile<<ch;
                    }
                    outfile<<s[j];
                }
                outfile<<"\n";
            }
            else if(as==1){
                for(int j=0;j<(int)s.size();j++){
                    if(used and abs(rand())%50<25){
                        used--;
                        continue;
                    }
                    outfile<<s[j];
                }
                outfile<<"\n";
            }
            else if(as==2)
                outfile<<s<<"\n";
            else
                outfile<<makes(s.size())<<"\n";
		}
        outfile.close();
	}
	return 0;
}