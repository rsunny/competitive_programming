#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <map>

using namespace std;

map<vector<int>,bool> vis;

int n;

bool equal(vector<int> arr){
	int ele=arr[0];
	for(int i=0;i<n;i++)
		if(arr[i]!=ele)
			return false;
	return true;
}

void print(vector<int> arr){
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<"\n";
	return ;
}

int reco(vector<int> arr,int step){
	print(arr);
	if(equal(arr)){
		cout<<step<<" "<<"\n";
		return 1;
	}
	vector<int> diff;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			diff.push_back(arr[j]-arr[i]);
			if(arr[j]-arr[i]>=2*n)
				return 0;
		}
	}
	if(vis[diff])
		return 0;
	vis[diff]=1;
	diff.clear();
	for(int i=0;i<n;i++){
		diff.push_back(arr[i]+1);
	}
	for(int i=0;i<n;i++){
		diff[i]--;
		vector<int> pass=diff;
		sort(pass.begin(), pass.end());
		if(reco(diff,step+1))
			return 1;
		diff[i]++;
	}
	return 0;
}

int main(){
	n=5;
	vector<int> arr;
	for(int i=1;i<=5;i++)
		arr.push_back(i);
	reco(arr,0);
	return 0;
}
