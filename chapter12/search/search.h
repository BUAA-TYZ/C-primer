#ifndef SEARCH_H
#define SEARCH_H
#include<iostream> 
#include<fstream>
#include<sstream>
#include<memory>
#include<set>
#include<vector>
#include<string>
#include<map>
using std::shared_ptr;
using std::vector;
using std::string;
using std::map;
using std::multiset;
using lineno = vector<string>::size_type;
class QueryResult;
class TextQuery{
	public:
		TextQuery(std::ifstream&);
		QueryResult query(string);
	private:
		shared_ptr<vector<string>> file;
		map<string, shared_ptr<multiset<lineno>>> wm;
};

class QueryResult{
	friend std::ostream& print(std::ostream&, const QueryResult&);
	public:
		 QueryResult(string l,
		 shared_ptr<vector<string>> f,
		 shared_ptr<multiset<lineno>> n):
		 s(l), file(f), lines(n){}
		
	private:
		string s;
		shared_ptr<vector<string>> file;
		shared_ptr<multiset<lineno>> lines;
};
#endif
