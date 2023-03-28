#include<iostream>
#include<vector>
#include<list>
using namespace std;
void ex9_15(){
	vector<int> v1{1, 2, 3, 4},
	 v2{1, 2, 3, 5}, v3;
	 if(v1>v2)
	 	cout<<"v1 bigger\n";
	 else
	 	cout<<"v2 bigger\n";
	 list<int> l1{1, 2, 4, 5};
	 v3.assign(l1.begin(), l1.end());
	 if(v3>v1)
	 	cout<<"l1 bigger\n";
}
int main(){
	ex9_15();
}
