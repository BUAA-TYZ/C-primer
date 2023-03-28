#include"Screen.h"
Screen & Screen::move(pos x, pos y){
	cursor=x*width+y;
	return (*this);
}
Screen & Screen::set(char c){
	contents[cursor] = c;
	return (*this);
}
Screen & Screen::set(pos x, pos y, char c){
	contents[x*width+y] = c;
	return (*this);
}
char Screen::get(){
	return contents[cursor];
}
char Screen::get(pos x, pos y){
	return contents[x*width+y];
}
void Window::clear(screen_idx i){
	string &s=win[i].contents;  //need friend
	s=string(s.size(), ' ');
}
void Window::display(std::ostream& os){
	for(auto c: win)
		c.display(os);
}
