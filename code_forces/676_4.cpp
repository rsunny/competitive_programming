#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int vis[1005][1005][5];
char mz[1005][1005];

map<char,vector<int> > dx,dy;
map<char,map<int,char> > rot;
map<char,map<char,int> > st,sd;

void pre(){
    vector<int> dirx,diry;
    dirx.clear();dirx.push_back(1);dirx.push_back(-1);dirx.push_back(0);dirx.push_back(0);
    diry.clear();diry.push_back(0);diry.push_back(0);diry.push_back(1);diry.push_back(-1);
    dx['+']=dirx; dy['+']=diry;
    dirx.clear();dirx.push_back(0);dirx.push_back(0);
    diry.clear();diry.push_back(1);diry.push_back(-1);
    dx['-']=dirx; dy['-']=diry;
    dirx.clear();dirx.push_back(1);dirx.push_back(-1);
    diry.clear();diry.push_back(0);diry.push_back(0);
    dx['|']=dirx; dy['|']=diry;
    dirx.clear();dirx.push_back(1);
    diry.clear();diry.push_back(0);
    dx['^']=dirx; dy['^']=diry;
    dirx.clear();dirx.push_back(0);
    diry.clear();diry.push_back(1);
    dx['>']=dirx; dy['>']=diry;
    dirx.clear();dirx.push_back(0);
    diry.clear();diry.push_back(-1);
    dx['<']=dirx; dy['<']=diry;
    dirx.clear();dirx.push_back(-1);
    diry.clear();diry.push_back(0);
    dx['v']=dirx; dy['v']=diry;
    dirx.clear();dirx.push_back(1);dirx.push_back(-1);dirx.push_back(0);
    diry.clear();diry.push_back(0);diry.push_back(0);diry.push_back(1);
    dx['L']=dirx; dy['L']=diry;
    dirx.clear();dirx.push_back(1);dirx.push_back(-1);dirx.push_back(0);
    diry.clear();diry.push_back(0);diry.push_back(0);diry.push_back(-1);
    dx['R']=dirx; dy['R']=diry;
    dirx.clear();dirx.push_back(1);dirx.push_back(-1);dirx.push_back(0);dirx.push_back(0);
    diry.clear();diry.push_back(0);diry.push_back(0);diry.push_back(1);diry.push_back(-1);
    dx['+']=dirx; dy['+']=diry;
    dirx.clear();dirx.push_back(-1);dirx.push_back(0);dirx.push_back(0);
    diry.clear();diry.push_back(0);diry.push_back(1);diry.push_back(-1);
    dx['U']=dirx; dy['U']=diry;
    dirx.clear();dirx.push_back(1);dirx.push_back(0);dirx.push_back(0);
    diry.clear();diry.push_back(0);diry.push_back(1);diry.push_back(-1);
    dx['D']=dirx; dy['D']=diry;

    rot['+'][0]='+'; rot['+'][1]='+'; rot['+'][2]='+'; rot['+'][3]='+';
    rot['-'][0]='-'; rot['-'][1]='|'; rot['-'][2]='-'; rot['-'][3]='|';
    rot['|'][0]='|'; rot['|'][1]='-'; rot['|'][2]='|'; rot['|'][3]='-';
    rot['^'][0]='^'; rot['^'][1]='>'; rot['^'][2]='v'; rot['^'][3]='<';
    rot['>'][0]='>'; rot['>'][1]='v'; rot['>'][2]='<'; rot['>'][3]='^';
    rot['<'][0]='<'; rot['<'][1]='^'; rot['<'][2]='>'; rot['<'][3]='v';
    rot['v'][0]='v'; rot['v'][1]='<'; rot['v'][2]='^'; rot['v'][3]='>';
    rot['L'][0]='L'; rot['L'][1]='U'; rot['L'][2]='R'; rot['L'][3]='D';
    rot['R'][0]='R'; rot['R'][1]='D'; rot['R'][2]='L'; rot['R'][3]='U';
    rot['U'][0]='U'; rot['U'][1]='R'; rot['L'][2]='D'; rot['L'][3]='L';
    rot['D'][0]='D'; rot['D'][1]='L'; rot['D'][2]='U'; rot['D'][3]='R';

    st['+']['+']=1;st['+']['|']=1;st['+']['^']=1;st['+']['L']=1;st['+']['R']=1;st['+']['D']=1;
    st['|']['+']=1;st['|']['|']=1;st['|']['^']=1;st['|']['L']=1;st['|']['R']=1;st['|']['D']=1;
    st['v']['+']=1;st['v']['|']=1;st['v']['^']=1;st['v']['L']=1;st['v']['R']=1;st['v']['D']=1;
    st['L']['+']=1;st['L']['|']=1;st['L']['^']=1;st['L']['L']=1;st['L']['R']=1;st['L']['D']=1;
    st['R']['+']=1;st['R']['|']=1;st['R']['^']=1;st['R']['L']=1;st['R']['R']=1;st['R']['D']=1;
    st['U']['+']=1;st['U']['|']=1;st['U']['^']=1;st['U']['L']=1;st['U']['R']=1;st['U']['D']=1;

    sd['+']['+']=1;sd['+']['-']=1;sd['+']['<']=1;sd['+']['R']=1;sd['+']['U']=1;sd['+']['D']=1;
    sd['-']['+']=1;sd['-']['-']=1;sd['-']['<']=1;sd['-']['R']=1;sd['-']['U']=1;sd['-']['D']=1;
    sd['>']['+']=1;sd['>']['-']=1;sd['>']['<']=1;sd['>']['R']=1;sd['>']['U']=1;sd['>']['D']=1;
    sd['L']['+']=1;sd['L']['-']=1;sd['L']['<']=1;sd['L']['R']=1;sd['L']['U']=1;sd['L']['D']=1;
    sd['U']['+']=1;sd['U']['-']=1;sd['U']['<']=1;sd['U']['R']=1;sd['U']['U']=1;sd['U']['D']=1;
    sd['D']['+']=1;sd['D']['-']=1;sd['D']['<']=1;sd['D']['R']=1;sd['D']['U']=1;sd['D']['D']=1;

    return ;
}


int main() {
    int n,m;
    pre();
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>mz[i][j];
    int x,y,ex,ey,l,r;
    cin>>x>>y>>ex>>ey;
    queue<int> X,Y,R,L;
    X.push(x),Y.push(y),R.push(0),L.push(0);
    X.push(x),Y.push(y),R.push(1),L.push(1);
    X.push(x),Y.push(y),R.push(2),L.push(2);
    X.push(x),Y.push(y),R.push(3),L.push(3);
    vis[x][y][0]=vis[x][y][1]=vis[x][y][2]=vis[x][y][3]=1;
    int ans=INT_MAX;
    while(X.size()){
        x=X.front();y=Y.front();l=L.front();r=R.front();
        X.pop(), Y.pop(), L.pop(), R.pop();
        if(x==ex and y==ey){
            ans=min(ans,l);
            continue;
        }
        char ele=mz[x][y];
        for(int i=0;i<4;i++){
            int rr=(r+i)%4;
            char el=rot[ele][rr];
            for(int j=0;j<(int)dx[el].size();j++){
                int xx=x+dx[el][j];
                int yy=y+dy[el][j];
                if(xx>0 and xx<n and yy>0 and yy<m){
                    int con=0;
                    if(xx==x){
                        if(yy>y)
                            con=sd[el][rot[mz[xx][yy]][rr]];
                        else
                            con=sd[rot[mz[xx][yy]][rr]][el];
                    }
                    if(yy==y){
                        if(xx>x)
                            con=st[el][rot[mz[xx][yy]][rr]];
                        else
                            con=st[rot[mz[xx][yy]][rr]][el];
                    }
                    if(!vis[xx][yy][rr] and con){
                        vis[xx][yy][rr]=1;
                        X.push(xx);
                        Y.push(yy);
                        R.push(rr);
                        L.push(l+1+i);
                    }
                }
            }
        }
    }
    if(ans==INT_MAX)
        ans=-1;
    cout<<ans<<"\n";
    return 0;
}



