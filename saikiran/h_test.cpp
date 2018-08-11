#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include "testlib.h"

#define fir first
#define sec second
#define ll long long
#define INF (int)1e9
#define pb push_back
#define mp make_pair

using namespace std;

static int te[10001][10001];

int main(int argc, char* argv[]){
	//ofstream cout("testing1.txt");
	registerGen(argc, argv, 1);
	vector<pair<int,int> >v;
	int k=0;
	for(int i=1;i<100000;i++){
		if(k%50==0 and i+3<=100000){
			v.pb(mp(i,i+1));
			v.pb(mp(i,i+2));
			v.pb(mp(i+1,i+2));
			v.pb(mp(i+1,i+3));
			v.pb(mp(i+2,i+3));
			i+=2;
		}
		else{
			v.pb(mp(i,i+1));
		}
		k++;
	}
	int maxi=-1;
	for(int i=0;i<v.size();i++){
		maxi=max(maxi,max(v[i].fir,v[i].sec));
	}
	cout<<maxi<<" "<<v.size()<<endl;
	int x=rnd.next(1,maxi);
	int y=rnd.next(1,maxi);
	cout<<x<<" "<<y<<endl;
	for(int i=0;i<v.size();i++){
		int n=rnd.next(1,10000);
		cout<<v[i].fir<<" "<<v[i].sec<<" "<<n<<endl;
	}
	return 0;
}