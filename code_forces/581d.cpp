#include <iostream> 
#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;

int x[3],y[3];
int resx[3],resy[3];
int pos[105][105];
int sq;
bool found;

bool check(){
    for(int i=0;i<sq;i++)
        for(int j=0;j<sq;j++)
            if(pos[i][j]==0)
                return false;
    return true;
}

bool check1(int X1,int Y1,int X2,int Y2){
    for(int i=X1;i<X2;i++)
        for(int j=Y1;j<Y2;j++)
            if(pos[i][j]!=0)
                return false;
    return true;
}

void print(){
    for(int i=0;i<sq;i++){
        for(int j=0;j<sq;j++){
            cout<<pos[i][j];
        }
        cout<<"\n";
    }
    return ;
}

void reco(int mask){
    //cout<<mask<<"\n";print();
    if(mask==7){
        found=check();
        return;
    }
    
    int X=-1,Y=-1;
    for(int i=0;i<sq;i++){
        for(int j=0;j<sq;j++)
            if(pos[i][j]==0){
                X=i;
                Y=j;
                break;
            }
        if(X!=-1 or Y!=-1)
            break;
    }
    
    for(int i=0;i<3;i++){
        if(mask&(1<<i))
            continue;
        //cout<<X<<" "<<Y<<" "<<x[i]<<" "<<y[i]<<" "<<i<<"--\n";
        if(X+x[i]<=sq and Y+y[i]<=sq and check1(X,Y,X+x[i],Y+y[i])){
            //cout<<"here1\n";
            for(int j=0;j<x[i];j++){
                for(int k=0;k<y[i];k++){
                    //cout<<X+j<<" "<<Y+k<<"\n";
                    pos[X+j][Y+k]=i+1;
                }
            }
            //cout<<"reco\n";
            reco(mask|(1<<i));
            if(found)
                return;
            for(int j=0;j<x[i];j++){
                for(int k=0;k<y[i];k++){
                    pos[X+j][Y+k]=0;
                }
            }
        }
        if(Y+x[i]<=sq and X+y[i]<=sq and check1(X,Y,X+y[i],Y+x[i])){
            //cout<<"here2\n";
            for(int j=0;j<y[i];j++){
                for(int k=0;k<x[i];k++){
                    pos[X+j][Y+k]=i+1;
                }
            }
            //cout<<"reco\n";
            reco(mask|(1<<i));
            if(found)
                return;
            for(int j=0;j<y[i];j++){
                for(int k=0;k<x[i];k++){
                    pos[Y+j][X+k]=0;
                }
            }
        }
    }
    return;
}

int main(){
    for(int i=0;i<3;i++)
        cin>>x[i]>>y[i],sq=max(sq,max(x[i],y[i]));
    //cout<<sq<<"\n";
    reco(0);
    if(!found){
        cout<<-1<<"\n";
        return 0;
    }
    cout<<sq<<"\n";
    for(int i=0;i<sq;i++){
        for(int j=0;j<sq;j++){
            if(pos[i][j]==1)
                cout<<"A";
            else if (pos[i][j]==2)
                cout<<"B";
            else
                cout<<"C";
        }
        cout<<"\n";
    }
    return 0;
}