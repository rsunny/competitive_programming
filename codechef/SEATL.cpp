#include <iostream>
#include <unordered_map>
#include <stdio.h>
#include <vector>

using namespace std;

unordered_map <int,bool> t[1000009];
int max_t[1000009];
int cnt_t[1000009];
int pre_t[1000009];
int cct_t[1000009];
vector<int> mat[1000009];

int main(){
	int n,m,ele,max_ele=-1;
	int test;
	scanf("%d",&test);
	while(test--){
		scanf("%d %d",&n,&m);

		for(int i=0;i<n;i++){
			mat[i].clear();
			for(int j=0;j<m;j++){
				scanf("%d",&ele);
				mat[i].push_back(ele);
				max_ele=max(max_ele,ele);
			}
		}

		for(int j=0;j<m;j++){

			for(int i=0;i<n;i++)
				ele = mat[i][j], cnt_t[ele]++;
			
			for(int i=0;i<n;i++){
				ele = mat[i][j];
				if(max_t[ele]<cnt_t[ele]){
					t[ele].clear();
					max_t[ele]=cnt_t[ele];
					t[ele][j]=true;
				}
				else if(max_t[ele]==cnt_t[ele])
					t[ele][j]=true;
			}
			for(int i=0;i<n;i++)
				ele = mat[i][j], cnt_t[ele]--;
			
		}

		unordered_map<int,bool> :: iterator it;
		for(int i=1;i<=max_ele;i++){
			//cout<<max_t[i]<<" "<<cct_t[ele]<<"\n";
			for(it=t[i].begin();it!=t[i].end();it++)
				cct_t[i]++;;//,cout<<it->first<<" "<<it->second<<"\n";
			//cout<<"-----\n";
		}

		int ans=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				ele = mat[i][j];
				cnt_t[ele]++;
				pre_t[ele]+=(t[ele][j]);
			}
			for(int j=0;j<m;j++){
				ele = mat[i][j];
				if(!cnt_t[ele])
					continue;
				int res = max_t[ele]+cnt_t[ele];
				//cout<<i<<" "<<j<<" "<<ele<<" "<<pre_t[ele]<<" "<<cct_t[ele]<<" "<<t[ele].size()<<"\n";
				if(pre_t[ele]==cct_t[ele])
					res--;
				ans = max(ans,res);
				cnt_t[ele]=0;
				pre_t[ele]=0;
			}
		}
		printf("%d\n",ans);

		for(int i=1;i<=max_ele;i++){
			t[i].clear();
			max_t[i]=cnt_t[i]=pre_t[i]=cct_t[i]=0;
		}
	}
	return 0;
}