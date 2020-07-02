#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
int main(int argc,char *argv[]){
	using namespace std;
	if(argc==1||strcmp("add",argv[1])!=0){
		cout<<"Uso correto da aplicacao: "<<argv[0]<<" add <conteudo>\n";
		return -1;
	}else{
		ofstream outfile("files/names.txt",ios::app);
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
	}
}
