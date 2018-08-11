#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string.h>
#include <math.h>

using namespace std;

string str;
int freq[30];

bool rearrange(){
    memset(freq,0,sizeof freq);
    int maxi=0;
    int n=str.size();

    for(int i=0;i<n;i++)
        freq[str[i]-'a']++,maxi=max(freq[str[i]-'a'],maxi);
    //cout<<maxi<<" "<<(n+1)/2<<"\n";
    if(maxi>(n+1)/2)
        return false;

    for(int i=0;i<n;i++)
        str[i]='A';

    for(int i=0;i<n;i++){
        if(str[i]=='A'){
            char ch;
            for(int j=0;j<26;j++)
                if(freq[j]){
                    ch='a'+i;
                    break;
                }
            for(int j=i;j<n and freq[ch-'a'];j+=2){
                str[j]=ch;
                freq[ch-'a']--;
            }
        }
    }
    return true;
}

int main()
{   
    int test;
    cin>>test;
    while(test--){
        cin>>str;
        if(!rearrange())
            cout<<-1;
        else
            cout << str;
        cout<<"\n";
    }   
    return 0;
}