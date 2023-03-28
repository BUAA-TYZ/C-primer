#ifndef STRBLOB_H
#define STRBLOB_H
#include<iostream>
#include<vector>
#include<string>
#include<memory>
#include<stdexcept>
#include<initializer_list>

using std::vector;
using std::string;
using std::shared_ptr;
using std::make_shared;
using size_type = vector<string>::size_type;
class StrBlob{
	public:
		StrBlob(): data(make_shared<vector<string>>()){}
		StrBlob(std::initializer_list<string> il):
		data(make_shared<vector<string>>(il)){}   //列表初始化vector<string>
		size_type size() const{return data->size();}
		bool empty() const{return data->empty();}
		void pop_back();
		void push_back(const string& t){data->push_back(t);}
		string& front();
		string& back() const;
		friend std::ostream& operator<<(std::ostream&, const StrBlob&);
	private:
		shared_ptr<vector<string>> data;
		void check(size_type i, const string& msg) const;
		//check wheather pass the limite
};

#endif
