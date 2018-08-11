#include <iostream>

using namespace std;

string ans, mat;

bool val(char a, char b){
    if(a == 'a') {
        if( b== 'b' || b == 'a') return true;
    }
    if(a == 'b') return true;
    if(a == 'c') {
        if( b== 'b' || b == 'c') return true;
    }
    return false;

}

int pre[555][555];

int main(){

ios_base::sync_with_stdio(false);
cin.tie(0);
int i,j,k,l,m,n,f=0;

cin>>n>>m;
for(i=0;i<=n;++i){
    mat += "*";
}
for(i=0;i<m;++i){
    cin>>k>>l;
    pre[k][l] = 1;
    pre[l][k] = 1;

}
for(i=1;i<=n-1;++i){
        f=0;
    for(j=i+1;j<=n;++j){
        if(pre[i][j]){

        }
        else{
            f = 1;
        }
    }
    //cerr<<" F "<<f<<"\n";
    if(f == 0 && mat[i] =='*'){
        mat[i] = 'b';
    }
    else{
        if(mat[i] == '*' || mat[i] == 'b'){
            mat[i] = 'a';
        }
        char damn = 'c';
        if(mat[i] == 'c'){
            damn = 'a';
        }
        for(j=i+1;j<=n;++j){
            if(!pre[i][j]) {
                mat[j] = damn;
            }
        }
    }
}
if(mat[n] == '*') mat[n] = 'b';
//cerr<<mat<<" ";

for(i=1;i<=n;++i){
    ans += mat[i];
    for(j=i+1;j<=n;++j){
        //cerr<<mat[i]<<" : "<<mat[j]<<" "<<val(mat[i],mat[j])<<"\n";
        if(pre[i][j]){
            if(!val(mat[i], mat[j] ) ){
                cout<<"No";return 0;
            }
        }
        else{
            //cerr<<" OUT ";
            if(val(mat[i], mat[j] ) ){
                cout<<"No";return 0;
            }
        }
    }
}
cout<<"Yes\n";
cout<<ans;
return 0;
}