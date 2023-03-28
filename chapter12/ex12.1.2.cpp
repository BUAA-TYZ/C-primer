#include<iostream>
#include<vector>
#include<memory>
using std::vector;
using std::shared_ptr;
using std::cout;
using std::endl;
vector<int>* input1(){
	int m;
	vector<int>* res(new vector<int>);
	while(std::cin>>m){
		res->push_back(m);
	}
	return res;
}
shared_ptr<vector<int> > input2(){
	int m;
	shared_ptr<vector<int> > res=std::make_shared<vector<int> >();  
	//auto = make_shared...  easier
	while(std::cin>>m){
		res->push_back(m);
	}
	return res;
}
void ouput1(vector<int>* res){
	for(int i=0;i<res->size();++i){
		cout<<(*res)[i]<<" ";
	}
	cout<<endl;
	delete res;
}
void ouput2(shared_ptr<vector<int> > res){
	for(int i=0;i<res->size();++i){
		cout<<(*res)[i]<<" ";
	}
	cout<<endl;    //delete automatically
}
int main(){
	ouput2(input2());
}
