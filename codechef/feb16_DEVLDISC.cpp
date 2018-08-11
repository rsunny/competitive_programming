#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

// int N=7;
// int mat[55][55];
// int dist[55][55];
// int INF = 1e9;

// int floydWarshell (){
//  	//cout<<"in\n";
//     for (int i = 1; i <= N; i++)
//         for (int j = 1; j <= N; j++)
//             dist[i][j] = mat[i][j];
 
//  	int dia=-1;

//     for (int k = 1; k <= N; k++){
//         for (int i = 1; i <= N; i++){
//             for (int j = 1; j <= N; j++){
//                 if (dist[i][k] + dist[k][j] < dist[i][j])
//                     dist[i][j] = dist[i][k] + dist[k][j];
//             }
//         }
//     }
 	
//     for(int i=1;i<=N;i++)
//     	for(int j=1;j<=N;j++){
//     		if(dist[i][j]==INF)
//     			return 0;
//     		dia=max(dia,dist[i][j]);
//     	}

//     for(int i=1;i<=N;i++){
//     	int maxi=0;
//     	for(int j=1;j<=N;j++)
//     		maxi=max(maxi,dist[i][j]);
//     	int ans=0;
//     	for(int j=1;j<=N;j++){
//     		if(dist[i][j]==maxi){
//     			for(int k=1;k<=N;k++)
//     				ans=max(ans,dist[j][k]);
//     		}
//     	}
//     	if(ans!=dia){
//     		for(int i=1;i<=N;i++){
//     			for(int j=1;j<=N;j++)
//     				cout<<mat[i][j]<<" ";
//     			cout<<"\n";
//     		}
//     		cout<<i<<" "<<ans<<" "<<dia<<"\n-----------\n\n";
//     		for(int i=1;i<=N;i++){
//     			for(int j=1;j<=N;j++)
//     				cout<<dist[i][j]<<" ";
//     			cout<<"\n";
//     		}
// 			return 1;
// 		}
//     }
//     return 0;
// }

// int main(){
// 	cout<<N<<"\n";
// 	for(long long int i=1;i<(1LL<<31);i++){
// 		int cnt=-1;
// 		for(int j=1;j<=N;j++){
// 			for(int k=1;k<=N;k++){
// 				if(j>k){
// 					cnt++;
// 					mat[j][k]=mat[k][j]=(i&(1LL<<cnt))?1:0;
// 					if(!mat[j][k])
// 						mat[j][k]=mat[k][j]=INF;
// 				}
// 			}
// 		}
// 		//cout<<i<<" ";
// 		if(floydWarshell())
// 			break;
// 		memset(mat,0,sizeof mat);
// 	}
// 	return 0;
// }

int main(){
	int t,n;
	cin>>t;
	vector<int> e1,e2;
	e1.push_back(1); e2.push_back(5);
	e1.push_back(1); e2.push_back(7);
	e1.push_back(1); e2.push_back(3);
	e1.push_back(4); e2.push_back(3);
	e1.push_back(2); e2.push_back(3);
	e1.push_back(2); e2.push_back(5);
	e1.push_back(2); e2.push_back(6);
	while(t--){
		cin>>n;
		if(n<7){
			cout<<-1<<"\n";
			continue;
		}
		cout<<n<<"\n";
		for(int i=0;i<(int)e1.size();i++)
			cout<<e1[i]<<" "<<e2[i]<<"\n";
		for(int i=8;i<=n;i++)
			cout<<1<<" "<<i<<"\n";
		cout<<5<<"\n";
	}
	return 0;
}