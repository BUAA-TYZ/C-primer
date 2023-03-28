#include<iostream>
#include"Screen.h"
using namespace std;
int main(){
	Screen sc1{5, 5, 'X'};
	sc1.display(cout);cout<<endl;
	sc1.move(4, 0).set('#').display(cout);cout<<endl;
	cout<<sc1.get(4, 0)<<endl;
	sc1.set(3, 2, '&').display(cout);
	Window win1;
	win1.display(cout);
	win1.clear(1);
	win1.display(cout);
}
