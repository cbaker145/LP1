#include "App.h"

int main(int argc, char* argv[])
{
    App aplicativo("files/diary.md");
    return aplicativo.run(argc, argv);
}
