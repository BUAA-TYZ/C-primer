#include<iostream>
#include<string>
#include<cctype>
using namespace std;
int main(){
	string s;
	getline(cin, s);
	decltype(s.size()) num_punct = 0;  //decltype 借助表达式推断类型 string::size_type
	for(auto c: s)					   //auto自动推断c, 此处为char
		if(ispunct(c))
			++num_punct;
	cout<<"The size of this string: "<<s.size();
	cout<<"\nThe number of punctuations: "<<num_punct<<endl;
}
