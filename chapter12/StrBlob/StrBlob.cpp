#include "StrBlob.h"

void StrBlob::check(size_type i, const string& msg) const{
	if(i>=data->size())
	//size_type must be positive
		throw std::out_of_range(msg);
}
void StrBlob::pop_back(){
	check(0, "pop on empty StrBlob");
	data->pop_back();
}
string& StrBlob::front(){
	check(0, "front on empty StrBlob");
	return data->front();
}
string& StrBlob::back() const{
	check(0, "back on empty StrBlob");
	return data->back();
};
std::ostream& operator<<(std::ostream& os, const StrBlob& str){
	for(auto c: *(str.data))
		os<<c<<" ";
	os<<std::endl;
	return os;
}
