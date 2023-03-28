#ifndef MESSAGE_H
#define MESSAGE_H

#include<iostream>
#include<string>
#include<set>
using namespace std;

class Folder;
class Message{
	friend class Folder;
	public:
		Message(const string &str=" "):
			contents(str){}
		Message(const Message& );
		Message& operator=(const Message&);
		Message(Message&&);
		Message& operator=(Message&&);
		~Message();
		void save(Folder&);
		void remove(Folder&);
		int size(){return folders.size();}
		//size纯粹为了看看是否耦合
		const string& content_() const{return contents;}
		void move_Folders(Message*);
	private:
		string contents;
		set<Folder*> folders;
		//指向所有带此消息的目录
		//拷贝构造时要在所有带消息的目录中加入一条消息，与save一样
		//赋值析构时要从所有目录中删除一条消息，与remove一样
		void add_to_Folders(const Message& );
		void remove_from_Folders();
};
class Folder{
	public:
		Folder() = default;
		Folder (const Folder& );
		Folder& operator=(const Folder& );
		~Folder(){remove_messages();}
	 	void addmsg(Message* m){messages.insert(m);m->folders.insert(this);}
	 	void remmsg(Message* m){messages.erase(m);m->folders.erase(this);}
	 	friend ostream& operator<<(ostream& os, const Folder& f){
			for(auto m: f.messages)
				os<<m->content_()<<" ";
			return os;
		}
	private:
		set<Message*> messages;
		void add_messages(const Folder& f){
		//向f目录中所有消息的目录集合中加入一个目录
			for(auto m: f.messages)
				m->folders.insert(this);
		}
		void remove_messages(){
		//将所有含本目录的消息的目录列表删除本目录
			for(auto m: messages)
				m->folders.erase(this);
		}
		
};
#endif
