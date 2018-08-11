#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <cassert>

using namespace std;

int MAXN = 100;

int main(){
  int file=0;
  int t=1;
  ofstream outfile;
  for(int k=1;k<=9;k++){
    stringstream ss;
    string num;
    ss<<file++;
    ss>>num;
    if(num.size()==1)
        num="0"+num;
    outfile.open("input"+num+".txt");
    outfile<<t<<"\n";
    for(int i=0;i<MAXN;i++){
        char ch = 'a'+abs(rand()*1953)%26;
        outfile<<ch;
    }
    outfile<<"\n";
    outfile.close();
  }
  return 0;
}