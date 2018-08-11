#include <stdio.h>
#include <iostream>
#include <map>

using namespace std;

int m,x;

struct node_trie{
	int cnt;
    node_trie *one,*zero;
    node_trie(){cnt=0;one=zero=0;}
};

string exor;
long long int pow_2[40];

node_trie* insert_trie(node_trie *p,int pos,int val){
    if(!p)
        p=new node_trie();
    p->cnt+=val;
    if(pos==40)
        return p;
    if(exor[pos]=='1')
        p->one=insert_trie(p->one,pos+1,val);
    else
        p->zero=insert_trie(p->zero,pos+1,val);
    return p;
}

long long int query_trie(node_trie *p,int pos){
    long long int res=0;
    if(pos==40)
        return 0LL;
    if(exor[pos]=='0'){
        if(p->one and p->one->cnt>0)
            res=pow_2[39-pos]+query_trie(p->one,pos+1);    
        else if(p->zero and p->zero->cnt>0)
            res=query_trie(p->zero,pos+1);
    }   
    if(exor[pos]=='1'){
        if(p->zero and p->zero->cnt>0)
            res=query_trie(p->zero,pos+1);    
        else if(p->one and p->one->cnt>0)
            res=pow_2[39-pos]+query_trie(p->one,pos+1);
    }   
    return res;
}

int main(){
    cin>>m;
    map<long long int,int> arr;
    pow_2[0]=1LL;
    exor='0';
    for(int i=1;i<40;i++)
        exor+='0',pow_2[i]=pow_2[i-1]*2LL;
    int pos=40;
    long long int y;
    node_trie *root_trie;
    root_trie=NULL;
    for(int i=0;i<m;i++){
    	char ch;
    	long long int x;
    	cin>>ch>>x;
        switch(ch){
            case '+':
            	arr[x]++;
                y=x;
                while(y){
                    pos--;
                    if(y%2LL)
                        exor[pos]='1';
                    y/=2LL;
                }
                root_trie=insert_trie(root_trie,0,1);
                pos=0;
                while(pos<40)
                    exor[pos]='0',pos++;
                break;
            case '?':
                y=x;
                while(y){
                    pos--;
                    if(y%2LL)
                        exor[pos]='1';
                    y/=2LL;
                }
                cout<<(x^query_trie(root_trie,0))<<"\n";
                pos=0;
                while(pos<40)
                    exor[pos]='0',pos++; 
                break;
            case '-':
            	y=x;
                while(y){
                    pos--;
                    if(y%2LL)
                        exor[pos]='1';
                    y/=2LL;
                }
                arr[x]--;
                if(arr[x]==0)
                	root_trie=insert_trie(root_trie,0,-1);
                pos=0;
                while(pos<40)
                    exor[pos]='0',pos++;   
                break;
        }
    }
    return 0;
}