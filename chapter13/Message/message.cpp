#include "message.h"

Message::Message(const Message& m):
	contents(m.contents), folders(m.folders){add_to_Folders(m);}
Message& Message::operator=(const Message& m){
	remove_from_Folders();
	contents = m.contents;
	folders = m.folders;
	add_to_Folders(m);
	return *this;
}
Message::~Message(){
	remove_from_Folders();
}
void Message::save(Folder& f){
	folders.insert(&f);
	f.addmsg(this);
}
void Message::remove(Folder& f){
	folders.erase(&f);
	f.remmsg(this);
}
void Message::add_to_Folders(const Message& m){
	for(auto f: m.folders)
		f->addmsg(this);
}
void Message::remove_from_Folders(){
	for(auto f: folders)
		f->remmsg(this);
}
void Message::move_Folders(Message* m){
   folders = std::move(m->folders);
   for(auto f: m->folders){
      f->remmsg(m);
	  f->addmsg(this);
   }
   m->folders.clear();   //important
}
Message::Message(Message&& m):
	contents(std::move(m.contents))
{
	move_Folders(&m);
}
Message& Message::operator=(Message&& rhs){
	if(&rhs != this){
		remove_from_Folders();
		this->contents = std::move(rhs.contents);
		move_Folders(&rhs);
	}
	return *this;
}
Folder::Folder(const Folder& f){
	add_messages(f);
	messages = f.messages;
}
Folder& Folder::operator=(const Folder& f){
	remove_messages();
	messages = f.messages;
	add_messages(f);
	return *this;
}
