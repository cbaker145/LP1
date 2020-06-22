#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
#include<ctime>

using namespace std;

string format_current_date(const string &format) {
	time_t current_time = time(nullptr);
	char result[1024];
	strftime(result, sizeof(result), format.c_str(), localtime(&current_time));
	return string(result);
}

string get_current_date(){ 
	return format_current_date("%d/%m/%Y");
}

string get_current_time(){
	return format_current_date("%H:%M:%S");
}

//retorna 0 se o arquivo contem uma linha com a data atual
//na formatacao correta, e -1 em caso contrario
int file_updated(){
	ifstream infile("messages.md");
	string current_date="# "+get_current_date();
	string current_line;
	if(!infile.is_open()){
		cerr<<"Arquivo inacessivel ou inexistente\n";
		return -1;
	}
	while(!infile.eof()){
		getline(infile,current_line);
		if(current_line.compare(current_date)==0){
			//cout<<"arquivo atualizado\n";
			infile.close();
			return 0;
		}
	}
	//cout<<"arquivo desatualizado\n";
	infile.close();
	return -1;
}

//lista as mensagens no arquivo, ignorando todas as que estiverem 
//fora da formataçao correta. retorna -1 se o arquivo estiver 
//inacessivel e 0 se a operaçao for completada com sucesso
int list_contents(){
	ifstream infile("messages.md");
	string current_line;
	if(!infile.is_open()){
		cerr<<"Arquivo inacessivel ou inexistente\n";
		return -1;
	}
	while(!infile.eof()){
		getline(infile,current_line);
		if(current_line.size()!=0&&current_line[0]=='-'){
			cout<<current_line<<endl;
		}
	}
	infile.close();
	return 0;
}

//adiciona uma mensagem no arquivo. retorna -1 se o arquivo 
//estiver inacessivel e 0 se a operaçao for completada com sucesso
int add_content(int argc, char *argv[]){
	ofstream outfile("messages.md",ios::app);
	if(!outfile.is_open()){
		cerr<<"Arquivo inacessivel ou inexistente\n";
		return -1;
	}
	if(argc==2){
		cout<<"Informe a mensagem: ";
		string msg;
		getline(cin,msg);
		if (file_updated()!=0){
			outfile<<"# "<<get_current_date()<<endl;
		}
		outfile<<"- "<<get_current_time()<<" "<<msg<<endl;
		cout<<"Mensagem '"<<msg<<"' adicionada\n";
	}else{
		if (file_updated()!=0){
			outfile<<"# "<<get_current_date()<<endl;
		}
		outfile<<"- "<<get_current_time()<<" "<<argv[2]<<endl;
		cout<<"Mensagem '"<<argv[2]<<"' adicionada\n";
	}
	outfile.close();
	return 0;
}


int main(int argc,char *argv[]){
	if(argc==1){
		cout<<"Uso correto da aplicacao: "<<argv[0]<<" add <conteudo>\n";
		return -1;
	}
	if(strcmp("add",argv[1])==0){
		if(add_content(argc, argv)!=0){
			cerr<<"Erro ao adicionar informacao\n";
			return -1;
		}
		return 0;
	}else if(strcmp("list",argv[1])==0){
		if (list_contents()!=0){
			cerr<<"Erro na leitura do arquivo\n";
			return -1;
		}
		return 0;
	}else{
		cout<<"Usos corretos da aplicacao:\n"<<argv[0]<<" add <conteudo>\n"<<argv[0]<<" list\n";
		return -1;
	}
}
