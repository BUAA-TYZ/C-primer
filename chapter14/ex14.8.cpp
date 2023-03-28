//利用类的函数对象

#include<functional>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class If_else{
	public:
		int operator()(bool argu1, int argu2, int argu3)
		{if(argu1) return argu2;else return argu3;}
	private:

};
int main(){
	If_else if1;
	cout<<if1((5>3), 2, 1)<<endl;
	plus<int> intadd;
	cout<<intadd(1, 2)<<endl;
	greater<string> gr;
	vector<string> str{"i", "am", "the", "king"};
	stable_sort(str.begin(), str.end(), gr);
	for(auto c: str)
		cout<<c<<" ";
	cout<<endl;
}
