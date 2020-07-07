#include "Utils.h"

std::string format_current_date(const std::string &format) {
	std::time_t current_time = std::time(nullptr);
	char result[1024];
	std::strftime(result, sizeof(result), format.c_str(), std::localtime(&current_time));
	return std::string(result);
}

std::string get_current_date(){
	return format_current_date("%d/%m/%Y");
}

std::string get_current_time(){
	return format_current_date("%H:%M:%S");
}

std::string get_path(){
	std::ifstream configs("diary.config");
	std::string current_line;
	while(!configs.eof()){
		getline(configs,current_line);
		if(current_line[0]=='p'){
			//std::cout<<current_line.substr(5)<<std::endl;
			break;
		}
		//std::cout<<current_line.size()<<" "<<current_line<<std::endl;
	}
	configs.close();
	return current_line.substr(5);
}

std::string get_format(){
	std::ifstream configs("diary.config");
	std::string current_line;
	while(!configs.eof()){
		getline(configs,current_line);
		if(current_line[0]=='d'){
			//std::cout<<current_line.substr(15)<<std::endl;
			break;
		}
		//std::cout<<current_line.size()<<" "<<current_line<<std::endl;
	}
	configs.close();
	return current_line.substr(15);
}

bool config_file_ready(){
	std::ifstream configs("diary.config");
	if(!configs.is_open()){
		std::cout<<"Arquivo de configuracoes inexistente ou inacessivel. Criando um arquivo com configuracoes base..."<<std::endl;
		std::ofstream create_file("diary.config");
		if(!create_file.is_open()){
			std::cout<<"O arquivo de configuracoes nao pode ser criado"<<std::endl;
			return false;
		}else{
			create_file<<"path=diary.md"<<std::endl<<"default_format=%d %t: %m";
			std::cout<<"Arquivo de configuracoes criado com sucesso."<<std::endl;
		}
	}
	configs.close();
	return true;
}

bool diary_file_ready(){
	std::ifstream check(get_path());
	if(!check.is_open()){
		std::cout<<"Diario inexistente ou inacessivel. Tentando criar um arquivo vazio..."<<std::endl;
		std::ofstream create_file(get_path());
		if(!create_file.is_open()){
			std::cout<<"O arquivo de configuracoes nao pode ser criado"<<std::endl;
			return false;
		}else{
			std::cout<<"Arquivo de configuracoes criado com sucesso."<<std::endl;
		}
	}
	check.close();
	return true;
}
