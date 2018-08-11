#include <iostream>
#include <vector>

using namespace std;

int h1,a1,x1,y1,ind1=-1;
int h2,a2,x2,y2,ind2=-1;
int m;
int vis1[1000009];
int vis2[1000009];
vector<int> head1,cycle1;
vector<int> head2,cycle2;


int main(){
	cin>>m;
	cin>>h1>>a1;
	cin>>x1>>y1;
	cin>>h2>>a2;
	cin>>x2>>y2;

	int hh1 = h1;
	while(!vis1[hh1]){
		vis1[hh1] = 1;
		hh1 = (x1*hh1) + y1;
		hh1 %= m;
	}

	int hh11 = h1;
	while(hh1!=hh11){
		head1.push_back(hh11);
		if(hh11==a1)
			ind1=head1.size()-1;
		hh11 = (x1*hh11) + y1;
		hh11 %= m;
	}

	do{
		cycle1.push_back(hh11);
		vis1[hh11] = 2;
		if(hh11==a1)
			ind1=cycle1.size()-1;
		hh11 = (x1*hh11) + y1;
		hh11 %= m;
	}while(hh11!=hh1);

	int hh2 = h2;
	while(!vis2[hh2]){
		vis2[hh2] = 1;
		hh2 = (x2*hh2) + y2;
		hh2 %= m;
	}

	int hh22 = h2;
	while(hh2!=hh22){
		head2.push_back(hh22);
		if(hh22==a2)
			ind2=head2.size()-1;
		hh22 = (x2*hh22) + y2;
		hh22 %= m;
	}
	do{
		cycle2.push_back(hh22);
		vis2[hh22] = 2;
		if(hh22==a2)
			ind2=cycle2.size()-1;
		hh22 = (x2*hh22) + y2;
		hh22 %= m;
	}while(hh22!=hh2);

	if(!vis1[a1] or !vis2[a2]){
		cout<<"-1\n";
		return 0;
	}
	
	if(vis1[a1]==1 and vis2[a2]==1){
		if(ind1!=ind2)
			cout<<"-1\n";
		else
			cout<<ind2-1<<"\n";
		return 0;
	}

	if(vis1[a1]==1 and vis2[a2]==2){
		int steps=ind2 + head2.size();
		while(steps<ind1){
			steps += cycle2.size();
		}
		if(steps != ind1)
			cout<<"-1\n";
		else
			cout<<ind1-1<<"\n";
		return 0;
	}

	if(vis2[a2]==1 and vis1[a1]==2){
		int steps=ind1 + head1.size();
		while(steps<ind2){
			steps += cycle1.size();
		}
		if(steps != ind2)
			cout<<"-1\n";
		else
			cout<<ind2-1<<"\n";
		return 0;
	}

	
	return 0;
}