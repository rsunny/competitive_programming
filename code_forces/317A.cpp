#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
//#include <bits/stdc++.h>

using namespace std;

int l;

int func(int a,int b,int c){
  
}

int main(int argc, char *argv[]){
  int a,b,c;
  cin>>a>>b>>c>>l;
  int res=0;
  res+=func(a,b,c);
  res+=func(a,c,b);
  res+=func(b,c,a);
  cout<<res<<"\n";
  return 0;
}
