#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using std::vector;
using std::endl;
class Foo{
	public:
		Foo(vector<int> v1): data(v1){}
		Foo(const Foo& f):data(f.data){}
		Foo(Foo&& f): data(std::move(f.data)){}
		Foo sorted() const &;
		Foo sorted() &&;
		vector<int> dt(){return data;}
	private:
		vector<int> data;
};

Foo Foo::sorted() const &{
	//cannot directly sort 'data' cause it's a left value
	Foo temp(*this);
	std::sort(temp.data.begin(), temp.data.end());
	return temp;
}
Foo Foo::sorted() &&{
	//we can safely sort it cause no one will use it
	std::sort(data.begin(), data.end(), std::greater<int>());
	return *this;
}

int main(){
	Foo f1(vector<int>({5, 4, 3, 6})); 
	//f1.sorted() return a rvalue
	for(auto c: f1.sorted().dt())
		std::cout<<c<<" "<<endl;
	for(auto c: f1.dt())
		std::cout<<c<<" "<<endl;
	//The rvalue which std::move(f1) returns chooses the rvalue version sorted() 
	for(auto c: std::move(f1).sorted().dt())
		std::cout<<c<<" "<<endl;
}
