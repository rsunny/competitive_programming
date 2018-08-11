#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <cassert>
#include <map>
#include <string.h>

using namespace std;

bool vis[25][25];
int c[25];

int main(){
	int l,r;
    int n,m,q;
	int file=3;
    ofstream outfile;
    for(int k=0;k<=10;k++){
        memset(vis,0,sizeof vis);
        memset(c,0,sizeof c);
        n=10,q=15;
        if(k==2)
            n=3,q=3;
        if(k>3)
            n=15,q=30;
        if(k>5)
            n=21,q=30;
        stringstream ss;
        string num;
        ss<<file++;
        ss>>num;
        if(num.size()==1)
            num="0"+num;
        outfile.open("input"+num+".txt");
        if(k>5)
            m=50;
        else
            m=abs(rand()%50)+1;
        assert(n>=1 and n<=21);
        assert(m>=1 and m<=50);
        assert(q>=1 and q<=30);
        outfile<<m<<" "<<n<<" "<<q<<"\n";
        for(int j=0;j<n;j++){
            l=rand()%1000000;
            l=abs(l)+1;
            outfile<<l<<" ";
            assert(l>=1 and l<=(int)1e6);
        }
        outfile<<"\n";
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                l=rand()%1000000;
                l=abs(l)+1;
                outfile<<l<<" ";
                assert(l>=1 and l<=(int)1e6);
            }
            outfile<<"\n";
        }
        while(q){
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    cout<<k<<" "<<q<<" "<<i<<" "<<j<<" "<<c[i]<<" "<<c[j]<<" "<<vis[i][j]<<"\n";
                    if( (k==2 or (rand()%3 and c[i]<=5 and c[j]<=5)) and q  and vis[i][j]!=true ){
                        q--;outfile<<i<<" "<<j<<"\n";
                        cout<<i<<" "<<j<<"\n";
                        vis[i][j]=vis[j][i]=true,c[i]++,c[j]++;
                        break;
                    }
                }
                if(!q)
                    break;
            }
        }
        outfile.close();
        cout<<"\n\n ----- \n\n";
	}
	return 0;
}