#include "Message.h"

#include <sstream>

void Message::set_from_string(const std::string& line)
{
	content=line.substr(11);
    //std::cout<<content<<std::endl;
}
