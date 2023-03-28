#include<iostream>
#include<vector>
#include<string>
#include<deque>
#include<list>
using namespace std;
void ex9_18();void ex9_20();
void ex9_21();
int main(){
	//ex9_18();
	//ex9_20();
	ex9_21();
}
void ex9_18(){
	deque<string> d;
	string s;
	cout<<"Please input a string: ";
	while(cin>>s && s!="q"){
		d.push_back(s);
		cout<<"Please input a string: ";
	}
	cout<<"This is what you want to say: \n";
	for(deque<string>::iterator c=d.begin();
		c!=d.end();++c)
		cout<<(*c)<<" ";
	cout<<endl;
}
void ex9_20(){
	list<int> l;deque<int> d1, d2;
	int x;
	while(cin>>x)
		l.push_back(x);
	for(auto c=l.begin();c!=l.end();++c){
		if((*c)%2==0)
			d1.push_back((*c));
		else
			d2.push_back((*c));
	}
	for(auto c: d1) cout<<c<<" ";	cout<<endl;
	for(auto c: d2) cout<<c<<" ";	cout<<endl;
}
void ex9_21(){
	list<string> l(1);
	string s;
	cout<<"Please input a string: ";
	auto ll = l.begin();
	while(cin>>s && s!="q"){
		ll = l.insert(ll, s);
		cout<<"Please input a string: ";
	}
	cout<<"This is what you want to say reversely: \n";
	for(list<string>::iterator c=l.begin();
		c!=l.end();++c)
		cout<<(*c)<<" ";
	cout<<endl;
}
