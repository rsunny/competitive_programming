//https://csacademy.com/contest/archive/task/tree-nodes-destruction/

#include <bits/stdc++.h>

#define MAX_N 100000

using namespace std;

vector<long long int> node,cum_fre;
int ind_fre[MAX_N];
vector<int> tree[MAX_N];
int freq[MAX_N];

void all_clear(){
    node.clear();
    cum_fre.clear();
    for(int i=0;i<MAX_N;i++)
        tree[i].clear(),ind_fre[i]=0,freq[i]=0;
}

int main(){
	int n=10;
    int m=10;
	int file=2;
    int mul=100;
    ofstream outfile;
    for(int k=0;k<=10;k++){
    	n+=abs(rand())%mul;
        m+=abs(rand())%mul;
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

        if(k%3==0)
            mul*=10;

        if(k==10)
        	n=10000,m=10000;
        n=min(10000,n);
        m=min(10000,m);
		outfile<<n<<"\n";

        int par,pre;
        all_clear();
        for(int i=1;i<=n;i++){
            node.push_back(i);
        }
        int cnt=rand()%MAX_N;
        while(cnt--)
            next_permutation(node.begin(),node.end());

        ind_fre[node[0]]=1;
        cum_fre.push_back(1);
        long long int fre;
        for(int i=1;i<n;i++){
            pre=node[i];
            fre=abs(rand())%cum_fre[i-1];fre++;
            par=lower_bound(cum_fre.begin(),cum_fre.end(),fre)-cum_fre.begin();
            par=node[par];
            tree[par].push_back(pre);
            ind_fre[pre]=ind_fre[par]++;
            cum_fre.push_back(cum_fre[i-1]+ind_fre[pre]);
        }
        vector<int> ed1,ed2;
        cout<<tree[0].size()<<"\n";
        for(int i=0;i<MAX_N;i++){
            for(int j=0;j<(int)tree[i].size();j++){
                ed1.push_back(i),ed2.push_back(tree[i][j]);
                if(ed1[(int)ed1.size()-1]==ed2[(int)ed2.size()-1])
                    cout<<"error\n";
            }
        }
        
        outfile<<ed1.size()<<"\n";
        for(int i=0;i<(int)ed1.size();i++)
            outfile<<ed1[i]<<"\n";

        outfile<<ed2.size()<<"\n";
        for(int i=0;i<(int)ed2.size();i++)
            outfile<<ed2[i]<<"\n";

        set<pair<int,int> > ed;
        while((int)ed.size()<m){
            int a = abs(rand())%n;a++;
            int b = abs(rand())%n;b++;
            ed.insert({a,b});
        }
        
        outfile<<m<<"\n";
        for(set<pair<int,int> >::iterator it=ed.begin();it!=ed.end();it++)
            outfile<<it->first<<"\n";
        
        outfile<<m<<"\n";
        for(set<pair<int,int> >::iterator it=ed.begin();it!=ed.end();it++)
            outfile<<it->second<<"\n";
        
        outfile.close();
	}
	return 0;
}