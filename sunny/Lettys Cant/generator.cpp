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

char ch[]={'a', 'b', 'c', 'd', '0', '1'};

int main(){
  int file=1;
  ofstream outfile;
  int n=3;
  for(int k=1;k<=12;k++){
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
    if(k<=2)
      n++;
    else if(k<12)
      n+=abs(rand())%10000;
    else
      n=100000;
    n=min(n,100000);
    outfile<<n<<"\n";
    for(int i=0;i<n;i++){
      int pos=abs(rand())%10000007;
      pos%=6;
      outfile<<ch[pos];
    }
    outfile.close();
  }
  return 0;
}
