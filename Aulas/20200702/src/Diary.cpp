#include "Diary.h"
#include "Utils.h"

void Diary::adjust_size(){
	Message* temp=new Message[messages_capacity*2];
	for(int i=0;i<messages_size;i++){
		temp[i]=messages[i];
	}
	delete[]messages;
	messages=temp;
	messages_capacity=messages_capacity*2;
}

Diary::Diary(const std::string& name) : filename(name), messages(nullptr), messages_size(0), messages_capacity(10)
{
    messages = new Message[messages_capacity];
	std::ifstream infile(filename);
	if (!infile.is_open()){
		//std::cout<<"O arquivo esta inacessivel ou nao existe."<<std::endl;
		return;
	}
	std::string current_line;
	std::string current_date;
    while(!infile.eof()){
    	if(messages_size>=messages_capacity)
		{
			adjust_size();
			continue;
		}
    	getline(infile,current_line);
    	if(current_line[0]=='#')
		{
    		current_date=current_line;
    		//std::cout<<current_date<<endl;
    		continue;
		}
		else if(current_line[0]=='-')
		{
			messages[messages_size].date.set_from_string(current_date);
	    	messages[messages_size].time.set_from_string(current_line);
	    	//std::cout<<messages[messages_size].date.to_string()<<" "<<messages[messages_size].time.to_string()<<messages[messages_size].content<<std::endl;
	    	messages[messages_size].set_from_string(current_line);
	    	//std::cout<<current_line<<std::endl;
		}
    	//std::cout<<messages[messages_size].date.day<<messages[messages_size].date.month<<messages[messages_size].date.year<<std::endl;
    	messages_size++;
	}
	infile.close();
}

Diary::~Diary()
{
    delete[] messages;
}

void Diary::add(const std::string& message)
{
    if (messages_size >= messages_capacity) {
        adjust_size();
    }
    Message m;
    m.date.set_from_string(get_current_date());
    //std::cout<<m.date.year<<m.date.month<<m.date.day<<std::endl;
    m.time.set_from_string(get_current_time());
    m.content = message;

    messages[messages_size] = m;
    //std::cout<<messages[messages_size].date.to_string()<<messages[messages_size].time.to_string()<<messages[messages_size].content<<std::endl;
    messages_size++;
}

std::vector<Message*> Diary::search(const std::string query){
	std::vector<Message*> matches;
	for(size_t i=0;i<messages_size;i++){
		if(&messages[i]!=nullptr && messages[i].content.find(query)!=std::string::npos){
			matches.push_back(&messages[i]);
		}
		//std::cout<<matches.size()<<std::endl;
	}
	return matches;
}

bool Diary::file_updated(){
	Date current_date;
	current_date.set_from_string(get_current_date());
	for(size_t i=0;i<messages_size;i++){
		if (current_date.to_string().compare(messages[i].date.to_string())==0){
			//std::cout<<"file updated."<<std::endl;
			//std::cout<<current_date.to_string()<<std::endl;
			//std::cout<<messages[i].date.to_string()<<std::endl;
			return true;
		}
	}
	//std::cout<<"file outdated."<<std::endl;
	//std::cout<<current_date.to_string()<<std::endl;
	return false;
}

void Diary::write()
{
	std::ofstream outfile(filename,std::ios::app);
	if(!file_updated()||messages_size==1){
		outfile<<"# "<<messages[messages_size-1].date.to_string()<<std::endl;
	}
	outfile<<"- "<<messages[messages_size-1].time.to_string()<<" "<<messages[messages_size-1].content<<std::endl;
	outfile.close();
}
