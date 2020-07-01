#include "App.h"

#include <iostream>
#include <string>

App::App(const std::string& filename) : diary(filename)
{
}

int App::run(int argc, char* argv[])
{
    if (argc == 1) {
        return show_usage();
    }

    std::string action = argv[1];

    if (action == "add") {
        if (argc == 2) {
            add();
        } else {
            add(argv[2]);
        }
    } else if (action == "list") {
        list_messages();
    }else if (action == "search"){
    	if (argc == 2) {
            search();
        } else {
            search(argv[2]);
        }
	} else {
        return show_usage();
    }

    return 0;
}

void App::add()
{
    std::string message;
    std::cout << "Enter your message:" << std::endl;
    std::getline(std::cin, message);

    add(message);
}

void App::add(const std::string message)
{
    diary.add(message);
    diary.write();
}

void App::list_messages()
{
    for (size_t i = 0; i < diary.messages_size; ++i) {
        const Message& message = diary.messages[i];
        std::cout << "-" << message.content << std::endl;
    }
}

int App::show_usage()
{
	std::cout<<"Aplicacao usada incorretamente."<<std::endl;
    return 1;
}

void App::search(){
	std::string query;
	std::cout<<"Enter text to search: "<<std::endl;
	std::getline(std::cin,query);
	search(query);
}

void App::search(const std::string query){
	Message* result = diary.search(query);
	if(result!=nullptr){
		std::cout<<"Match found: "<<std::endl<<result->date.to_string()+" "+result->time.to_string()+" "+result->content<<std::endl;
	}else{
		std::cout<<"No result found..."<<std::endl;
	}
}
