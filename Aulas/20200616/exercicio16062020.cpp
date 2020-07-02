#include<iostream>
#include<string>
#include<cstring>
int main(int argc,char *argv[]){
	using namespace std;
	if(argc==1||strcmp("add",argv[1])!=0){
		cout<<"Uso correto da aplicacao: "<<argv[0]<<" add <conteudo>\n";
		return -1;
	}else if(argc==2){
		cout<<"Informe a mensagem: ";
		string msg;
		getline(cin,msg);
		cout<<"Mensagem adicionada\n";
	}else{
		cout<<"Mensagem '"<<argv[2]<<"' registrada\n";
		return 0;
	}
}
