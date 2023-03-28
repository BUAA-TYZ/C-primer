#ifndef SCREEN_H
#define SCREEN_H
#include<string>
#include<vector>
#include<iostream>
using std::string;
using std::vector;
class Screen{
	public: 
		typedef string::size_type pos;
		friend class Window;
		Screen() = default;
		Screen(pos ht, pos wi, char c=' '): height(ht), width(wi), //act as two functions
		contents(ht*wi, c){}
		void display(std::ostream& os) const{
			for(auto c=contents.begin();
				c!=contents.end();++c){
				os<<(*c);if((c-contents.begin()+1)%width==0) os<<std::endl;
				}
		}
		Screen &move(pos, pos);
		Screen &set(char);
		Screen &set(pos, pos, char);
		char get();
		char get(pos, pos);
	private:
		pos cursor=0;
		pos height=0, width=0;
		string contents;
};
class Window{
	public:
		using screen_idx = vector<Screen>::size_type;
		void display(std::ostream&);
		void clear(screen_idx);
	private:
		vector<Screen> win{Screen(4, 3, 'a'),
		Screen(4, 3, 'b'), Screen(4, 3, 'c')} ;
};
#endif
