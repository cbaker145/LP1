#include "App.h"

#include <iostream>
#include <string>
#include <sstream>

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
        if (argc == 2) {
            list_messages(get_format());
        } else {
            list_messages(argv[2]);
        }
    }else if (action == "search"){
    	if (argc == 2) {
            search();
        } else {
            search(argv[2]);
        }
	} else if(action=="interactive"){
		std::string line;
		char action;
		std::cout<<"Diary v04072020\n\nSelecione Uma Acao:\n\n1) Listar mensagens\n2) Adicionar nova mensagem\n3) Procurar por mensagem\n0) Finalizar\n";
		while(getline(std::cin,line)){
			if (line[0]=='1'){
				if(line.size()>2){
					list_messages(line.substr(2));
				}else{
					list_messages(get_format());
				}
//				std::cout<<line.size()<<std::endl;
//				std::cout<<line.substr(1)<<std::endl;
			}else if(line[0]=='2'){
				if(line.size()>2){
					add(line.substr(2));
				}else{
					add();
				}
			}else if(line[0]=='3'){
				if(line.size()>2){
					search(line.substr(2));
				}else{
					search();
				}		
			}else if(line[0]=='0'){
				return 0;
			}else{
				show_usage();
				return 0;
			}
			std::cout<<"Diary v04072020\n\nSelecione Uma Acao:\n\n1) Listar mensagens\n2) Adicionar nova mensagem\n3) Procurar por mensagem\n0) Finalizar\n";
		}
	}else {
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

void App::list_messages(std::string format)
{
	//std::cout<<format<<std::endl;
	std::stringstream output_build;
    for (size_t i = 0; i < diary.messages_size; i++) {
    	for (size_t j=0;j<format.size();j++){
    		if(format[j]=='%'){
    			if(format[j+1]=='d'){
    				j++;
    				output_build<<diary.messages[i].date.to_string();
				}else if(format[j+1]=='t'){
    				j++;
    				output_build<<diary.messages[i].time.to_string();
				}else if(format[j+1]=='m'){
    				j++;
    				output_build<<diary.messages[i].content;
				}else{
					output_build<<format[j];
				}
			}else{
				output_build<<format[j];
			}
		}
		std::cout<<output_build.str()<<std::endl;
		output_build.str("");
        //std::cout<<diary.messages[i].date.to_string()<<" "<<diary.messages[i].time.to_string()<<" "<<diary.messages[i].content<<std::endl;
    }
}

int App::show_usage()
{
	std::cout<<"Aplicacao usada incorretamente. Para mais informacoes, consulte o README."<<std::endl;
    return 1;
}

void App::search(){
	std::string query;
	std::cout<<"Enter text to search: "<<std::endl;
	std::getline(std::cin,query);
	search(query);
}

void App::search(const std::string query){
	std::vector<Message*> result = diary.search(query);
	if (result.size()>0){
		std::cout<<"Total Matches: "<<result.size()<<std::endl<<"Contents:"<<std::endl;
		for(size_t i=0;i<result.size();i++){
			std::cout<<result[i]->content<<std::endl;
		}
	}else{
		std::cout<<"No matches found"<<std::endl;
	}
}
