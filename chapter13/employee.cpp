#include<iostream>
#include<string>
using namespace std;

class Employee{
	public:
		static int i;
		//类中的static 不能在类内初始化
		Employee(const string& s=""): name(s) {id = i++;}
		friend ostream& operator<<(ostream& os, const Employee&);
	private:
		string name;
		int id;
};
int Employee::i = 1;
ostream& operator<<(ostream& os, const Employee& e){
	os<<"name: "<<e.name<<endl<<"Id: "<<e.id<<endl;
	return os;
}
int main(){
	Employee client1("tianyuzhe");
	cout<<client1;
}
