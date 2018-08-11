#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <utility>
#include <fstream>
#include <sstream>
#include <map>
using namespace std;

int main(){
    int file=1;
    ofstream outfile;
    for(int i=1;i<=10;i++){
        stringstream ss;
        string num;
        ss<<file++;
        ss>>num;
        if(num.size()==1)
            num="0"+num;
        cout<<num<<"\n";
        outfile.open("input"+num+".txt");
        int n=10000*i;
        int k=abs(rand()%n);
        outfile<<n<<" "<<k<<"\n";
        for(int i=1;i<=n;i++){
            int a = abs((rand()*i)%(100000)); a++;
            outfile<<a<<" ";
        }
        outfile<<"\n";
        outfile.close();
    }
    return 0;
}