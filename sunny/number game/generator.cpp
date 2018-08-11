//https://csacademy.com/contest/archive/#task/lightbulbs

#include <bits/stdc++.h>

#define MAX_N 100000

using namespace std;

string convert(long long int n){
    string s="";
    while(n){
        if(n%2LL)
            s="1"+s;
        else
            s="0"+s;
        n/=2LL;
    }
    return s;
}


int main(){
	long long int n=11;
    cout<<n<<" "<<convert(n)<<"\n";
    n=abs(rand()%1000000000000);
	int file=3;
    ofstream outfile;
    for(int k=1;k<=10;k++){
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
        int x=abs(rand()%50);
        long long int a=1ll<<x;
        n|=a;
        outfile<<n<<"\n";
        cout<<n<<" "<<convert(n)<<"\n";
        outfile.close();
	}
	return 0;
}