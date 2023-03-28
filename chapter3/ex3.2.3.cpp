#include<iostream>
#include<string>
#include<cctype>
using namespace std;
void ex3_6_7(){
	string s;
	getline(cin, s);
	for(auto &c: s)
		c = 'X';
	cout<<s<<endl;
	for(char &c: s)
		c = 'X';
	cout<<s<<endl;
}
void ex3_10(){
	string s;
	getline(cin, s);
	for(auto c: s){
		if(!ispunct(c))	cout<<c;
	}	
	cout<<endl;
}
void ex3_11(){
	const string s="Keep out!";
	for(auto &c : s){
		//c = 'X';
		cout<<c;
	}
}
int main(){
	//ex3_6_7();
	//ex3_10();
	ex3_11();
	return 0;
}
