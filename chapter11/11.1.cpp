// count frequencies of words without punctuations && we ignore words ordinary or rare

#include<fstream>
#include<iostream>
#include<string>
#include<map>
#include<set>
using namespace std;
const string s="1.txt";
void seperat(string);
map<string, int> word_count;
set<string> exclude{"the", "of", "i", "you"
	, "and", "or", "are"};
int main(){
	fstream fi1(s);
	string word;
	if(fi1){
		string word;
		while(fi1>>word)
			seperat(word);
		for(auto w: word_count){
			if(w.second>1 && exclude.find(w.first)==exclude.end())
				cout<<w.first<<" occurs "<<w.second
				<<"times"<<endl;
		}
		cout<<endl;		
		}
	else
		cout<<"Opening file "<<s<<" fails.";
}
void seperat(string word){
	for(int i=0;i<word.size();++i){
		if(isspace(word[i]))
			word.erase(i, 1);
		if(ispunct(word[i])&&i!=word.size()-1){
			if(i==0)
				return;
			++word_count[word.substr(0, i)];
			seperat(word.substr(i+1));
			return;
		}
		else if(ispunct(word[i])){
			word.pop_back();
			++word_count[word];
			return;
		}
	}
	++word_count[word];return;
}
