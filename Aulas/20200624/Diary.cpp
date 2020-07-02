#include "Diary.h"

Diary::Diary(const std::string& filename):filename(filename),messages_size(0),messages_capacity(10),messages(nullptr)
{
	messages=new Message[messages_capacity];
}

void Diary::add(const std::string& message)
{
    if(messages_size>=messages_capacity){
		Message* temp=new Message[messages_capacity+1];
		temp=messages;
		delete[]messages;
		messages=temp;
		delete[]temp;
	}
	messages[messages_size].content=message;
	messages_capacity++;
	messages_size++;
}

void Diary::write()
{
    // gravar as mensagens no disco
}
