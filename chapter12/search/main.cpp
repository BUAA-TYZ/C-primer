#include "search.h"
using namespace std;
const string s ="2.txt";
int main(){
	ifstream fil(s);
	TextQuery tq(fil);
	while(true){
 		cout<<"search the word: (q to quit)\n";
 		string mot;
 		if(!(cin>>mot) || mot=="q") break;
 		print(cout, tq.query(mot))<<endl;
 	}
}
