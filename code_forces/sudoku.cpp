#include <iostream>
#include <unordered_map>
#include <utility>
#include <string.h>
#include <vector>

#define ORDER 9

using namespace std;

int sudoku[ORDER][ORDER];
bool vis[ORDER][ORDER][ORDER][ORDER];
int temp[ORDER];   
vector<pair<int,int> > ind; 

pair<int,int> Check (int y[ORDER]) {
  for (int i=0; i<ORDER; i++){
    for(int j=i+1;j<ORDER;j++){
      if(y[i]==y[j])
        return make_pair(i,j);
    }
  }
  return make_pair(9,9);
}

int RowCheck ( int x[ORDER][ORDER]) {
  for (int i=0; i<ORDER; i++) {
    for (int j= 0; j<ORDER; j++)
      temp[j] = x[i][j];
		pair<int,int> res = Check(temp); 
    if ( res != make_pair(9,9) ){
      ind.push_back(make_pair(i,res.first));
      ind.push_back(make_pair(i,res.second));
      return 0;
    }
  }
  return 1;
}

int ColumnCheck ( int x[ORDER][ORDER]) {
  int i,j;
  for (i=0; i<ORDER; i++) {
    for (j= 0; j<ORDER; j++)
      temp[j] = x[j][i];
    pair<int,int> res = Check(temp); 
    if ( res != make_pair(9,9) ){
      ind.push_back(make_pair(j,res.first));
      ind.push_back(make_pair(j,res.second));
      return 0;
    }
  }
  return 1;
}			

int SquaresCheck (int x[ORDER][ORDER]) {

  int i;
  int j;
  int column;
  int row;
  int k;
	
  for (column=0; column <= 6; column += 3) {
    for (row=0; row <= 6; row += 3) {
      for (k=0, i=0; i<3; i++) {
      	for (j=0; j<3; j++)
      	  temp[k++] = x[row+i][column+j];
        }
      pair<int,int> res = Check(temp); 
      if ( res != make_pair(9,9) ){   
        for (k=0, i=0; i<3; i++) 
          for (j=0; j<3; j++)
              if(k==res.first or k==res.second)
                ind.push_back(make_pair(row+i,column+j));
        return 0;
      }	
    }
  }
	
  return 1;
}
		

void solve(){
  if ( RowCheck(sudoku) == 1 and ColumnCheck(sudoku)==1 and SquaresCheck(sudoku)==1) {
    cout<<"Serendipity\n";
    return ;
  }
  
  for(int i=0;i<(int)ind.size();i++){
    cout<<ind[i].first<<" "<<ind[i].second<<"\n";
  }

  memset(vis,false, sizeof vis);

  for(int i=0;i<ORDER;i++){
    for(int j=0;j<ORDER;j++){
      for(int k=0;k<ORDER;k++){
        for(int l=0;l<ORDER;l++){
          pair<int,int> p1,p2;
          p1=make_pair(i,j);
          p2=make_pair(k,l);
          if(p1>p2)
            swap(p1,p2);
          if(vis[i][j][k][l] or vis[k][l][i][j])
            continue;
          vis[i][j][k][l] = vis[k][l][i][j] = true;
          swap(sudoku[i][j],sudoku[k][l]);
          if ( RowCheck(sudoku) == 1 and ColumnCheck(sudoku)==1 and SquaresCheck(sudoku)==1) {
            printf("(%d,%d) <-> (%d,%d)",p1.first+1,p1.second+1,p2.first+1,p2.second+1);
            return ;
          }
          swap(sudoku[i][j],sudoku[k][l]);
        }
      }
    }
  }
  return ;
}

void print(){
  for(int i=0;i<ORDER;i++){
    for(int j=0;j<ORDER;j++)
      cout<<sudoku[i][j]<<" ";
    cout<<"\n";
  }
  return ;
}

int main() {
  int test,cnt=1;
  cin>>test;
  while(cnt<=test){
    printf("Case #%d:\n",cnt++);
    for (int i=0; i<ORDER; i++)
  	 for (int j=0; j<ORDER; j++)
  	    cin >> sudoku[i][j]; 
    //print(); 
    solve();
  }
  return 0;
}
