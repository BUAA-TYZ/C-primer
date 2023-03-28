/*
	This programme enable users to sort the arcticle by order.
*/

#include<iostream>
#include<fstream>
#include<cctype>
#include<algorithm>
#include<numeric>
#include<vector>
#include<string>
#include<list>
using namespace std;
string s="1.txt";
vector<string> v;
void seperat(string);
void sortbyval(vector<string>&);
void sortbylen(vector<string>&);
int main(){
	fstream fi1(s);
	if(fi1){
		string word;
		while(fi1>>word)
			seperat(word);
		//sortbyval(v);
		sortbylen(v);
		for(int i=0;i<v.size();++i){
			if(i%5==0)cout<<endl;
			cout<<v[i]<<" ";
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
			v.push_back(word.substr(0, i));
			seperat(word.substr(i+1));
			return;
		}
		else if(ispunct(word[i])){
			word.pop_back();
			v.push_back(word);
			return;
		}
	}
	v.push_back(word);return;
}
void sortbyval(vector<string>& v){
	sort(v.begin(), v.end());  //sort
	v.erase(unique(v.begin(), v.end()), v.end()); //erase repeatd elements
}
void sortbylen(vector<string>& v){
	stable_sort(v.begin(), v.end(),[](const string& a, const string& b){return a.size()<b.size();});
	v.erase(unique(v.begin(), v.end()), v.end());
}
