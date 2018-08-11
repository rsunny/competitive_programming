//https://csacademy.com/contest/virtual9/#task/word_ordering

#include <bits/stdc++.h>

#define MAX_N 100000

using namespace std;

vector<int> v[5];

void pre(){
    int k=0;
    for(int i=0;i<4;i++)
        for(int j=0;j<5;j++)
            v[i].push_back(k),k++;
    for(;k<26;k++)
        v[4].push_back(k);
    return ;
} 

int main(){
	int n=10;
	int file=3;
    ofstream outfile;
    pre();
    for(int k=1;k<=10;k++){
    	n+=abs(rand())%1000;
        n+=abs(rand())%1000;
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
        	n=20000;
        n=min(20000,n);
        outfile<<n<<"\n";
        for(int i=1;i<=n;i++){
            for(int j=0;j<100;j++){
    			int a=abs(rand())%26;
                char ch='a'+a;
                outfile<<ch;
            }
            outfile<<"\n";
		}
        for(int i=0;i<5;i++){
            int k=0;
            do{
                k++;
            }while(k<10 and next_permutation(v[i].begin(),v[i].end()));
            for(int j=0;j<(int)v[i].size();j++){
                char ch='a'+v[i][j];
                outfile<<ch;
            }
        }
        outfile<<"\n";
        outfile.close();
	}
	return 0;
}