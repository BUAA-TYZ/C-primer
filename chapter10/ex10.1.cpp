#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
using namespace std;
void ex10_1();void ex10_2();
int main(){
	//ex10_1();
	ex10_2();
}
void ex10_1(){
	vector<int> v1;
	for(int i=1;i<=100;i+=2)
		v1.push_back(i);
	cout<<"Find: ";
	int val;
	cin>>val;
	auto res = find(v1.cbegin(), v1.cend(), val);
	cout<<val<<" "<<(res!=v1.cend()?"presents.":"doesn't present.")<<endl;
}
void ex10_2(){
	list<string> l1(4, "hello");
	cout<<count(l1.cbegin(), l1.cend(), "hello")<<endl;
}
