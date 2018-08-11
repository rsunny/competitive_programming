#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <cassert>

using namespace std;

int main(){
	int n,l,r,t,c;
	int file=3;
    ofstream outfile;
    for(int k=0;k<=8;k++){
        stringstream ss;
        string num;
        ss<<file++;
        ss>>num;
        if(num.size()==1)
            num="0"+num;
        outfile.open("input"+num+".txt");
        if(k%2==0)
            t+=50;
        else
            t*=4;
        if(k<=4)
            c=abs(rand()%1000)+1;
        else
            c=abs(rand()%1000000)+1;
        t=min(t,10000);
        cout<<k<<" "<<t<<"\n";
        outfile<<t<<"\n";
        int temp=t;
        while(temp--){
            n=abs(rand()%c)+1;
            l=abs(rand()%n)+1;
            r=abs(rand()%n)+1;
            outfile<<n<<" "<<l<<" "<<r<<"\n";
        }
        outfile.close();
	}
	return 0;
}