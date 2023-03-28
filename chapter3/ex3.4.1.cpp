#include<iostream>
#include<string>
#include<vector>
#include<cctype>
using namespace std;
int main(){
	vector<int> entier{0, 1, 2, 3, 4};
	for(auto it=entier.begin();
	it!=entier.end();it++){
		(*it)*=2;cout<<*it<<" ";
	}
}
