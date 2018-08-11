// http://codeforces.com/contest/864/problem/C

#include <bits/stdc++.h>

#define MAX_N 1000000

using namespace std;

int main(){
    int x=10;
    int y;
    int z;
    int file=2;
    ofstream outfile;

    for(int k=0;k<=10;k++){
        x+=abs(rand())%50000;
        y=abs(rand())%x;
        z=2*(x-y);
        if(rand()%5 > 2)
            z+=abs(rand())%(2*y);
        else
            z+=(2*y);
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

        x=min(x,(int)5e5);
        y=min(y,x);
        z=min(z,(int)1e7);

        outfile<<x<<"\n";
        outfile<<y<<"\n";
        outfile<<z<<"\n";
        cout<<x<<" "<<y<<" "<<z<<"\n";
        outfile.close();
	}
	return 0;
}