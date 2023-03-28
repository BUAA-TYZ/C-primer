#include "StrBlob.h"
int main(){
	StrBlob p1={"a", "an", "apple"};
	StrBlob p2(p1);
	p2.push_back("hello");
	std::cout<<p1.back()<<std::endl;
}
