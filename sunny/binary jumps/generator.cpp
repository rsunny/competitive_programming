#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <cassert>
#include <algorithm>
#include <map>
#include <vector>
#include <utility>

using namespace std;

int d[11]={0,1,2,3,4,5,6,7,4,3,2};

int main(){
  int file=3;
  int n=1578;
  ofstream outfile;
  for(int k=1;k<=10;k++){
    n+=abs(rand())%10000;
    if(k==10)
      n=100000;
    n=min(100000,n);
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
    outfile<<n<<"\n";
    for(int i=1;i<=n and k<8;i++){
      int num = 10+abs(rand())%(int)(50);
      if(num%10>=5)
        outfile<<1;
      else
        outfile<<0;
    }
    for(int i=1;i<=n and k>=8;i++){
      if(i>n/d[k])
        outfile<<1;
      else
        outfile<<0;
    }
    outfile<<"\n";
    outfile.close();
  }
  return 0;
}