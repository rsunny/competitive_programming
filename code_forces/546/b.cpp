#include <iostream>
#include <map>
#include <vector>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <cstdio>

using namespace std;

vector<int> v;
bool arr[100000];

int main(){
	int n,b;
	cin>>n;
	int mini=1e5;
	for(int i=0;i<n;i++){
		cin>>b;
		arr[b]=true;
		v.push_back(b);
		mini=min(b,mini);
	}
	sort(v.begin(), v.end());
	int res=0;
	for(int i=1;i<n;i++){
		if(v[i]==v[i-1]){
			int need=v[i];
			while(1){
				if(arr[need]==0){
					res+=(need-v[i]);
					arr[need]=1;
					break;
				}
				need++;
			}
		}
	}
	cout<<res<<"\n";
	return 0;
}