//https://csacademy.com/contest/archive/task/tree-nodes-destruction/

#include <bits/stdc++.h>

#define MAX_N 500009

using namespace std;

vector<long long int> node,cum_fre;
int ind_fre[MAX_N];
vector<int> tree[MAX_N];
int freq[MAX_N];
int vis[MAX_N];
vector<int> len[MAX_N],ed[MAX_N];
int maxl;

void all_clear(){
    node.clear();
    cum_fre.clear();
    for(int i=0;i<MAX_N;i++)
        ed[i].clear(),tree[i].clear(),len[i].clear(),ind_fre[i]=0,freq[i]=0,vis[i]=0;
}


void dfs(int node,int l){
    if(vis[node])
        return ;
    vis[node]=1;
    maxl=max(l,maxl);
    len[l].push_back(node);
    for(int i=0;i<(int)ed[node].size();i++)
        dfs(ed[node][i],l+1);
    return ;
}

int main(){
	int n=10;
	int file=2;
    int mul=100;
    ofstream outfile;
    for(int k=0;k<=10;k++){
    	n+=abs(rand())%mul;
        stringstream ss;
        string num;
        ss<<file++;
        ss>>num;
        if(num.size()==1)
            num="0"+num;
        string num_temp=num;
        num = "input"+num+".txt";
        char inp[(int)num.size()];
        for(int i=0;i<(int)num.size();i++)
          inp[i]=num[i];
        
        outfile.open(inp);

        if(k%3==0)
            mul*=10;

        if(k==10)
        	n=500000;
        n=min(500000,n);
		outfile<<n<<"\n";
        cout<<k<<" "<<n<<" ";
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
            ed[par].push_back(pre);
            ed[pre].push_back(par);
            ind_fre[pre]=ind_fre[par]++;
            cum_fre.push_back(cum_fre[i-1]+ind_fre[pre]);
        }
        vector<int> ed1,ed2;
        for(int i=0;i<MAX_N;i++){
            for(int j=0;j<(int)tree[i].size();j++){
                ed1.push_back(i),ed2.push_back(tree[i][j]);
            }
        }
        
        outfile<<ed1.size()<<"\n";
        for(int i=0;i<(int)ed1.size();i++)
            outfile<<ed1[i]<<"\n";

        outfile<<ed2.size()<<"\n";
        for(int i=0;i<(int)ed2.size();i++)
            outfile<<ed2[i]<<"\n";

        int node = abs(rand())%n;
        node++;
        maxl=0;
        dfs(node,1);
        
        int l;
        for(int i=0;i<maxl;i++){
            if(len[i].size()>=3 and abs(rand())%50>40){
                l=i;
                break;
            }
        }

        int rep = abs(rand()%10005);
        while(rep-- and next_permutation(len[l].begin(),len[l].end()));

        for(int i=0;i<3;i++){
            outfile<<len[l][i]<<"\n";
            cout<<len[l][i]<<" ";
        }

        cout<<"\n";
        cout<<node<<"\n";
        
        outfile.close();

        num=num_temp;

        num = "output"+num+".txt";
        char out[(int)num.size()];
        
        for(int i=0;i<(int)num.size();i++)
          out[i]=num[i];
        
        outfile.open(out);
        outfile<<node<<"\n";
        outfile.close();

	}
	return 0;
}