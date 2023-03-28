// construct a map, the first member of which is the name of a family
// the second is an ensemble containning names of children


#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;
map<string, vector<string> > family;
int main(){
	char c;
	string f, m;
	cout<<"input a: create a new family b :add members in a family";
	cout<<"\nc to show, q to quit\n";
	while(cin>>c && c!='q'){
		switch(c){
			case 'a':
			case 'A':
				cout<<"Name of the family: ";cin>>f;
				cout<<"Member of the family: ";cin>>m;
				family[f].push_back(m);
				break;
			case 'b':
				cout<<"Add to which family: \nOptions: ";
				for(auto w: family) cout<<w.first<<" ";
				cout<<endl;
				cin>>f;cout<<"Name of the member: ";cin>>m;
				family[f].push_back(m);
				break;
			case 'c':
				for(auto w: family){
					cout<<"Family: "<<w.first<<"\nMembers: ";
					for(auto w1: w.second)
						cout<<w1<<" ";
					cout<<endl;
				}
				break;
		}
	cout<<"input a: create a new family b :add members in a family";
	cout<<"\nc to show, q to quit\n";
	}
}
