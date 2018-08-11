#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
//#include <bits/stdc++.h>

using namespace std;

int c[100009];
long long int cnt[100009];
long long int res;

string preProcess(string s){
  int n = s.length();
  string ret = "^";
  for (int i = 0; i < n; i++)
    ret += "#" + s.substr(i, 1);
 
  ret += "#$";
  return ret;
}
 
string countgood(string s){
  string T = preProcess(s);
  int n = T.length();
  int *P = new int[n];
  int C = 0, R = 0;
  for (int i = 1; i < n-1; i++) {
    int i_mirror = 2*C-i; 
    
    P[i] = (R > i) ? min(R-i, P[i_mirror]) : 0;
    
    // Attempt to expand palindrome centered at i
    while (T[i + 1 + P[i]] == T[i - 1 - P[i]]){
      P[i]++;	

    }
 
    if (i + P[i] > R) {
      C = i;
      R = i + P[i];
    }
  }
  return ;
}

int main(int argc, char *argv[]){
	string s,text;
	int n,p=0;
	cin>>s;
	n=s.size();
	text+=s[0];
	c[p]=1;
	for(int i=1;i<n;i++){
		if(s[i]!=s[i-1]){
			text+=s[i];
			p++;
		}
		c[p]+=1;
	}
	countgood(text);

	return 0;
}
