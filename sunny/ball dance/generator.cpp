//https://csacademy.com/contest/virtual23/#task/swap_pairing/

#include <bits/stdc++.h>

#define MAX_N 100000

using namespace std;

int main(){
	int n=10;
	int file=2;
    ofstream outfile;
    for(int k=0;k<=10;k++){
    	n+=abs(rand())%20;
        stringstream ss;
        string num;
        ss<<file++;
        ss>>num;
        if(num.size()==1)
            num="0"+num;
        num = "input"+num+".txt";
        char inp[100];
        for(int i=0;i<(int)num.size();i++)
          inp[i]=num[i];
        
        outfile.open(inp);

        if(k==10)
        	n=200;
        n=min(200,n);
		outfile<<n<<"\n";
        outfile<<2*n<<"\n";
        int x=0;
        vector<int> v1,v2;
        set<int> m;
        for(int i=1;i<=n;i++){
            x=abs(rand())%1000;
            while(!x or m.find(x)!=m.end()){
                x++;
                x%=1001;
            }
            m.insert(x);
            v1.push_back(x);
            v2.push_back(x);
		}
        int i=0, j=0;
        int n1 = n;
        int n2 = n;
        if(k>=8)
            reverse(v2.begin(),v2.end());
        while (i < n1 and j < n2){
            x=abs(rand())%50;
            if (x>30){
                outfile<<v1[i]<<"\n";
                i++;
            }
            else{
                outfile<<v2[j]<<"\n";
                j++;
            }
        }
        while (i < n1){
            outfile<<v1[i]<<"\n";
            i++;
        }
     
        while (j < n2){
            outfile<<v2[j]<<"\n";
            j++;
        }
        outfile.close();
	}
	return 0;
}