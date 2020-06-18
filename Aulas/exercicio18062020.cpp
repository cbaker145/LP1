#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
int main(int argc,char *argv[]){
	using namespace std;
	if(argc==1){
		cout<<"Uso correto da aplicacao: "<<argv[0]<<" add <conteudo>\n";
		return -1;
	}
	if(strcmp("add",argv[1])==0){
		ofstream outfile("files/names.txt",ios::app);
		if(!outfile.is_open()){
			cerr<<"Arquivo inacessivel ou inexistente";
			return -1;
		}
		if(argc==2){
			cout<<"Informe a mensagem: ";
			string msg;
			getline(cin,msg);
			outfile<<msg<<endl;
			cout<<"Mensagem '"<<msg<<"' adicionada\n";
		}else{
			outfile<<argv[2]<<endl;
			cout<<"Mensagem '"<<argv[2]<<"' adicionada\n";
		}
		outfile.close();
		return 0;
	}else if(strcmp("list",argv[1])==0){
		ifstream infile("files/names.txt");
		string current_line;
		int line_number=0;
		if(!infile.is_open()){
			cerr<<"Arquivo inacessivel ou inexistente";
			return -1;
		}
		while(!infile.eof()){
			getline(infile,current_line);
			if(current_line.size()!=0){
				line_number++;
				cout<<line_number<<": "<<current_line<<endl;
			}
		}
		infile.close();
	}else{
		cout<<"Usos corretos da aplicacao:\n"<<argv[0]<<" add <conteudo>\n"<<argv[0]<<" list\n";
		return -1;
	}
}
