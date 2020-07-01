#ifndef W5N_MESSAGE_H
#define W5N_MESSAGE_H

#include "Date.h"
#include "Timing.h"

#include <string>
#include <iostream>

struct Message
{
    std::string content;
    Date date;
    Time time;
    
    void set_from_string(const std::string& line);
};
#endif
