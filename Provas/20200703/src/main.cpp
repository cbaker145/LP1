#include "App.h"
#include "Utils.h"

int main(int argc, char* argv[])
{
	if(!config_file_ready()){
		return 1;
	}if(!diary_file_ready()){
		return 1;
	}
    App aplicativo(get_path());
    return aplicativo.run(argc, argv);
}
