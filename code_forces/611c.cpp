#include <iostream>

using namespace std;

char arr[505][505];
int lft[505][505];
int bottom[505][505];

int main(){
	int n,m;
	string s;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s;
		for(int j=1;j<=m;j++){
			arr[i][j]=s[j-1];
		}
	}

	//lft

	for(int i=1;i<=n;i++){
		int cnt=0;
		for(int j=1;j<=m;j++){
			if(arr[i][j]=='.' and j+1<=m and arr[i][j+1]=='.')
				cnt++;
			lft[i][j]=cnt;
			//cout<<lft[i][j]<<" ";
		}
		//cout<<"\n";
	}

	//bottom

	for(int j=1;j<=m;j++){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(arr[i][j]=='.' and i+1<=n and arr[i+1][j]=='.')
				cnt++;
			bottom[i][j]=cnt;
			//cout<<bottom[i][j]<<" ";
		}
		//cout<<"\n";
	}

	int q;
	cin>>q;

	while(q--){
		int r1,c1,r2,c2;
		cin>>r1>>c1>>r2>>c2;
		int res = 0;
		for(int i=r1;i<=r2;i++){
			//cout<<lft[c2-1][i]<<" "<<lft[c1-1][i]<<"\n";
			res+=lft[i][c2-1]-lft[i][c1-1];
		}
		for(int j=c1;j<=c2;j++){
			//cout<<bottom[r2-1][j]<<" "<<bottom[r1-1][j]<<"\n";
			res+=bottom[r2-1][j]-bottom[r1-1][j];
		}
		cout<<res<<"\n";
	}

	return 0;
}