#include "search.h"

TextQuery::TextQuery(std::ifstream& fil): file(new vector<string>){
	string text;
	while(getline(fil, text)){
		file->push_back(text);
		int n = file->size()-1;
		std::istringstream line(text);
		string word;
		while(line>>word){
			shared_ptr<multiset<lineno>>& lines = wm[word];  //lines is a shared_ptr
			//&reference for using the same pointer when meetting a word twice
			if(!lines) 
				lines.reset(new multiset<lineno>);
			lines->insert(n);
		}
	}
}
QueryResult TextQuery::query(string s){
	static shared_ptr<multiset<lineno>> nodata(new multiset<lineno>);
	auto loc = wm.find(s);
	if(loc==wm.end())
		return QueryResult(s, file, nodata);
	else
		return QueryResult(s, file, loc->second);
}
std::ostream& print(std::ostream& os, const QueryResult& res){
	int n=res.lines->size();
	os<<res.s<<" occurs "<<n<<" times:\n";
	std::set<lineno> clear_repeat(res.lines->begin(), res.lines->end());
	//genius
	for(lineno num: clear_repeat){
		//if the same row, ouput one time
			os<<"\t(line "<<num+1<<"): "<<*(res.file->begin()+num)<<std::endl;
	}
	return os;
}

