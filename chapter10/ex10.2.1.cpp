#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
#include<list>
using namespace std;
int main(){
	vector<int> v1{1, 2, 3, 7};
	cout<<accumulate(v1.cbegin(), v1.cend(), 0)<<endl;
	vector<double> v2{1, 2, 3, 65};
	cout<<accumulate(v2.cbegin(), v2.cend(), 0)<<endl;
	vector<string> v3{"hello", "world"};
	list<const char*> l1{"hello", "world"};
	cout<<equal(v3.cbegin(), v3.cend(), l1.cbegin())<<endl;
	v1.reserve(10);
	fill_n(v1.begin(), 10, 0);
	for(auto c:v1)cout<<c<<" ";
}
