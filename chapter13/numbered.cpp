#include<iostream>
using namespace std;

int i = 1;
class numbered{
	private:
		int mysn;
	public:
		numbered(): mysn(i){++i;}
		//numbered(const numbered& ) = default;
		numbered(const numbered& s){mysn = i++;}
		//numbered operator=(const numbered& s){mysn = ++i; return *this;}
		friend void f(const numbered&);
};
void f(const numbered& s) {cout<<s.mysn<<endl;}
int main(){
	numbered a, b=a;
	f(a);f(b);
	//小心隐式调用拷贝构造函数， f(numbered s)
}
