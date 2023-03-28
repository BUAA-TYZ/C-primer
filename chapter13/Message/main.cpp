//事实上， 每个folder也应该有名字， 这儿只能打印出folder中含的message
//这里用检验size的方式判断是否耦合

#include "message.h"
int main(){
	Message m1("tyz nb"), m2("hh"), m3("tyz weak");
	Folder f1, f2, f3, f4;
	m1.save(f1);m2.save(f1);f2.addmsg(&m1);f2.addmsg(&m3);
	cout << f1<<endl;
	cout << f2<<endl;
	cout<<m1.size()<<endl;
	m1.remove(f1);
	cout << f1 << endl;
	cout<<m1.size()<<endl;
}
